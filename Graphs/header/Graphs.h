#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>

struct Point 
{
    int x, y;
};

template <typename T>
class Graph 
{
    private:
        int rows;
        int cols;
        std::vector<std::vector<T>>& maze;  // Template-based maze

        // Checks if a point is valid within the maze boundaries.
        bool isValid(int x, int y);

    public:
        // Constructor.
        Graph(std::vector<std::vector<T>>& maze);

        // Breadth-first search to find a path from entrance to exit in the maze.
        std::vector<Point> findPath(Point start, Point end);

        // Depth-First Search to find and flip the region.
        void flipRegion(int x, int y);

        // Compute enclosed regions (optional, if needed).
        void computeEnclosedRegions();

        // Checks if there is a cycle in the adjacent list.
        bool hasCycle();

};

#endif // GRAPH_H

