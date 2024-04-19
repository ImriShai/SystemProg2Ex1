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
    bool directed;
    bool negative;
    bool weighted;
    bool sameWeight;
    public:
    vector<vector<int>> getAdjMatrix(){
        return adjMatrix;
    }
    void printGraph();

    bool isDirected(){
        return directed;
    }
    bool isNegative(){
        return negative;
    }
    bool isWeighted(){
        return weighted;

    }
    bool isSameWeight(){
        return sameWeight;
    }

    void loadGraph(vector<vector<int>> adjMatrix);

};
}