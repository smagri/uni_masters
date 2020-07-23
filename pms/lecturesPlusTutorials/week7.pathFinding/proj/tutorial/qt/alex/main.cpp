#include <algorithm> // for std::reverse()
#include <map>
#include <queue>
#include <set>
#include <list>
#include <vector>
#include <cstdio>
#include <iostream>


using namespace std;


vector<int> reconstruct_path(map<int, int> parents, int goal){

  vector<int> path;
  path.push_back(goal); // work backwards from goal node

  // vector<int> path.back() returns a reference to the last element
  // in the vector.
  //
  // So here, while last element in the vector is not the end of the
  // parents map container.
  //
  // For all parents in the map container, they form the reverse bfs
  // path.
  while (parents.find(path.back()) != parents.end()){
    // searh through parent's map put parent in the path
    path.push_back(parents.at(path.back()));
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


vector<int> breadthFirstSearch(vector<list<int> > &graph, int start, int goal){

  // note, graph is passed by reference.
  
  fprintf(stderr, "Breadth first search exploration order: ");

  // Additional search variables:
  //
  int current; // current node being processed
  map<int, int> parents; // the nodes that are parents, ie have children

  // Set of visited nodes, ie stores unique elements in a specific
  // order. Once in set element can't be modified(ie are const) but
  // you can insert and remove elements from set.
  //
  // This 'empty' set contains nodes in the algorithim that have
  // already been visited.
  //
  set<int> visited;

  // 'Emplty' queue(aka FIFO).
  queue<int> q;

  visited.insert(start); // We are at the start node, visiting it.
  q.push(start);	 // Put start node on the frontier que/FIFO.

  
  while(!q.empty()){
    
    // current node is at the front of the frontier queue/FIFO q.
    current = q.front();
    q.pop();
    
    // Print exploration order.
    fprintf(stderr, "%d ", current);
    
    if(current == goal){
      // reconstruct path and RETURN.
      return reconstruct_path(parents, current);
    }

    // for each node n that is adjacent to the current:
    for (list<int>::iterator n = graph.at(current).begin();
	 n != graph.at(current).end(); n++){
      // itterates through all the nodes n.  list it itterates is the
      // graph vector of lists.
      
      // If n is not already visited. Fn find.(&val) takes a
      // reference/pointer to a value as input.
      if (visited.find(*n) == visited.end()){
	// ie n not found, and we got to the end of the visited set.

	// add n to visited list and parent list
	visited.insert(*n);
	parents[*n] = current;
	q.push(*n); // put the current node on the frontier que.
      }
    }

    
  } // while(!q.empty()){

  //fprintf(stderr, "\n\n");
  
} // bfs end




int main(){

  // Build the graph
  //
  // Double linked lists are easier to insert and delete units from.
  //
  // Vectors gives random access but needs to move around a lot of memory.
  //
  vector<list<int> > house_graph(9);

  house_graph.at(0).push_back(1);
  
  house_graph.at(1).push_back(0);
  house_graph.at(1).push_back(5);
  
  house_graph.at(2).push_back(4);
  
  house_graph.at(3).push_back(4);
  
  house_graph.at(4).push_back(2);
  house_graph.at(4).push_back(3);
  house_graph.at(4).push_back(5);

  house_graph.at(5).push_back(1);
  house_graph.at(5).push_back(4);
  house_graph.at(5).push_back(6);
  house_graph.at(5).push_back(7);

  house_graph.at(6).push_back(5);

  house_graph.at(7).push_back(5);
  house_graph.at(7).push_back(8);

  house_graph.at(8).push_back(7);


  int start = 3;
  int goal = 0;
  vector<int> path;

  path = breadthFirstSearch(house_graph, start, goal);

  print_path(path);

  
  return 0;
}

