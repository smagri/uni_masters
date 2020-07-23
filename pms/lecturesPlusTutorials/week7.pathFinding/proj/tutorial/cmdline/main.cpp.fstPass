#include <queue>
#include <vector>


using namespace std;


int bfs(vector<vector<int> > graphAdjList, vector<int> parent,
	int rootNode, int goalNode){

  // Breadth-First-Search
  //
  //
  vector<int> visitedNode; // S, visited node, vector of integers
  queue<int> frontierNode; // Q, FIFO of integers
  int curNode = 0; // current node being processed
  int nodeVisitedAlready;
  
  visitedNode.at(0) = rootNode;
  frontierNode.push(rootNode);


  while(!frontierNode.empty()){

    curNode = frontierNode.front();
    frontierNode.pop();


    if(curNode == goalNode){
      // If we have arrived at the goal node return this node number.
      return curNode;
    }


    // Foreach node n that is adjacent to current node.
    for(int node=0; node<graphAdjList.size(); node++){
      // All nodes:
      
      nodeVisitedAlready = 0;
      
      for (int j=0; j<graphAdjList[curNode].size(); j++){
	
	if (graphAdjList[curNode][j] == node){
	  // Each node adjacent to the current node.
	  
	  // Determine if node has already been visited.
	  for(int i=0; i<visitedNode.size(); i++){
	    if(visitedNode[i] == node){
	      // Node visited already.
	      nodeVisitedAlready = 1;
	    }
	  }
	  
	  // If node _not_ visited already.
	  if (!nodeVisitedAlready){
	    visitedNode.push_back(node);
	    parent[node] = curNode;
	    frontierNode.push(node);
	  }
	}
      } // for (j=0; i<graphAdjList[curNode].size(); j++){
      
    } // for(int node=0; node<graphAdjList.size(); node++){

    
  } // while(!frontierNode.empty()){
  
} // int bfs(graphAdjList, parent, rootNode, goalNode){



int main(int argc, char *argv[]){


  // BFS algorithm adjacentcy List, derived from graph.
  //
  vector<vector<int> > graphAdjList; // 2x2 vector
  vector<int> parent;	   // vector of parent nodes

  // graphAdjList.at(row).push_back(column)
  //
  // This is better system to fill a 2x2 vector(ie vector of vectors).
  //
  graphAdjList.push_back(vector<int>());
  
  graphAdjList.at(0).push_back(1);
  
  // graphAdjList.at(1).push_back(0);
  // graphAdjList.at(1).push_back(5);
  
  // graphAdjList.at(2).push_back(4);
  
  // graphAdjList.at(3).push_back(4);
  
  // graphAdjList.at(4).push_back(2);
  // graphAdjList.at(4).push_back(3);
  // graphAdjList.at(4).push_back(5);

  // graphAdjList.at(5).push_back(1);
  // graphAdjList.at(5).push_back(4);
  // graphAdjList.at(5).push_back(6);
  // graphAdjList.at(5).push_back(7);

  // graphAdjList.at(6).push_back(5);

  // graphAdjList.at(7).push_back(5);
  // graphAdjList.at(7).push_back(8);

  // graphAdjList.at(8).push_back(7);
  

  int rootNode = 3;
  int goalNode = 0;

  
  //bfs(graphAdjList, parent, rootNode, goalNode);


}
