/*
 * Demo program for Exercise 2.
 * Author: Benjamin Saldman.
 */
#include "Graph.hpp"
#include "Algorithms.hpp"

using ariel::Algorithms;

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

int main()
{
    ariel::Graph g;

    vector<vector<int>> graph5 = {
            {0, 0, 0, 0},
            {4, 0, -6, 0},
            {0, 0, 0, 5},
            {0, -2, 0, 0}};
    g.loadGraph(graph5);
    g.printGraph();                                    // Should print: "This is a directed weighted graph with negative weights, 4 vertices and 4 edges"
    cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
    cout << Algorithms::shortestPath(g, 0, 3) << endl; // Should print: "Negative cycle detected" (false).
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "No cycle detected" (false).
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "There is no valid bipartite partition of the graph"
    cout << ariel::Algorithms::negativeCycle(g) << endl; //== "0->1->2->0");

 vector<vector<int>> testGraph = {
           {0, 0, 0},
           {0, 0, 0},
           {0, 0, 0}};
        g.loadGraph(testGraph); // Load the graph to the object.

    g.printGraph();                                    // Should print: "This is a undirected and unweighted graph with 3 vertices and 0 edges"
    cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
    cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: "Start or End vertices are invalid!"
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "No cycle detected" (false)
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0}, B={1, 2}"


    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph =
        {{0, 1, 0},
         {1, 0, 1},
         {0, 1, 0}};
    g.loadGraph(graph); // Load the graph to the object.

    g.printGraph();                                    // Should print: "This is a undirected and unweighted graph with 3 vertices and 2 edges"
    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(g, 0, 1) << endl; // Should print: 0->1.
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "No cycle detected" (false)
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2}, B={1}."

    // 5x5 matrix that represents a non-connected graph with a cycle.
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph2); // Load the graph to the object.

    g.printGraph();                                    // Should print: "This is a undirected and unweighted graph with 5 vertices and 4 edges"
    cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
    cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: "There is no path between vertex 0 and vertex 4" (false).
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0->1->2->0" (The actual cycle)
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "There is no valid bipartite partition of the graph" (false).

    // 5x5 matrix that reprsents a connected weighted graph.
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3); // Load the graph to the object.

    g.printGraph();                                    // Should print: "This is a undirected weighted graph with non-negative weights, 5 vertices and 4 edges"
    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: 0->1->2->3->4.
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "No cycle detected" (false).
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2, 4}, B={1, 3}."

    // 5x4 matrix that reprsents invalid graph.
    vector<vector<int>> graph4 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    try
    {
        g.loadGraph(graph4); // Load the graph to the object.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print: "Not a valid graph!"
    }



   
}