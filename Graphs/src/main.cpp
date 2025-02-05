#include "../header/Graphs.h"


int main() 
{
    // Find shortest path between two nodes.
    std::vector<std::vector<int>> maze = {  // maze (0 represents open path, 1 represents wall)
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

    Graph<int> graph(maze);

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
    }
    std::cout << "\n-----------------------------------------------" << std::endl;

    // Flip the color of adjacent.
    std::vector<std::vector<bool>> matrix = {
        {0, 0, 1, 1, 1},
        {0, 0, 1, 1, 1},
        {1, 1, 1, 0, 0},
        {1, 1, 1, 0, 0},
        {1, 0, 0, 0, 0}
    };

    Graph<bool> flip_color(matrix);
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

    // Compute the enclosed region.
    std::vector<std::vector<char>> enclosed_region = {
        {'B','B','B','B'},
        {'W','B','W','B'},
        {'B','W','W','B'},
        {'B','B','B','B'}
    };

    Graph<char> enclosed(enclosed_region);
    
        std::cout << "Original Matrix:" << std::endl;
    for (const auto& row : enclosed_region) 
    {
        for (char c : row) 
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }

    enclosed.computeEnclosedRegions();

    std::cout << "\nMatrix after flipping:" << std::endl;
    for (const auto& row : enclosed_region) 
    {
        for (char c : row) 
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------------------------------------" << std::endl;
    
    // Detect loop.
    std::vector<std::vector<int>> graph1 = { // (adjacency list representation)
        {1},        // Node 0 -> 1
        {2},        // Node 1 -> 2
        {3, 1},     // Node 2 -> 0, 3
        {}         // Node 3 -> 3 (self-loop)
    };
    Graph<int> loop_check1(graph1);

    if (loop_check1.hasCycle()) 
    {
        std::cout << "Graph contains a cycle (potential deadlock)." << std::endl;
    } 
    else {
        std::cout << "Graph does not contain a cycle." << std::endl;
    }

    std::vector<std::vector<int>> graph2 = {
        {1},
        {2},
        {3},
        {}
    };

    Graph loop_check2(graph2);
    if (loop_check2.hasCycle()) 
    {
        std::cout << "Graph 2 contains a cycle (potential deadlock)." << std::endl;
    } 
    else {
        std::cout << "Graph 2 does not contain a cycle." << std::endl;
    }
    std::cout << "-----------------------------------------------" << std::endl;
    
    // Example graph construction:
    GraphBase base;
    Vertex* v1 = new Vertex;
    v1->label = 1;
    Vertex* v2 = new Vertex;
    v2->label = 2;
    Vertex* v3 = new Vertex;
    v3->label = 3;
    Vertex* v4 = new Vertex;
    v4->label = 4;

    v1->neighbors = {v2, v4};
    v2->neighbors = {v3};
    v4->neighbors = {v3};

    // Clone the graph starting from v1:
    std::unordered_map<Vertex*, Vertex*> visited;
    Vertex* v1_copy = base.cloneGraph(v1, visited);

    std::cout << "Cloned graph labels:" << std::endl;
    std::cout << v1_copy->label << " ";
    for (Vertex* neighbor : v1_copy->neighbors) 
    {
        std::cout << neighbor->label << " ";
    }
    std::cout << "\n-----------------------------------------------" << std::endl;

    // Bipartite list.
    std::vector<std::vector<int>> adj1 = { // Example graph (adjacency list) - Bipartite
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2}
    };

    std::vector<std::vector<int>> adj2 = { // Example graph (adjacency list) - Not Bipartite
        {1, 2},
        {0, 2},
        {0, 1}
    };
    
    Graph<int> bipart1(adj1);
    if (bipart1.isBipartite()) 
    {
        std::cout << "Graph 1 is bipartite." << std::endl;
    } 
    else {
        std::cout << "Graph 1 is not bipartite." << std::endl;
    }
    
    Graph<int> bipart2(adj2);
    if (bipart2.isBipartite()) 
    {
        std::cout << "Graph 2 is bipartite." << std::endl;
    } 
    else {
        std::cout << "Graph 2 is not bipartite." << std::endl;
    }
    std::cout << "-----------------------------------------------" << std::endl;

    // Shortest production sequence. 
    GraphBase shortest_sequence;
    std::unordered_set<std::string> d = {"bat", "cot", "dog", "dag", "dot", "cat"};
    std::string s = "cat";
    std::string t = "dog";

    int length = shortest_sequence.shortestProductionSequence(s, t, d);

    if (length != -1) 
    {
        std::cout << "Length of shortest production sequence: " << length << std::endl;
    } 
    else {
        std::cout << "No production sequence found." << std::endl;
    }
    std::cout << "-----------------------------------------------" << std::endl;
    return 0;
}