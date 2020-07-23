#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <iostream>

using namespace std;


vector<int> reconstruct_path(map<int, int> parentNodes, int goalNode){

  vector<int> path;
  path.push_back(goalNode); // work backwards from goal node

  // vector<int> path.back() returns a reference to the last element
  // in the vector.
  //
  // So here, while last element in the vector is not the end of the
  // parentNodes map container.
  //
  // For all parentNodes in the map container, they form the reverse bfs
  // path.
  while (parentNodes.find(path.back()) != parentNodes.end()){
    // searh through parent's map put parent in the path
    path.push_back(parentNodes.at(path.back()));
  }

  // Reverses the order of the elements in the vector path.
  std::reverse(path.begin(), path.end());
  
  return path;
}


void print_path(vector<int> path){

  //cout << endl << "Path nodes are: ";
  fprintf(stderr, "\nPath nodes are: ");
  
    for(vector<int>::iterator n=path.begin(); n != path.end(); n++){
    fprintf(stderr, " %d", *n); // unbuffered io needed, don't use:
                                // cout << *n << " ";
  }
  fprintf(stderr, "\n"); // unbuffered io needed, don't use: cout << endl;

}


vector<int> breadthFirstSearch(vector<vector<int> > &graphAdjList,
			       int rootNode, int goalNode){

  // Breadth-First-Search
  //            
  //
  // Pass graphAdjList in by reference, fn prototype and fn definition
  // need to reflect that.
  // note, graph is passed by reference.

  fprintf(stderr, "Breadth first search exploration order: ");

  // Additional search variables:                                         
  //
  
  // Vector of visited nodes, ie  stores unique elements in a specific
  // order. Once  in set element  can't be modified(ie are  const) but
  // you can insert and remove elements from set.
  //
  // This 'empty' vector contains nodes in the algorithim that have
  // already been visited.
  //                                                                           
  vector<int> visitedNode; // S, visited node, vector of integers
  queue<int> frontierNode; // Q, queue, aka FIFO of integers

  map<int, int> parentNodes; // the nodes that are parentNodes, ie have children
  int curNode; // current node being processed

  visitedNode.push_back(rootNode); // We are at the start node, visiting it.
  frontierNode.push(rootNode);     // Put start node on the frontier que/FIFO.

  
  while(!frontierNode.empty()){

    curNode = frontierNode.front();
    frontierNode.pop();

    // Print exploration order.                                                
    fprintf(stderr, "%d ", curNode);

    if(curNode == goalNode){
      // If we have arrived at the goal node reconstruct path and RETURN.
      //
      return reconstruct_path(parentNodes, curNode);
    }

    // for each node that is adjacent to the current:
    for (vector<int>::iterator node = graphAdjList.at(curNode).begin();
         node != graphAdjList.at(curNode).end(); node++){

      // Itterate over all the nodes/columns foreach row in
      // graphAdjList, curNode=row.
      
      // If node is _not_ already visited.
      //
      if (find(visitedNode.begin(), visitedNode.end(), *node)
	  == visitedNode.end()){
        // ie n not found, and we got to the end of the visited set.

        // add n to visited list and parent list
        visitedNode.push_back(*node);
        parentNodes[*node] = curNode; 	// parentNodes[key] = value.
        frontierNode.push(*node); // put the current node on the frontier que.
      }
    }

  } // end: while(!q.empty()){

  
}

  
int main(){

  vector<vector<int> > graphAdjList(9);

  graphAdjList.at(0).push_back(1);

  graphAdjList.at(1).push_back(0);
  graphAdjList.at(1).push_back(5);

  graphAdjList.at(2).push_back(4);

  graphAdjList.at(3).push_back(4);

  graphAdjList.at(4).push_back(2);
  graphAdjList.at(4).push_back(3);
  graphAdjList.at(4).push_back(5);

  graphAdjList.at(5).push_back(1);
  graphAdjList.at(5).push_back(4);
  graphAdjList.at(5).push_back(6);
  graphAdjList.at(5).push_back(7);

  graphAdjList.at(6).push_back(5);

  graphAdjList.at(7).push_back(5);
  graphAdjList.at(7).push_back(8);

  graphAdjList.at(8).push_back(7);


  int rootNode = 3; // search start node
  int goalNode = 0; // search end node
//  vector<int> parent; // vector of parent nodes
  vector<int> path;

  path = breadthFirstSearch(graphAdjList, rootNode, goalNode);

  print_path(path);

  
  return 0;
}

