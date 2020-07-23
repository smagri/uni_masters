// set.cpp by Bill Weinman <http://bw.org/>
#include <iostream>
#include <string>
#include <set>

using namespace std;


// A set is an Associative Container which means that the elements are
// referenced  by their  value rather  than by  their location  in the
// container. A set holds an ordered  set of objects and it holds only
// unique objects  where there's another version  called Multiset that
// allows duplicates. Set does not support random access and it uses a
// Bidirectional Iterator.

// So sets are really useful in cases where you need an ordered set of
// objects that you can search but you don't need random access.


int main( int argc, char ** argv ) {
  set<string> strset = { "one", "two", "three", "four", "five" };
    cout << "size of set: " << strset.size() << endl;
    cout << "ordered set is alphabetical:" << endl;
    for(string s : strset) {
        cout << s << " ";
    }
    cout << endl << endl;
    
    cout << "insert element \"six\":" << endl;
    // inserts in the correct alphabetical location
    strset.insert("six");
    for(string s : strset) {
        cout << s << " ";
    }
    cout << endl << endl;

    // can do this becase set is associative
    cout << "find and erase element \"six\":" << endl;
    set<string>::iterator it = strset.find("six");
    if(it != strset.end()) {
        cout << "erasing " << *it << endl;
        strset.erase(it);
    } else {
        cout << "not found" << endl;
    }
    for(string s : strset) {
        cout << s << " ";
    }
    cout << endl << endl;

    // Trying to insert a duplicate element does not work.
    //
    // If instead of  using set, we use  a multiset you get a duplicate five.
    //
    cout << "insert duplicate element \"five\":" << endl;
    strset.insert("five");
    for(string s : strset) {
        cout << s << " ";
    }
    cout << endl << endl;

    // multiset version, sms is string multi set.
    multiset<string> sms = { "one", "two", "three", "four", "five" };
    cout << "insert duplicate element \"five\":" << endl;
    sms.insert("five");
    for(string s : sms) {
      cout << s << " ";
    }
    cout << endl << endl;



    // I can get an error from this.   The error is a pair so use auto
    // rp = insert then  test and see if it failed.   The pair that is
    // returned by insert returns two  elements in the pair.  First is
    // an Iterator pointing to either the newly inserted element or an
    // existing element if the insert failed due to duplicate.
    //
    // The second  is bool  which is  true for  success and  false for
    // failure due to duplicate. ie rp.second.
    //
    // "five" string  is already  in strset so  you can't  put another
    // "five" string into it.  If you  try to insert "seven" string it
    // works cause it does not already contain the string "seven".
    //
    cout << "insert duplicate element \"five\":" << endl;
    auto rp = strset.insert("five");
    if (rp.second){
      // if insert was successful
      cout << "input succeded" << endl;
    }
    else{
      cout << "input failed" << endl;
    }
    for(string s : strset) {
      cout << s << " ";
    }
    cout << endl << endl;


    
// Multiset version  of Insert only  returns an Iterator. It  does not
// return a pair because it's not  going to fail due to duplicates.

    auto rp1 = strset.insert("seven");
    if (rp1.second){
      // if insert was successful
      cout << "input succeded" << endl;
    }
    else{
      cout << "input failed" << endl;
    }
    for(string s : strset) {
      cout << s << " ";
    }
    cout << endl << endl;
    
    
    return 0;
}
