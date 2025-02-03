#include "../header/Graphs.h"

int main() 
{
    // Find path maze (0 represents open path, 1 represents wall)
    std::vector<std::vector<int>> maze = { 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 1, 1, 0, 1, 1, 1, 0, 1},
        {0, 1, 1, 1, 0, 0, 0, 0, 0, 1},
        {0, 1, 1, 1, 1, 1, 0, 1, 1, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
        {0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 0, 0, 1, 0}
    };

    Graph graph(maze); 

    Point start = {0, 0};
    Point end = {9, 9};

    std::vector<Point> path = graph.findPath(start, end);

    if (path.empty()) 
    {
        std::cout << "No path found!" << std::endl;
    } 
    else {
        std::cout << "Path found:" << std::endl;
        for (const Point& p : path) 
        {
            std::cout << "(" << p.x << ", " << p.y << ") ";
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------------------------------------" << std::endl;
    
    // Flip the color of adjacent.
    std::vector<std::vector<int>> matrix = {
        {0, 0, 1, 1, 1},
        {0, 0, 1, 1, 1},
        {1, 1, 1, 0, 0},
        {1, 1, 1, 0, 0},
        {1, 0, 0, 0, 0}
    };

    Graph flip_color(matrix);
    int x = 0, y = 0; 

    std::cout << "Original Matrix:" << std::endl;
    for (const auto& row : matrix) 
    {
        for (bool val : row) 
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    flip_color.flipRegion(x, y);

    std::cout << "\nMatrix after flipping:" << std::endl;
    for (const auto& row : matrix) 
    {
        for (bool val : row) 
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------------------------------------" << std::endl;
    return 0;
}