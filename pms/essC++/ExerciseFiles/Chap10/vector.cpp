// A vector is a sequence container that supports random access to its
// elements.  You can  think of it like an object-oriented  ray with a
// bunch of extra cool features.
//
// Use it whenever you would otherwise use a C array but could benefit
// from some capabilities that  vector provides in its object-oriented
// interface.
//
// The vector template is defined in the vector header file <vector>
//
// vector.cpp by Bill Weinman <http://bw.org/>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main( int argc, char ** argv ) {
  //cout << "vector from initializer list: " << endl;
    // initalising a vector:
    //
    // declare it with the vector template class
    //
    // <int>  is  the  template  parameter list,  thus  it  creates  a
    // container of elements of type int.
    //
    // intialisation via initialiser  list is new in c++11,  but it is
    // highly recommended that you use it, much simpler than old way.
    //vector<int> vi1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    
    // cout << "size: " << vi1.size() << endl;
    // cout << "front: " << vi1.front() << endl;
    // cout << "back: " << vi1.back() << endl;
    
    // // iterator
    // //
    // // vector's like most containers have itterators.  The iterrator
    // // type is a class itself.
    // //
    // // mostly used like a pointer.
    // //
    // vector<int>::iterator itbegin = vi1.begin();
    // vector<int>::iterator itend = vi1.end();
    // // OR
    // // as below with the auto operator provided in c++11
    // //auto itbegin = vi1.begin();
    // //auto itend = vi1.end();
    // for (auto it = itbegin; it < itend; ++it) {
    //     cout << *it << ' ';
    // }
    // cout << endl;

    // // You  dereference a  vector  the  same as  you  would an  array.
    // // Normal method for an array or using the at() method.
    // //
    // cout << "element at 5: " << vi1[5] << endl;
    // cout << "element at 5: " << vi1.at(5) << endl;

    // // range-based for loop is a c++11 feature.
    // cout << "range-based for loop:" << endl;
    // for (int & i : vi1) {
    //     cout << i << ' ';
    // }
    // cout << endl;

    // cout << "insert 42 at begin + 5: " << endl;
    // vi1.insert(vi1.begin() + 5, 42);
    // cout << "size: " << vi1.size() << endl;
    // cout << "vi1[5]: " << vi1[5] << endl;
    
    // cout << "erase at begin + 5: " << endl;
    // vi1.erase(vi1.begin() + 5);
    // cout << "size: " << vi1.size() << endl;
    // cout << "vi1[5]: " << vi1[5] << endl;
    
    // cout << "push_back 47: " << endl;
    // vi1.push_back(47);
    // cout << "size: " << vi1.size() << endl;
    // cout << "vi1.back() " << vi1.back() << endl;
    
    // cout << "range-based for loop: " << endl;
    // for(int & v : vi1) {
    //     cout << v << ' ';
    // }
    // cout << endl << endl;
    
    // // from C-array
    // //
    // // This is how you would do it before c++11
    // const static size_t size = 10;
    // int ia[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    // cout << "vector from C-array: " << endl;
    // vector<int> vi2(ia, ia + size);
    // for( int & i : vi2 ) {
    //     cout << i << ' ';
    // }
    // cout << endl << endl;
    
    // vector of strings
    cout << "vector of strings:" << endl;
    vector<string> vs = { "one", "two", "three", "four", "five" };
    for(string & v : vs) {
      cout << v << endl;
    }
    
    return 0;
}
