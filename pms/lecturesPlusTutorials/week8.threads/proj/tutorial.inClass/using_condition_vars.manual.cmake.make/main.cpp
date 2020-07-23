#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
#include <string>
#include <vector>
#include <random>


class NamedVector {

public:
    NamedVector(std::string name);
    void addNumber(double number);
    void pruneValues(double min, double max);
    void pruneLength(unsigned max_size);

private:
    void printElements();

    std::string name_;
    std::vector<double> elements_;

    // Synchronisation
    std::mutex mutex_;
    std::condition_variable cv_;
    bool values_are_checked_, size_is_checked_;
};

NamedVector::NamedVector(std::string name):
    name_(name), values_are_checked_(false), size_is_checked_(false)
{
}

void NamedVector::addNumber(double number) {
    std::unique_lock<std::mutex> lock(mutex_);
    elements_.push_back(number);
    values_are_checked_ = false;
    size_is_checked_ = false;
    cv_.notify_all();
    std::cout << "Added " << number << " to " << name_ << std::endl;
    printElements();
}

void NamedVector::pruneValues(double min, double max) {
    std::unique_lock<std::mutex> lock(mutex_);
    while (values_are_checked_) {
        cv_.wait(lock);
    }
    std::cout << "Checking all values of " << name_ << std::endl;
    std::vector<double>::iterator it = elements_.begin();
    while (it != elements_.end()) {
        if (*it<min || *it>max) {
            std::cout << "Removing " << *it << " from " << name_ << std::endl;
            elements_.erase(it);
        } else {
            it++;
        }
    }
    values_are_checked_ = true;
    cv_.notify_all();
    std::cout << "Checked all values of " << name_ << std::endl;
    printElements();
}

void NamedVector::pruneLength(unsigned max_size) {
    std::unique_lock<std::mutex> lock(mutex_);
    while (size_is_checked_ || !values_are_checked_) {
        cv_.wait(lock);
    }
    std::cout << "Checking length of " << name_ << std::endl;
    if (elements_.size() > max_size) {
        elements_.erase(elements_.begin());
        std::cout << "Pruned length of " << name_ << std::endl;
    } else {
        std::cout << "Length of " << name_ <<  " is ok" << std::endl;
    }
    size_is_checked_ = true;
    printElements();
}

void NamedVector::printElements()
{
    for (auto element : elements_) {
        std::cout << element << " ";
    }
    std::cout << std::endl << std::endl;
}

NamedVector named_vector("rad vector");


void addRandomThread() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::uniform_real_distribution<double> distribution(0,100);
    while (true) {
        named_vector.addNumber(distribution(generator));
        std::this_thread::sleep_for (std::chrono::milliseconds(10));
    }
}

void pruneValuesThread() {
    while (true) {
        named_vector.pruneValues(20,80);
    }
}

void pruneLengthThread() {
    while (true) {
        named_vector.pruneLength(20);
    }
}

int main ()
{
    // Create the threads
    std::thread add_random_thread(addRandomThread);
    std::thread prune_values_thread(pruneValuesThread);
    std::thread prune_length_thread(pruneLengthThread);

    // Wait for the threads to finish (they wont)
    add_random_thread.join();
    prune_values_thread.join();
    prune_length_thread.join();

    return 0;
}



