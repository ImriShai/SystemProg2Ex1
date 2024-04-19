/** Implementation of the Algorithm class*/
#include "Algorithms.hpp"

using namespace std;
static int isContainsCycleUtil(ariel::Graph g, int v, vector<bool>& visited, vector<int>& parent) {
       
        visited[(size_t)v] = true; //marking the current vertex as visited
        vector<vector<int>> adjMatrix = g.getAdjMatrix();
        for (size_t i = 0; i < adjMatrix.size(); i++) { //go through all the vertices
            if (adjMatrix[(size_t)v][i] && !visited[i]) { //if there is an edge between the current vertex and the vertex i, and we haven't visited i yet 
                parent[i] = v;  // update the parent of i to be v and recursively call the function
                int res = isContainsCycleUtil(g, i, visited, parent);
                if (res!=-1) {
                    return res;
                }
            }
            else if (adjMatrix[(size_t)v][i] && visited[i] && parent[(size_t)v] != i) { //if there exists an edge between the current vertex and i, and we have visited i, and i is not the parent of v, then there is a cycle
                return v;
            }
        }
        return -1;
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
static string BFS(ariel::Graph g,int start,int end){
    vector<vector<int>> adjMatrix = g.getAdjMatrix(); //get the adjacency matrix of the graph, and initialize the visited, distance, and parent vectors
    vector<bool> visited(adjMatrix.size(), false);
    vector<int> distance(adjMatrix.size(), INT_MAX);
    vector<int> parent(adjMatrix.size(), -1);
    queue<int> q;
    q.push(start); //push the start vertex to the queue, mark it as visited and set its distance to 0
    visited[(size_t)start] = true;
    distance[(size_t)start] = 0;

    while(!q.empty()){ //while the queue isn't empty, pop the front vertex, and go through all the vertices, if there is an edge between the front vertex and the current vertex, and the current vertex wasn't visited yet, mark it as visited, update its distance and parent vectors, and push it to the queue
        int u = q.front();
        q.pop();
        for(size_t i=0; i<adjMatrix.size(); i++){
            if(adjMatrix[(size_t)u][i] && !visited[i]){
                visited[(size_t)i] = true;
                distance[(size_t)i] = distance[(size_t)u] + 1;
                parent[(size_t)i] = u;
                q.push(i);
            }
            if(i == end&&parent[(size_t)end]!=-1){ //if we reached the end vertex, and the end vertex already been visited, create the path by going through the parent vector, and return it
                string path = "";
                while(parent[(size_t)i] != -1){
                    path = to_string(i) + "->" + path;
                    i = (size_t)parent[(size_t)i];
                }
                path = to_string(start) + "->" + path;
                path.pop_back();
                path.pop_back();
                return path;
            }
        }
    }
    return "There is no path between vertexr " + to_string(start) + " and vertex " + to_string(end);
    ;
    }

static string dijkstra(ariel::Graph g, int start, int end) {
    vector<vector<int>> adjMatrix = g.getAdjMatrix();
    size_t V = (size_t)adjMatrix.size(); // Number of vertices in the graph
    vector<int> dist(V, INT_MAX); // Initialize distances to all vertices as infinite
    vector<bool> visited(V, false); // Track visited vertices
    vector<int> prev(V, -1); // To store the path

    // Create a priority queue to store vertices that are being preprocessed
    priority_queue< pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > pq;

    // Distance of source vertex from itself is always 0
    dist[(size_t)start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        // The first vertex in pair is the minimum distance vertex, extract it from priority queue
        int u = pq.top().second;
        pq.pop();

        // Mark the picked vertex as visited
        visited[(size_t)u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        for (size_t v = 0; v < V; ++v) {
            // Update dist[v] only if it is not in visited, there is an edge from u to v,
            // and total weight of path from start to v through u is smaller than current value of dist[v]
            if (!visited[v] && adjMatrix[(size_t)u][v] && dist[(size_t)u] != INT_MAX && dist[(size_t)u] + adjMatrix[(size_t)u][v] < dist[v]) {
                dist[v] = dist[(size_t)u] + adjMatrix[(size_t)u][v];
                pq.push(make_pair(dist[v], v));
                prev[v] = u;
            }
        }
    }

    // If there is no path between start and end
    if (dist[(size_t)end] == INT_MAX) {
        return "There is no path between vertex " + to_string(start) + " and vertex " + to_string(end);
    }

    // Store the shortest path
    string path = "";
    for (int v = end; v != -1; v = prev[(size_t)v]) {
        path = to_string(v) + "->" + path;
    }

    // Remove the trailing "->"
    path = path.substr(0, path.length() - 2);

    return path;
}
static string bellmanFord(ariel::Graph g,int start,int end){
    vector<vector<int>> adjMatrix = g.getAdjMatrix();
    vector<int> distance(adjMatrix.size(), INT_MAX); //initialize the distance vector with infinity
    vector<int> parent(adjMatrix.size(), -1); //initialize the parent vector with -1
    distance[(size_t)start] = 0; //set the distance of the start vertex to 0
    for(size_t i=0; i<adjMatrix.size()-1; i++){ //run the loop n-1 times, where n is the number of vertices, each time relax all the edges
        for(size_t j=0; j<adjMatrix.size(); j++){
            for(size_t k=0; k<adjMatrix.size(); k++){
                if(adjMatrix[j][k]!=0&&distance[(size_t)j] != INT_MAX && distance[(size_t)j] + adjMatrix[(size_t)j][(size_t)k] < distance[(size_t)k]){
                    distance[(size_t)k] = distance[(size_t)j] + adjMatrix[(size_t)j][(size_t)k];
                    parent[(size_t)k] = j;
                }
            }
        }
    }
    for(size_t j=0; j<adjMatrix.size(); j++){ //run the loop one more time, if we can still relax one of the edges, then there is a negative cycle
        for(size_t k=0; k<adjMatrix.size(); k++){
            if(adjMatrix[j][k]!=0&&distance[(size_t)j] != INT_MAX && distance[(size_t)j] + adjMatrix[(size_t)j][(size_t)k] < distance[(size_t)k]){
                return "Negative cycle detected";
            }
        }
    }
    if(distance[(size_t)end] == INT_MAX) return "There is no path between vertex " + to_string(start) + " and vertex " + to_string(end);
    string path = "";
    for(int v = end; v != -1; v = parent[(size_t)v]){ //create the path by going through the parent vector
        path = to_string(v) + "->" + path;
    }
    path = path.substr(0, path.length() - 2); //remove the last "->"
    return path;
}

 int ariel::Algorithms::isConnected(ariel::Graph g){ //I think it will work
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

 string ariel::Algorithms::isContainsCycle(ariel::Graph g){ //running a version of DSF that will return the actual cycle
    vector<vector<int>> adjMatrix = g.getAdjMatrix();
    vector<bool> visited(adjMatrix.size(), false);
    vector<int> parent(adjMatrix.size(), -1);
    int start;
    for (size_t i = 0; i < adjMatrix.size(); i++) {
        if (!visited[i]) {  //if we haven't visited the vertex yet, call the helper function, that updates the parent vector, and returns true if there is a cycle
            start = isContainsCycleUtil(g, i, visited, parent);
            if (start!=-1) {
                string cycle; //if there is a cycle, we will return the cycle, by going through the parent vector
                while (parent[(size_t)start] != -1) {
                    cycle = to_string(start) + "->" + cycle;
                    start = parent[(size_t)start];

                }
                cycle += to_string(i);
                cycle = to_string(i)+"->"+cycle;
                return cycle;
            }
        }
    }
    return "0";
}

string ariel::Algorithms::isBipartite(ariel::Graph g){
    vector<vector<int>> adjMatrix = g.getAdjMatrix();
    vector<int> color(adjMatrix.size(), -1); //initialize the color vector with -1
    color[0] = 1; //color the first vertex with 1
    queue<int> q;
    q.push(0); //push the first vertex to the queue
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(size_t i=0; i<adjMatrix.size(); i++){
            if(adjMatrix[(size_t)u][i] && color[i] == -1){ //if there is an edge between u and i, and i is not colored yet
                color[i] = 1 - color[(size_t)u]; //color i with the opposite color of u
                q.push(i); //push i to the queue
            }
            else if(adjMatrix[(size_t)u][i] && color[i] == color[(size_t)u]){ //if there is an edge between u and i, and they have the same color, then the graph is not bipartite
                return "0";
            }
        }
    }
    string res = "The graph is bipartite: A={";
    for(size_t i=0; i<color.size(); i++){ //create the string representation of the first set
        if(color[i] == 1){
            res += to_string(i) + ", ";
        }
    }
    res.pop_back(); //remove the last comma
    res.pop_back(); //remove the last space
    res += "}, B={";
    for(size_t i=0; i<color.size(); i++){ //create the string representation of the second set and concatenate it to the first set
        if(color[i] == 0){
            res += to_string(i) + ", ";
        }
    }
    res.pop_back();
    res.pop_back();
    res += "}";
    return res;
}

string ariel::Algorithms::shortestPath(ariel::Graph g, int start, int end){
    if (g.isSameWeight()) return BFS(g,start,end); //might need to check what should I do with negative weights, when all the weights are the same
    if (!g.isNegative()) return dijkstra(g,start,end);
    return bellmanFord(g,start,end);
}
/**
 * @brief This function finds A negative cycle in the graph if exists
 * the function uses the Bellman-Ford algorithm to find the shortest path from a source vertex to all other vertices.
 *  by adding a vertex with weight 0 to all other vertices, and then running the Bellman-Ford algorithm, we can get to any negative cycle in the graph, if exists;
 * I used the wiki page https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm to implement the algorithm
 * @param g the graph
 * @return the negative cycle if exists, otherwise return "There is no negative cycle in the graph"
*/
string ariel::Algorithms::negativeCycle(ariel::Graph g){
    if(!g.isNegative()) return "0";
    vector<vector<int>> adjMatrixCopy = g.getAdjMatrix();
    vector<vector<int>> adjMatrix(adjMatrixCopy.size()+1, vector<int>(adjMatrixCopy.size()+1, 0)); //initalize a new matrix with the same values as the original matrix, but with a source vector that connected to each vertex with weight 0
    for(size_t i=0; i<adjMatrix.size(); i++){
        adjMatrix[0][i] = 0;
        adjMatrix[i][0] = INT_MAX;
    }
    for(size_t i=1; i<adjMatrix.size(); i++){
        for(size_t j=1; j<adjMatrix.size(); j++){
            if(adjMatrixCopy[i-1][j-1] != 0) adjMatrix[i][j] = adjMatrixCopy[i-1][j-1];
            else adjMatrix[i][j] = INT_MAX;
        }
    }
    vector<int> distance(adjMatrix.size(), INT_MAX); //initialize the distance vector with infinity
    vector<int> parent(adjMatrix.size(), -1); //initialize the parent vector with -1
    distance[0] = 0; //set the distance of the source vertex to 0
    for(size_t i=0; i<adjMatrix.size()-1; i++){  //run the loop n-1 times, where n is the number of vertices, including the new source vertex, each time relax all the edges
        for(size_t j=0; j<adjMatrix.size(); j++){
            for(size_t k=0; k<adjMatrix.size(); k++){
                if(distance[j] != INT_MAX && distance[j] + adjMatrix[j][k] < distance[k]){
                    distance[k] = distance[j] + adjMatrix[j][k];
                    parent[k] = j;
                }
            }
        }
    }
    for(size_t j=0; j<adjMatrix.size(); j++){ //run the loop one more time, if we can still relax one of the edges, then there is a negative cycle
        for(size_t k=0; k<adjMatrix.size(); k++){
            if(distance[j] != INT_MAX && distance[j] + adjMatrix[j][k] < distance[k]){ //if we can relax the edge
               string cycle;
                distance[k] = distance[j] + adjMatrix[j][k]; //update the distance and the parent vectors
                parent[k] = j;
                vector<bool> visited(adjMatrixCopy.size()+1,false); //initialize the visited vector with false
                int u = j; //start from u, mark all the vertices of the cycle as visited
                visited[k] =true;
                while (!visited[(size_t)u]){
                    visited[(size_t)u] = true;
                    u = parent[(size_t)u];
                }
                cycle = to_string(u-1); // create the string representation of the cycle
                int v = parent[(size_t)u];
                while(v!=u){ // go through the parent vector and create the string representation of the cycle
                    cycle = to_string(v-1) + "->" + cycle;
                    v = parent[(size_t)v];
                }
                cycle = to_string(u-1) + "->" + cycle; //add the end of the cycle and return it
                return cycle;
            }


        }
    }
    return "There is no negative cycle in the graph";
}
