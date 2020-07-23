#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

int main(){

  // 9 rows in vector, ie 9 rows or vectors in another vector
  // vec2d(rows) or vec2d(num horozontal elements)
  vector<vector<int> > vec2d(9);
  vector<vector<int> > vec2d1(1);
  
  
  vec2d.at(0).push_back(1);
  
  vec2d.at(1).push_back(0);
  vec2d.at(1).push_back(5);
  
  vec2d.at(2).push_back(4);
  
  vec2d.at(3).push_back(4);
  
  vec2d.at(4).push_back(2);
  vec2d.at(4).push_back(3);
  vec2d.at(4).push_back(5);
  
  vec2d.at(5).push_back(1);
  vec2d.at(5).push_back(4);
  vec2d.at(5).push_back(6);
  vec2d.at(5).push_back(7);
  
  vec2d.at(6).push_back(5);
  
  vec2d.at(7).push_back(5);
  vec2d.at(7).push_back(8);
  
  vec2d.at(8).push_back(7);

  for(int i=0; i<vec2d.size(); i++){
    for(int j=0; j<vec2d[i].size(); j++){
      fprintf(stderr, "vec2d[%d][%d]=%d\n", i, j, vec2d[i][j]);
    }
  }

  //vec2d.at(7).clear();
  
  for(int i=0; i<vec2d.size(); i++){
    // leaves container with size=0, elements of vector destroyed
    vec2d[i].clear();
    for(int j=0; j<vec2d[i].size(); j++){
      fprintf(stderr, "vec2d[%d][%d]=%d\n", i, j, vec2d[i][j]);
    }
  }
  

  vec2d1.at(0).push_back(11);

  fprintf(stderr, "vec2d1.at(0).push_back(11)=%d\n", vec2d1[0][0]);

  // matrix with vectors
  int rows =2;
  int columns =3;
  int initValue = 99;
  //
  vector<vector<int> > matrix(rows, vector<int>(columns));
  //
  for(int i=0; i<rows; i++){
    for(int j=0; j<columns; j++){
            fprintf(stderr, "matrix[%d][%d]=%d\n", i, j, matrix[i][j]);
    }
  }
  

  vector<vector<int> > matrix1(rows, vector<int>(columns, initValue));
  for(int i=0; i<rows; i++){
    for(int j=0; j<columns; j++){
      fprintf(stderr, "matrix1[%d][%d]=%d\n", i, j, matrix1[i][j]);
    }
  }

  
  
  return 0;
}

