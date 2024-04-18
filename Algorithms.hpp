/** A header file for the Algorithms */
#include <string>
#include <vector>
#include <queue>
#include <limits.h>
#include "Graph.hpp"
namespace ariel{
class Algorithms{
    public:
      static int isConnected(Graph g);
     static string shortestPath(Graph g, int start, int end);
     static string isContainsCycle(Graph g);
    static string isBipartite(Graph g);
     static string negativeCycle(Graph g);
};
}

