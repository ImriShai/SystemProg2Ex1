/** Implementation of the Algorithm class*/
#include "Algorithms.hpp"
using namespace std;
bool isContainsCycleUtil(ariel::Graph g, int v, vector<bool>& visited, vector<int>& parent) {
       
        visited[(size_t)v] = true; //marking the current vertex as visited
        vector<vector<int>> adjMatrix = g.getAdjMatrix();
        for (size_t i = 0; i < adjMatrix.size(); i++) { //go through all the vertices
            if (adjMatrix[(size_t)v][i] && !visited[i]) { //if there is an edge between the current vertex and the vertex i, and we haven't visited i yet 
                parent[i] = v; // update the parent of i to be v and recursively call the function
                if (isContainsCycleUtil(g, i, visited, parent)) { 
                    return true;
                }
            }
            else if (adjMatrix[(size_t)v][i] && visited[i] && parent[(size_t)v] != i) { //if there exists an edge between the current vertex and i, and we have visited i, and i is not the parent of v, then there is a cycle
                return true;
            }
        }
        return false;
    }
static ariel::Graph transpose(ariel::Graph g){
  vector<vector<int>> adjMatrix = g.getAdjMatrix();
   for(size_t i=0; i<adjMatrix.size(); i++){
       for(size_t j=0; j<i; j++){
           int temp = adjMatrix[i][j];
              adjMatrix[i][j] = adjMatrix[j][i];
                adjMatrix[j][i] = temp;
       }
   }
   g.loadGraph(adjMatrix);
   return g;
   

}
static void DFS(ariel::Graph g, int start, vector<bool> &visited){
    visited[(size_t)start] = true;
    vector<vector<int>> adjMatrix = g.getAdjMatrix();
    for(size_t i=0; i<adjMatrix.size(); i++){
        if(adjMatrix[(size_t)start][i] && !visited[i]){
            DFS(g, i, visited);
        }
    }
}

static int isConnected(ariel::Graph g){ //I think it will work
    vector<bool> visited(g.getAdjMatrix().size(), false);
    DFS(g, 0, visited); //runnig DFS from the first vertex
    for(size_t i=0; i<visited.size(); i++){
        if(!visited[i]){
            return 0; //if there is a vertex that wasn't visited, the graph is not connected
        }
        visited[i] = false;
    } //if we got here, then we can get to any vertex from the first vertex
    //then we will transpose the graph and run DFS from the first vertex again, if we visit every vertex, then we can reach from every vertex to the first vertex, so the graph is connected
    ariel::Graph gT;
    gT = transpose(g);
    DFS(gT, 0, visited);
    for(size_t i=0; i<visited.size(); i++){
        if(!visited[i]){
            return 0;
        }
    }
    return 1;
}

static string isContainsCycle(ariel::Graph g){ //running a version of DSF that will return the actual cycle
    vector<vector<int>> adjMatrix = g.getAdjMatrix();
    vector<bool> visited(adjMatrix.size(), false);
    vector<int> parent(adjMatrix.size(), -1);
    for (size_t i = 0; i < adjMatrix.size(); i++) {
        if (!visited[i]) {  //if we haven't visited the vertex yet, call the helper function, that updates the parent vector, and returns true if there is a cycle
            if (isContainsCycleUtil(g, i, visited, parent)) {
                string cycle; //if there is a cycle, we will return the cycle, by going through the parent vector
                int start = i;
                while (parent[(size_t)start] != -1) {
                    cycle += to_string(start) + "->";
                    start = parent[(size_t)start];
                }
                cycle += to_string(i);
                return cycle;
            }
        }
    }
    return "0";
}
