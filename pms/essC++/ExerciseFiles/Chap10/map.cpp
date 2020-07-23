// map.cpp by Bill Weinman <http://bw.org/>
#include <iostream>
#include <string>
#include <map>

using namespace std;

// The data in  the map containers are organised in  pairs, that is, a
// key value and a mapped value, and the map is orded by the key.


int main( int argc, char ** argv ) {
    cout << "map of strings from initializer list:" << endl;
    map<string, string> strmap = { { "George", "Father" }, { "Ellen", "Mother" },
        { "Ruth", "Daughter" }, { "Spike", "Neighbor's Son" } };
    
    cout << "size is " << strmap.size() << endl;
    cout << "get some values:" << endl;
    // different methods to get the values here:
    // using subcript operator
    cout << "George is " << strmap["George"] << endl;
    // at method works exactly like the subscript operator
    cout << "Ellen is " << strmap.at("Ellen") << endl;
    // returns an itterator to the pair
    cout << "Spike is " << strmap.find("Spike")->second << endl;
    cout << endl;
    
    cout << "loop through the map:" << endl;
    // output is in alphabetical order, based on the key
    for( auto p : strmap ) {
        cout << p.first << " is " << p.second << endl;
    }
    cout << endl;

    // now we have five elements in the map
    cout << "insert an element:" << endl;
//    strmap.insert( { "Luke", "Neighbor" } );
    strmap.insert( { "Bill", "Programmer" } );
    cout << "inserted - size is " << strmap.size() << endl;
    for( auto p : strmap ) {
        cout << p.first << " is " << p.second << endl;
    }
    cout << endl;
    
    cout << "insert a duplicate:" << endl;
    // if one is already there it fails, if it's a new one it is added
    // to the map
    //
    // insert returns a pair, iterator and success/failure bool
    auto rp = strmap.insert( { "Luke", "Neighbor" } );
    if (rp.second) {
        cout << "insert succeeded: " << rp.first->first << " is " << rp.first->second << endl;
    } else {
        cout << "insert failed" << endl;
    }
    cout << "after insert size is " << strmap.size() << endl;
    for( auto p : strmap ) {
        cout << p.first << " is " << p.second << endl;
    }
    cout << endl;
    
    cout << "find and erase an element:" << endl;
    auto it = strmap.find("Spike");
    if(it != strmap.end()) {
        cout << "found " << it->first << ":" << it->second << endl;
        strmap.erase(it);
        cout << "erased - size is " << strmap.size() << endl;
    } else {
        cout << "not found" << endl;
    }
    for( auto p : strmap ) {
        cout << p.first << " is " << p.second << endl;
    }
    cout << endl;
    
    return 0;
}
