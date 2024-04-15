/** A header file for the Algorithms */
#include <string>
#include <vector>
#include "Graph.hpp"
namespace ariel{
class Algorithms{
    public:
      static int isConnected(ariel::Graph g);
     static string shortestPath(ariel::Graph g, int start, int end);
     static int isContainsCycle(ariel::Graph g);
    static string isBipartite(ariel::Graph g);
     static void negativeCycle(ariel::Graph g);
};
}

