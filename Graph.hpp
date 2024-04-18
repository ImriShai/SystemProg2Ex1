/** header file of class Graph*/
#pragma once
#include <iostream>
#include <vector>
using namespace std;
namespace ariel{
class Graph{
    private:
     vector<vector<int>> adjMatrix;
    int numVertices;
    int numEdges;
    public:
    vector<vector<int>> getAdjMatrix(){
        return adjMatrix;
    }
    void printGraph(){
        cout<<"Graph with "<<numVertices<<" vertices and "<<numEdges<<" edges."<<endl; 
    }
    void loadGraph(vector<vector<int>> adjMatrix);

};
}