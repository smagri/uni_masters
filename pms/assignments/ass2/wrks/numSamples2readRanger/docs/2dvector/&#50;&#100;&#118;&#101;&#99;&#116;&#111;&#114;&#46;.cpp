#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	
    vector<vector<int> > vec;
	
	for(int i = 0; i < 5; i++)
	{
         vector<int> row;
         vec.push_back(row);
    }
    
    vec[0].push_back(5);
    cout << vec[0][0] << endl;
	
    system("pause");
    return 0;
}
