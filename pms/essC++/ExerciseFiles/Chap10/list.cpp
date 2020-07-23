// list.cpp by Bill Weinman <http://bw.org/>
#include <iostream>
#include <list>
using namespace std;


// A list  is a sequence  container like  a vector, but  optimized for
// speedy insert and delete operations. And it does not support random
// access.  So lack of random access  support means to support for the
// subscript operator eg vi[5].

// The advantage of  this is the lists are really,  really fast. Doing
// these inserts and these deletes, even with all of the looping, is a
// lot faster than it is with something like a vector.  So if you have
// really, really  big data structures,  or data structures  that have
// really,  really  big  elements,  then   a  list  can  sometimes  be
// efficient.


int main( int argc, char ** argv ) {
    list<int> li1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << "size: " << li1.size() << endl;
    cout << "front: " << li1.front() << endl;
    cout << "back: " << li1.back() << endl << endl;
    
    cout << "push_back 47: " << endl;
    li1.push_back(47);
    cout << "size: " << li1.size() << endl;
    cout << "back() " << li1.back() << endl;
    
    // range-based for loop
    cout << "range-based for loop: " << endl;
    for(int v : li1) {
        cout << v << " ";
    }
    cout << endl << endl;
    
    // need an iterator to insert and erase
    list<int>::iterator it1 = li1.begin();
    while((*++it1 != 5) && (it1 != li1.end()));
    if (it1 != li1.end()) {
        cout << "insert 112 before 5:" << endl;
        li1.insert(it1, 112);
    }
    for(int v : li1) cout << v << " ";
    cout << endl;
    
    while((*++it1 != 7) && (it1 != li1.end()));
    if (it1 != li1.end()) {
        cout << "erase 7:" << endl;
        li1.erase(it1);
    }
    
    for(int v : li1) cout << v << " ";
    cout << endl;
    
    cout << "erase 112 to 8:" << endl;
    list<int>::iterator it2 = it1 = li1.begin();
    while( ( *++it1 != 112) && (it1 != li1.end() ) );
    while( ( *++it2 != 8) && (it2 != li1.end() ) );
    if (it1 != li1.end() && it2 != li1.end()) {
        cout << *it1 << " " << *it2 << endl;
	// erases between it1 and it2
        li1.erase(it1, it2);
        for(int v : li1)  cout << v << " ";
        cout << endl << endl;
    }
    cout << endl;
    
    return 0;
}
