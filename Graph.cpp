/** Implementation of class Graph*/
#include "Graph.hpp"
using namespace ariel;

Graph Graph::loadGraph(vector<vector<int>> adjMatrix) {
    if(adjMatrix.size() == 0 ){
        throw invalid_argument("The matrix is empty");
    }
    if ( adjMatrix.size()!=adjMatrix[0].size())
    {
        throw invalid_argument("Not a valid graph!");
    }
    
    this->adjMatrix = adjMatrix; //loading the actual matrix
    this->numVertices = adjMatrix.size(); 
    this->numEdges = 0;
    for(int i = 0; i < numVertices; i++){
        for(int j = 0; j < numVertices; j++){
            if(adjMatrix[i][j] != 0){
                numEdges++;   //counting each edge 
            }
        }
    }
}