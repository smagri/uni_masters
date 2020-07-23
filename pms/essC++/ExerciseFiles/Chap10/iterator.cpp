// iterator.cpp by Bill Weinman <http://bw.org/>

// the  STL, iterators  are a  generalization of  pointers that  allow
// access to STL containers with a consistent interface.

// There are  five types  of itterators, some  classes do  not support
// all, or any, of the the types.  The documentation or each container
// type will tell you which types of iterators it supports.


#include <iostream>
#include <vector>
using namespace std;

int main( int argc, char ** argv ) {
    vector<int> vi1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int>::iterator it;   // vector iterator
    
    // input iterator
    //
    // vi1.end() points beyond the end of the container.
    //
    // iterator/it here is a pointer to the container elements, so *it
    // gets you the current contents of the pointer.
    cout << "input iterator:" << endl;
    for(it = vi1.begin(); it < vi1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // save start and end points of the container.  Container here is
    // 'vector', vectors are like arrays but with extra benifits.
    //
    // Once you start inserting and deleting objects from a container
    // your saved iterators are no longer going to be valid, so you
    // need to be aware of that.
    vector<int>::iterator start = vi1.begin();
    vector<int>::iterator end = vi1.end();
    
    // output iterator???
    //
    // Allows writing to the object, that is writing to the container
    // the iterator is pointing too.
    cout << "output iterator:" << endl;
    for(it = start; it < end; it++) {
        cout << ++(*it) << " ";
        --(*it);
    }
    cout << endl;
    
    // forward iterator allows re-iteration of same set with same results
    //
    // Allows  reading  and  writing  to  the  iterator  object,  with
    // multi-pass gaurantee, that is rereading the object will produce
    // the same result.
    //
    cout << "forward iterator:" << endl;
    for(it = start; it < end; ++it) {
        cout << *it << " ";
    }
    for(it = start; it < end; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    
    // bidirectional iterator -- iterate forward or backward
    // allows it-- with multipass gaurantee.
    //
    // Again, remember end points past the end of the container, so
    // need to start with it=end-1.
    //
    cout << "bidirectional iterator:" << endl;
    for(it = end - 1; it >= start; --it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // random access iterator
    // allows += and -= access
    // also has multi-pass gaurantee.
    cout << "random access iterator:" << endl;
    it = start + 7;
    cout << *it << " ";
    it -= 3;
    cout << *it << " ";
    it += 4;
    cout << *it << " ";
    cout << vi1[5] << " ";
    cout << endl;
    
    return 0;
}
