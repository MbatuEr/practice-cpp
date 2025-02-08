#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <limits>
#include <cmath>
#include <climits>

typedef std::pair<double, int> pdi; // (distance, vertex).
typedef std::pair<int, double> pid; // (vertex, distance).

const double INF = std::numeric_limits<double>::infinity();
const double EPSILON = 1e-6; // Small penalty to prioritize fewer edges.

// Point structure for adjacency matrixes.
struct Point 
{
    int x, y;
};

// Vertex structure for the directed graph.
struct Vertex 
{
    int label;
    std::vector<Vertex*> neighbors;
};

// Structure to represent an edge.
struct Edge 
{
    int source, destination, weight;

    // Comparison function to sort edges based on weight.
    bool operator<(const Edge& other) const;  
};

template <typename T>
class Graph 
{
    private:
        int rows;
        int cols;
        std::vector<std::vector<T>>& adjacency_matrix;  

        // Checks if a point is valid within the maze boundaries.
        bool isValid(int x, int y);

    public:
        // Constructor.
        Graph(std::vector<std::vector<T>>& adjacency_matrix);

        // Breadth-first search to find a path from entrance to exit in the maze.
        std::vector<Point> findPath(Point start, Point end);

        // Print the distance matrix.
        void printMatrix(const std::vector<std::vector<T>>& matrix);

        // Depth-First Search to find and flip the region.
        void flipRegion(int x, int y);

        // Compute enclosed regions (optional, if needed).
        void computeEnclosedRegions();

        // Checks if there is a cycle in the adjacent list.
        bool hasCycle();

        // Checks if the list bipartite or not.
        bool isBipartite();

        // Find the maximum number of teams that can be photographed.
        int maxTeams();

        // Implements Floyd-Warshall Algorithm.
        void floydWarshall();
};

class GraphBase 
{
    private:
        // Checks if two strings differ by exactly one character.
        bool differByOne(const std::string& a, const std::string& b);

        // Finds the parent of a node (for disjoint sets).
        int findParent(std::vector<int>& parent, int i);

        // Performs union of two sets (by rank).
        void unionSets(std::vector<int>& parent, std::vector<int>& rank, int i, int j);

    public:
        // Clones a graph reachable from a given vertex.
        Vertex* cloneGraph(Vertex* u, std::unordered_map<Vertex*, Vertex*>& visited);

        // Checks if input strings can be obtained from each other through the given sets of strings.
        int shortestProductionSequence(const std::string& s, const std::string& t, const std::unordered_set<std::string>& dict);

        // Finds the shortest path with the fewest edges by using Dijkstra's algorithm.
        std::vector<int> shortestPathWithFewestEdges(int n, std::vector<std::vector<pid>>& adj, int s, int t);

        // Implements Bellman-Ford algorithm.
        void bellmanFord(int n, std::vector<Edge>& edges, int source); 

        // Implements Kruskal's algorithm.
        std::vector<Edge> kruskalsAlgorithm(std::vector<Edge>& edges, int numVertices);
};

#endif // GRAPH_H