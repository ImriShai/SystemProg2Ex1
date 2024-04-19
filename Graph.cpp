/** Implementation of class Graph*/

#include "Graph.hpp"
using namespace ariel;

void Graph::loadGraph(vector<vector<int>> adjMatrix) {
    if(adjMatrix.empty()){
        throw invalid_argument("The matrix is empty");
    }
    if ( adjMatrix.size()!=adjMatrix[0].size())
    {
        throw invalid_argument("Not a valid graph!");
    }
    
    this->adjMatrix = adjMatrix; //loading the actual matrix
    this->numVertices = adjMatrix.size(); 
    this->numEdges = 0;
    this->directed = false;
    this->weighted = false;
    this->sameWeight = true;
    this->negative = false;
    bool firstEdge = true;
    int firstEdgeVal = 0;
    for(size_t i = 0; i < numVertices; i++){
        for(size_t j = 0; j < numVertices; j++){
            if(adjMatrix[i][j] != 0){
                numEdges++;   //counting each edge
                if (adjMatrix[i][j]<0) negative =true;
                if (adjMatrix[i][j]!=adjMatrix[j][i]) directed = true;
                if (adjMatrix[i][j]!=0&&adjMatrix[i][j]!=1) weighted = true;
                if (firstEdge){
                    firstEdgeVal = adjMatrix[i][j];
                    firstEdge = false;
                }
                else if (adjMatrix[i][j]!=firstEdgeVal) sameWeight = false;
            }
        }
    }
    if (!directed) numEdges/=2;
}
void Graph::printGraph() {
    if (!directed&&!weighted){
        cout<<"This is a undirected and unweighted graph with " << numVertices << " vertices and " << numEdges <<" edges"<<endl;
    }
    if (!directed&&weighted&&!negative){
        cout<<"This is a undirected weighted graph with non-negative weights, " << numVertices << " vertices and " << numEdges <<" edges"<<endl;
    }
    if (!directed&&weighted&&negative){
        cout<<"This is a undirected weighted graph with negative weights, " << numVertices << " vertices and " << numEdges <<" edges"<<endl;
    }
    if (directed&&!weighted){
        cout<<"This is a directed and unweighted graph with " << numVertices << " vertices and " << numEdges <<" edges"<<endl;
    }
    if (directed&&weighted&&!negative){
        cout<<"This is a directed weighted graph with non-negative weights, " << numVertices << " vertices and " << numEdges <<" edges"<<endl;
    }
    if (directed&&weighted&&negative){
        cout<<"This is a directed weighted graph with negative weights, " << numVertices << " vertices and " << numEdges <<" edges"<<endl;
    }
}