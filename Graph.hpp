/** header file of class Graph*/

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
    void printGraph(){
        cout<<"Graph with "<<numVertices<<"vertices and "<<numEdges<<" edges."<<endl; 
    }
    Graph loadGraph(vector<vector<int>> adjMatrix);

};
};