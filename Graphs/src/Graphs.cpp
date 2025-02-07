#include "../header/Graphs.h"

template class Graph<int>;
template class Graph<bool>;
template class Graph<char>;

bool Edge::operator<(const Edge& other) const 
{
    return this->weight < other.weight;
}

template <typename T>
Graph<T>::Graph(std::vector<std::vector<T>>& adjacency_matrix) : adjacency_matrix(adjacency_matrix) 
{
    rows = adjacency_matrix.size();
    cols = adjacency_matrix[0].size();
}

template <typename T>
bool Graph<T>::isValid(int x, int y) 
{
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

template <typename T>
void Graph<T>::printMatrix(const std::vector<std::vector<T>>& matrix) 
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == INT_MAX)
            {
                std::cout << "INF ";
            }
            else {
                std::cout << matrix[i][j] << "  ";
            }
        }
        std::cout << std::endl;
    }
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

            if (isValid(nx, ny) && adjacency_matrix[nx][ny] == 0 && !visited[nx][ny]) 
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
    T target_color = adjacency_matrix[x][y];

    std::function<void(int, int)> dfs = [&](int i, int j) 
    {
        if (!isValid(i, j) || adjacency_matrix[i][j] != target_color) return;

        adjacency_matrix[i][j] = !target_color;

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

    for (int i = 0; i < rows; i++)
    {
        if (adjacency_matrix[i][0] == 'W' && !reachable[i][0])
        {
            q.push({i, 0});
            reachable[i][0] = true;
        }
        if (adjacency_matrix[i][cols - 1] == 'W' && !reachable[i][cols - 1])
        {
            q.push({i, cols - 1});
            reachable[i][cols - 1] = true;
        }        
    }
    
    for (int j = 0; j < cols; j++)
    {
        if (adjacency_matrix[0][j] == 'W' && !reachable[0][j])
        {
            q.push({0, j});
            reachable[0][j] = true;
        }
        if (adjacency_matrix[rows - 1][j] == 'W' && !reachable[rows - 1][j])
        {
            q.push({rows - 1, j});
            reachable[rows - 1][j] = true;
        }
    }

    // BFS to find all reachable cells.
    while (!q.empty())
    {
        Point current_point = q.front();
        q.pop();

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++)
        {
            int nx = current_point.x + dx[i];
            int ny = current_point.y + dy[i];

            if (isValid(nx, ny) && adjacency_matrix[nx][ny] == 'W' && !reachable[nx][ny])
            {
                q.push({nx, ny});
                reachable[nx][ny] = true;
            }
        }
    }
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (adjacency_matrix[i][j] == 'W' && !reachable[i][j])
            {
                adjacency_matrix[i][j] = 'B';
            }
        }
    }
}    

template <typename T>
bool Graph<T>::hasCycle()
{
    int num_nodes = adjacency_matrix.size();
    std::vector<int> visited(num_nodes, 0);

    std::function<bool(int)> dfs = [&](int node)
    {
        visited[node] = 1;
        for(int neighbor : adjacency_matrix[node])
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

template <typename T>
bool Graph<T>::isBipartite() 
{
    int n = adjacency_matrix.size();
    std::vector<int> color(n, -1); // -1; uncolored, 0 or 1; colored.
    
    for (int  start_node = 0; start_node < n; start_node++)
    {
        if (color[start_node == -1])
        {
            std::queue<int> q;
            q.push(start_node);
            color[start_node] = 0;
            
            while (!q.empty())
            {
                int u = q.front();
                q.pop();

                for (int v : adjacency_matrix[u])
                {
                    if (color[v] == -1)
                    {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    else if(color[v] == color[u])
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

template <typename T>
int Graph<T>::maxTeams() 
{
    for (auto& team : adjacency_matrix)
    {
        sort(team.begin(), team.end());
    }

    sort(adjacency_matrix.begin(), adjacency_matrix.end(), [](const std::vector<T>& a, const std::vector<T>& b)
    {
        return a.back() < b.back();
    });
    
    int max_team_count = 0;
    std::vector<T> last_row;

    for(const auto& team : adjacency_matrix)
    {
        bool can_add = true;
        for (size_t i = 0; i < team.size(); i++)
        {
            if (!last_row.empty() && team[i] <= last_row[i])
            {
                can_add = false;
                break;
            }
        }
        if (can_add)
        {
            last_row = team;
            max_team_count++;
        }
    }

    return max_team_count;
}

template <typename T>
void Graph<T>::floydWarshall() 
{
    for (int k = 0; k < rows; k++)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (adjacency_matrix[i][k] != INT_MAX && adjacency_matrix[k][j] != INT_MAX &&
                    adjacency_matrix[i][j] > adjacency_matrix[i][k] + adjacency_matrix[k][j])
                {
                    adjacency_matrix[i][j] = adjacency_matrix[i][k] + adjacency_matrix[k][j];
                }
            }
        }
    }
    for (int i = 0; i < rows; i++)
    {
        if (adjacency_matrix[i][i] < 0)
        {
            std::cout << "Graph contains a negative weoghted cycle!" << std::endl;
            return;
        }
    }
}


Vertex* GraphBase::cloneGraph(Vertex* u, std::unordered_map<Vertex*, Vertex*>& visited) 
{
    if (u == nullptr) return nullptr;

    if(visited.count(u)) return visited[u];

    Vertex* u_copy = new Vertex;
    u_copy->label = u->label;

    visited[u] = u_copy;

    for (Vertex* neighbor : u->neighbors)
    {
        u_copy->neighbors.push_back(cloneGraph(neighbor, visited));
    }
    
    return u_copy;
}

bool GraphBase::differByOne(const std::string& a, const std::string& b) 
{
    if (a.length() != b.length()) return false;

    int diff_count = 0;

    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
        {
            diff_count++;
        }
    }
    return diff_count == 1;
}

int GraphBase::shortestProductionSequence(const std::string& s, const std::string& t, const std::unordered_set<std::string>& dict)
{
    if(s == t) return 0;

    std::queue<std::pair<std::string, int>> q;
    q.push({s, 1});

    std::unordered_set<std::string> visited;
    visited.insert(s);

    while (!q.empty())
    {
        std::string current = q.front().first;
        int length = q.front().second;
        q.pop();

        for (const std::string& next : dict)
        {
            if (differByOne(current, next) && visited.find(next) == visited.end())
            {
                if (next == t)
                {
                    return length + 1;
                }
                q.push({next, length + 1});
                visited.insert(next);
            }
        }
    }
    return -1;
}

std::vector<int> GraphBase::shortestPathWithFewestEdges(int n, std::vector<std::vector<std::pair<int, double>>>& adj, int s, int t)
{
    // modify edge costs: c'(e) = c(e) + EPSILON
    for (int i = 0; i < n; i++)
    {
        for (auto& edge : adj[i])
        {
            edge.second += EPSILON; 
        }
    }
    
    // Dijkstra's Algorithm.
    std::vector<double> dist(n, INF);
    std::vector<int> parent(n, -1);
    std::priority_queue<pdi, std::vector<pdi>, std::greater<pdi>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        double d = pq.top().first;
        pq.pop();

        if (u == t) break;
        if (d > dist[u]) continue;
        
        for (auto& edge : adj[u])
        {
            int v = edge.first;
            double w = edge.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }        
    }
    
    std::vector<int> path;
    if (dist[t] == INF)
    {
        return path;
    }

    for (int v = t; v != -1; v = parent[v])
    {
        path.push_back(v);
    }

    reverse(path.begin(), path.end());
    return path;
}

void GraphBase::bellmanFord(int n, std::vector<Edge>& edges, int source) 
{
    std::vector<int> distance(n, INT_MAX);
    distance[source] = 0;

    for (int i = 0; i <= n - 1; i++)
    {
        for(const auto& edge : edges)
        {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;

            if (distance[u] != INT_MAX && distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w; 
            }
        }
    }

    // Check for negative cycles.
    for (const auto& edge : edges)
    {
        int u = edge.source;
        int v = edge.destination;
        int w = edge.weight;

        if (distance[u] != INT_MAX && distance[u] + w < distance[v])
        {
            std::cout << "Graph contains a negative weight cycle!" << std::endl;
            return;
        }
    }

    std::cout << "Vertex\tDistance from source" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << i <<"\t" << distance[i] << std::endl;
    }
}

int GraphBase::findParent(std::vector<int>& parent, int i) 
{
    if(parent[i] == i) return i;

    return findParent(parent, parent[i]); 
}

void GraphBase::unionSets(std::vector<int>& parent, std::vector<int>& rank, int i, int j) 
{
    int i_id = findParent(parent, i);
    int j_id = findParent(parent, j);

    if (i_id != j_id)
    {
        if (rank[i_id] > rank[j_id])
        {
            parent[j_id] = i_id;
        }
        if (rank[i_id] < rank[j_id])
        {
            parent[i_id] = j_id;
        }
        else{
            parent[j_id] = i_id;
            rank[i_id]++;
        }
    }
}

std::vector<Edge> GraphBase::kruskalsAlgorithm(std::vector<Edge>& edges, int num_vertices) 
{
    std::vector<Edge> result;

    sort(edges.begin(), edges.end());

    std::vector<int> parent(num_vertices);
    std::vector<int> rank(num_vertices, 0);

    for (int i = 0; i < num_vertices; i++)
    {
        parent[i] = i;
    }

    // Iterate through sorted edges and add to MST if it doesn't create a cycle
    for (const auto& edge : edges)
    {
        int source_parent = findParent(parent, edge.source);
        int dest_parent = findParent(parent, edge.destination);

        if (source_parent != dest_parent)
        {
            result.push_back(edge);
            unionSets(parent, rank, edge.source, edge.destination);
        }
    }
    
    return result;
}