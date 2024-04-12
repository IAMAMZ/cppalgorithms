#include <iostream>
#include <list>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::vector;

class Graph {
 private:
  // Number of vertices
  int V;
  // Pointer to adjacency list
  vector<list<int>> adj; // Now storing indices of vertices

 public:
  // Constructor prototype
  Graph(int v);

  // Method to add an edge
  void addEdge(char v, char w);

  // Method for BFS traversal given a source "s"
  void BFS(char s);

  // Method for DFS traversal given start node 's';
  void DFS(char s);
  // helper method for DFS recursion with an array of visited elements
  void DFS_helper(char s, bool* visited);
};

// Constructor with number of vertices
Graph::Graph(int v) {
  V = v;
  adj.resize(v);
}

// Implementation of method to add edges
void Graph::addEdge(char v, char w) {
  // Convert char to index since we represent verticies as chars
  int vIndex = v - 'a';
  int wIndex = w - 'a';
  adj[vIndex].push_back(wIndex); 
}

void Graph::BFS(char start) {
    // Start with all vertices as not visited
    vector<bool> visited(V, false);

    // A lambda function to perform BFS from a given node sIndex
    auto bfsFromNode = [&](int sIndex) {
        list<int> queue;

        // Mark the current node as visited and enqueue it
        visited[sIndex] = true;
        cout << "visiting: " << static_cast<char>('a' + sIndex) << endl;

        queue.push_back(sIndex);

        while(!queue.empty()) {
            // Dequeue a vertex from queue and print it
            sIndex = queue.front();
            cout << "Popping: " << static_cast<char>('a' + sIndex) << endl;
            queue.pop_front();

            // Get all adjacent vertices of the dequeued vertex s
            // If a adjacent has not been visited, then mark it visited and enqueue it
            for (auto adjIndex : adj[sIndex]) {
                if (!visited[adjIndex]) {
                    cout << "visiting: " << static_cast<char>('a' + adjIndex) << endl;
                    visited[adjIndex] = true;
                    queue.push_back(adjIndex);
                }
            }
        }
    };

    // Initially start BFS from the given starting node
    int startIndex = start - 'a';
    bfsFromNode(startIndex);

    // Check for any node that hasn't been visited and perform BFS from there
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            bfsFromNode(i);
        }
    }
}


void Graph::DFS_helper(char s, bool *visited){


    // convert char to index

    int sIndex = s -'a';
    // visit node
    cout << "Visiting node " << s <<endl;
    visited[sIndex] = true;

    // go through adjacency list 
    for( auto i=adj[sIndex].begin(); i!=adj[sIndex].end(); i++){\

        // convert index back to char
        char adjacent = static_cast<char>('a' + *i);

        // if we have not visited then visit
        if(!visited[*i]){
            cout <<" going to vertex "<<adjacent<<" from vertex "<<s <<endl;
            DFS_helper(adjacent,visited);
        }
    }

    


}

void Graph::DFS(char start) {
    // Initialize visited array
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // Start DFS from the given starting node
    DFS_helper(start, visited);

    // Check for any vertex that hasn't been visited and start DFS from it
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            // Convert index back to char to use DFS_helper correctly
            char startChar = static_cast<char>('a' + i);
            DFS_helper(startChar, visited);
        }
    }

    // Clean up
    delete[] visited;
}

int main() {
  // Create a new graph
  Graph graph1(10); 

 cout<<"<=========== Graph 1 ==============>"<<endl;
  // Create some edges between the vertices
  graph1.addEdge('a', 'e');
  graph1.addEdge('a', 'd');
  graph1.addEdge('a', 'c');


  graph1.addEdge('c', 'a');
  graph1.addEdge('c', 'd');
  graph1.addEdge('c', 'f');

  graph1.addEdge('d', 'a');
  graph1.addEdge('d', 'c');


  graph1.addEdge('f', 'c');
  graph1.addEdge('f', 'e');
  graph1.addEdge('f', 'b');


  graph1.addEdge('e', 'a');
  graph1.addEdge('e', 'f');
  graph1.addEdge('e', 'b');

  graph1.addEdge('b', 'f');
  graph1.addEdge('b', 'e');

  graph1.addEdge('g','h');
  graph1.addEdge('g','h');

  graph1.addEdge('j','i');
  graph1.addEdge('j','g');

  graph1.addEdge('h','g');
  graph1.addEdge('h','i');

  // Perform BFS starting from vertex 'a' and print result
  cout<<"<---------- BFS ---------->"<<endl;
  graph1.BFS('a');
  cout<<"<---------- DFS ---------->"<<endl;
  graph1.DFS('a');


  // insert graph 2

 cout<<"<=========== Graph 2 ==============>"<<endl;
  Graph graph2(8);

  graph2.addEdge('a','b');
  graph2.addEdge('a','e');

  graph2.addEdge('b','a');
  graph2.addEdge('b','f');
  graph2.addEdge('b','c');

  graph2.addEdge('c','b');
  graph2.addEdge('c','g');
  graph2.addEdge('c','d');

  graph2.addEdge('d','c');
  graph2.addEdge('d','h');

  graph2.addEdge('h','d');
  graph2.addEdge('h','g');

  graph2.addEdge('g','h');
  graph2.addEdge('g','c');
  graph2.addEdge('g','f');

  graph2.addEdge('f','g');
  graph2.addEdge('f','b');
  graph2.addEdge('f','e');

  graph2.addEdge('e','f');
  graph2.addEdge('e','a');

  cout<<"<---------- BFS ---------->"<<endl;
  graph2.BFS('a');
  cout<<"<---------- DFS ---------->"<<endl;
  graph2.DFS('a');

   cout<<"<=========== Graph 3 ==============>"<<endl;

   Graph graph3(7);

   graph3.addEdge('a','b');
   graph3.addEdge('a','c');
   graph3.addEdge('a','e');
   graph3.addEdge('a','d');


   graph3.addEdge('b','a');
   graph3.addEdge('b','d');
   graph3.addEdge('b','f');

   graph3.addEdge('f','b');
   graph3.addEdge('f','d');

   graph3.addEdge('d','f');
   graph3.addEdge('d','b');
   graph3.addEdge('d','a');


   graph3.addEdge('c','a');
   graph3.addEdge('c','g');

   graph3.addEdge('g','c');
   graph3.addEdge('g','e');

   graph3.addEdge('e','g');
   graph3.addEdge('e','a');

  cout<<"<---------- BFS ---------->"<<endl;
   graph3.BFS('a');
 cout<<"<---------- DFS ---------->"<<endl;
  graph3.DFS('a');


   cout<<"<=========== Graph 4 ==============>"<<endl;

    Graph graph4(4);
    graph4.addEdge('a','c');
    graph4.addEdge('b','a');

    graph4.addEdge('c','b');
    graph4.addEdge('c','d');

    graph4.addEdge('d','a');

  cout<<"<---------- BFS ---------->"<<endl;
    graph4.BFS('a');
    cout<<"<---------- DFS ---------->"<<endl;
  graph4.DFS('a');


  return 0;
}