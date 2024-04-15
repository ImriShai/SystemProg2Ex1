/** Implementation of class Graph*/

#include "Graph.hpp"
using namespace ariel;

void Graph::loadGraph(vector<vector<int>> adjMatrix) {
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
    for(size_t i = 0; i < numVertices; i++){
        for(size_t j = 0; j < numVertices; j++){
            if(adjMatrix[i][j] != 0){
                numEdges++;   //counting each edge 
            }
        }
    }
}