/** header file of class Graph*/
#pragma once
#include <iostream>
#include <vector>
using namespace std;
namespace ariel{

/** A class representing a graph*/
class Graph{
    private:
     vector<vector<int>> adjMatrix;
    int numVertices;
    int numEdges;
    bool directed;
    bool negative;
    bool weighted;
    bool sameWeight;
    bool loaded;
    public:
    Graph():loaded(false){};
    const vector<vector<int>>& getAdjMatrix() const{
        return adjMatrix;
    }
    const void printGraph();

    const bool isDirected() const{
         if(!loaded){
            throw invalid_argument("The graph is not loaded");
        }
        return directed;
    }
   const  bool isNegative() const{
         if(!loaded){
            throw invalid_argument("The graph is not loaded");
        }
        return negative;
    }
   const  bool isWeighted() const{
         if(!loaded){
            throw invalid_argument("The graph is not loaded");
        }
        return weighted;

    }
  const  bool isSameWeight() const{
        if(!loaded){
            throw invalid_argument("The graph is not loaded");
        }
        return sameWeight;
    }
   const bool isLoaded() const{
        return loaded;
    }

    void loadGraph(vector<vector<int>> adjMatrix);

};
}