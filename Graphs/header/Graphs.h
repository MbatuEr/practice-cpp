// Graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <functional> 

struct Point 
{
    int x, y;
};

class Graph 
{
    private:
        int rows;
        int cols;
        std::vector<std::vector<int>>& maze; 

        // Checks if a point is valid within the maze boundaries.
        bool isValid(int x, int y);
    
    public:
        // Constructor.
        Graph(std::vector<std::vector<int>>& maze);

        // Bread-first search to find a path from entrance to exit in the maze.
        std::vector<Point> findPath(Point start, Point end);

        // Depth-First Search to find and flip the region.
        void flipRegion(int x, int y);
};

#endif // GRAPH_H