#include "../header/Graphs.h"

template <typename T>
Graph<T>::Graph(std::vector<std::vector<T>>& maze) : maze(maze) 
{
    rows = maze.size();
    cols = maze[0].size();
}

template <typename T>
bool Graph<T>::isValid(int x, int y) 
{
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

template <typename T>
std::vector<Point> Graph<T>::findPath(Point start, Point end) 
{
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    std::queue<std::vector<Point>> q;

    q.push({start});
    visited[start.x][start.y] = true;

    while (!q.empty()) 
    {
        std::vector<Point> current_path = q.front();
        q.pop();
        Point last_point = current_path.back();

        if (last_point.x == end.x && last_point.y == end.y) return current_path;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) 
        {
            int nx = last_point.x + dx[i];
            int ny = last_point.y + dy[i];

            if (isValid(nx, ny) && maze[nx][ny] == 0 && !visited[nx][ny]) 
            {
                std::vector<Point> new_path = current_path;
                new_path.push_back({nx, ny});
                q.push(new_path);
                visited[nx][ny] = true;
            }
        }
    }
    return {};
}

template <typename T>
void Graph<T>::flipRegion(int x, int y) 
{
    T target_color = maze[x][y];

    std::function<void(int, int)> dfs = [&](int i, int j) 
    {
        if (!isValid(i, j) || maze[i][j] != target_color) return;

        maze[i][j] = !target_color;

        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
    };
    
    dfs(x, y);
}

template <typename T>
void Graph<T>::computeEnclosedRegions() 
{
    std::vector<std::vector<bool>> reachable(rows, std::vector<bool>(cols, false));
    std::queue<Point> q;

    for (int i = 0; i < rows; ++i) 
    {
        if (maze[i][0] == 'W' && !reachable[i][0]) 
        {
            q.push({i, 0});
            reachable[i][0] = true;
        }
        if (maze[i][cols - 1] == 'W' && !reachable[i][cols - 1]) 
        {
            q.push({i, cols - 1});
            reachable[i][cols - 1] = true;
        }
    }
    
    for (int j = 1; j < cols - 1; ++j) 
    {
        if (maze[0][j] == 'W' && !reachable[0][j]) 
        {
            q.push({0, j});
            reachable[0][j] = true;
        }
        if (maze[rows - 1][j] == 'W' && !reachable[rows - 1][j]) 
        {
            q.push({rows - 1, j});
            reachable[rows - 1][j] = true;
        }
    }

    // BFS to find all reachable 'W' cells:
    while (!q.empty()) 
    {
        Point current_point = q.front();
        q.pop();

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i) 
        {
            int nx = current_point.x + dx[i];
            int ny = current_point.y + dy[i];

            if (isValid(nx, ny) && maze[nx][ny] == 'W' && !reachable[nx][ny]) 
            {
                q.push({nx, ny});
                reachable[nx][ny] = true;
            }
        }
    }

    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            if (maze[i][j] == 'W' && !reachable[i][j]) 
            {
                maze[i][j] = 'B';
            }
        }
    }

}    

template <typename T>
bool Graph<T>::hasCycle()
{
    int num_nodes = maze.size();
    std::vector<int> visited(num_nodes, 0);

    std::function<bool(int)> dfs = [&](int node)
    {
        visited[node] = 1;

        for(int neighbor : maze[node])
        {
            if (visited[neighbor] == 1)
            {
                return true;
            }
            if (visited[neighbor] == 0)
            {
                if (dfs(neighbor))
                {
                    return true;
                }
            }    
        }
        visited[node] = 2;
        return false;
    };

    for (int i = 0; i < num_nodes; i++)
    {
        if (visited[i] == 0)
        {
            if (dfs(i))
            {
                return true;
            }
        }
    }

    return false;
}


template class Graph<int>;
template class Graph<bool>;
template class Graph<char>;