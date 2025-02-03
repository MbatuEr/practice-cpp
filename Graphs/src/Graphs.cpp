#include "../header/Graphs.h"

Graph::Graph(std::vector<std::vector<int>>& maze) : maze(maze)
{
    rows = maze.size();
    cols = maze[0].size();
}

bool Graph::isValid(int x, int y)
{   
    return x >= 0 && x < rows && y >= 0 && y < cols; 
}

std::vector<Point> Graph::findPath(Point start, Point end)
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

        if(last_point.x == end.x && last_point.y == end.y) return current_path;

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

void Graph::flipRegion(int x, int y)
{
    if (!isValid(x, y)) return;
    bool target_color = maze[x][y];

    std::function<void(int, int)> dfs = [&](int i, int j)
    {
        if (!isValid(i, j) || maze[i][j] != target_color) return; // THEN check color

        maze[i][j] = !target_color;

        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
    };
    dfs(x,y);
}