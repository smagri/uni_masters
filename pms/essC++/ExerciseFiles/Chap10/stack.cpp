// stack.cpp by Bill Weinman <http://bw.org/>
#include <iostream>
#include <stack>
#include <string>
#include <list>
using namespace std;


// The STL provides three distinct  types of queues.  The stack object
// provides a last-in first-out or LIFO  queue, where you push and pop
// items from the same side of the queue, and items are removed in the
// reverse  order from  which they  were inserted.
//
// The  queue object  provides a  first-in, first-out  or FIFO  queue,
// where you push and pop from  opposite sides of the queue, and items
// are removed in the same order in which they were inserted.

// The double-ended  queue object, pronounced  deck, can push  and pop
// from either side, allowing you to  control the order in which items
// are inserted and removed.

// stack que is a LIFO, push and pop at the same end

// que is a FIFO, push one end and pop at the other end

// double ended que, can push and pop from either side

// Container adapter. What a container adapter does is, it takes
// another container, and it adapts it for a particular use.

int main( int argc, char ** argv ) {
    cout << "initialize stack from list:" << endl;
    // li is a list of integers, si is stack of integers in li
    list<int> li = { 1, 2, 3, 4, 5 };
    stack<int, list<int>> si(li);	// constructor copies to new list
    
    cout << "li has " << li.size() << " entries; si has " << si.size() << " entries." << endl;

    // pop all of si leaves si empty but li is still fully full as si
    // uses a copy of li, not li itself.
    cout << "pop all from si:" << endl;
    while(!si.empty()) {
      // top() allows you to look at element your about to pop off.
        cout << si.top() << " ";
        si.pop();
    }
    cout << endl;
    
    cout << "li has " << li.size() << " entries; si has " << si.size() << " entries." << endl;
    
    cout << "contents of li after sl is emptied:" << endl;
    for( int i : li ) cout << i << ' ';
    cout << endl;
    
    stack<string> ss;	// default stack uses deque object
    cout << "push strings onto ss:" << endl;
    ss.push("one");
    ss.push("two");
    ss.push("three");
    ss.push("four");
    ss.push("five");
    cout << "size of ss: " << ss.size() << endl;
    cout << "pop all from ss:" << endl;
    while(!ss.empty()) {
        cout << ss.top() << " ";
        ss.pop();
    }
    cout << endl;
    cout << "size of ss: " << ss.size() << endl;
    
    return 0;
}
