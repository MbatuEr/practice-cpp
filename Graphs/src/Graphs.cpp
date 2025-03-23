#include "../header/Graphs.h"

template class Graph<int>;
template class Graph<bool>;
template class Graph<char>;

bool Edge::operator<(const Edge& other) const 
{
    return this->weight < other.weight;
}

template <typename T>
Graph<T>::Graph(std::vector<std::vector<T>>& adjacency_matrix) : 
                                            adjacency_matrix(adjacency_matrix)
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
void Graph<T>::flipRegion(int x, int y)
{
    T target_color = adjacency_matrix[x][y];

    // Lambda function for DFS traversal
    std::function<void(int, int)> dfs = [&](int i, int j)
    {
        if (!isValid(i, j) || adjacency_matrix[i][j] != target_color) return;

        adjacency_matrix[i][j] = !target_color;

        // Explore all four directions
        dfs(i - 1, j);   // Down
        dfs(i + 1, j);   // Up 
        dfs(i, j - 1);   // Right
        dfs(i, j + 1);   // Left
    };

    dfs(x,y);
}

template <typename T>
void Graph<T>::computeEnclosedRegions() 
{
    if(rows == 0 || cols == 0) return;

    // Lambda function for DFS traversal
    std::function<void(int, int)> dfs = [&] (int x, int y)
    {
        if(!isValid(x, y) || adjacency_matrix[x][y] != 'W') return;

        // Mark as temporary to indicate it is connected to the border
        adjacency_matrix[x][y] = 'T';

        // Explore all four directions
        dfs(x - 1, y); // Up
        dfs(x + 1, y); // Down
        dfs(x, y - 1); // Left
        dfs(x, y + 1); // Right
    };

    for (int i = 0; i < rows; i++)
    {
        if (adjacency_matrix[i][0] == 'W') dfs(i, 0);
        if(adjacency_matrix[i][cols- 1] == 'W') dfs(i, cols - 1);        
    }

    for (int j = 0; j < cols; j++)
    {
        if (adjacency_matrix[0][j] == 'W') dfs(0, j);
        if(adjacency_matrix[rows - 1][j] == 'W') dfs(rows - 1, j);        
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (adjacency_matrix[i][j] == 'W')
            {
                adjacency_matrix[i][j] = 'B';
            }
            else if (adjacency_matrix[i][j] == 'T')
            {
                adjacency_matrix[i][j] = 'W';
            }           
        }       
    }    
}    

template <typename T>
bool Graph<T>::hasCycle()
{
    std::vector<int> visited(rows, 0);

    std::function<bool(int)> dfs = [&](int node)
    {
        visited[node] = 1;
        for (int neighbor : adjacency_matrix[node])
        {
            if (visited[neighbor] == 1) return true;
            if (visited[neighbor] == 0)
            {
                if(dfs(neighbor)) return true;
            }            
        }
        visited[node] = 2;
        return false;
    };

    for (int i = 0; i < rows; i++)
    {
        if (visited[i] == 0)
        {
            if (dfs(i)) return true;
        }
    }
    return false;
}

template <typename T>
bool Graph<T>::isBipartite() 
{
    std::vector<int> color(rows, -1);

    std::function<bool(int, int)> dfs = [&](int u, int c)
    {
        color[u] = c;
        for (int v : adjacency_matrix[u])
        {
            if (color[v] == -1)
            {
                if(!dfs(v, 1 - c)) return false;
            }
            else if (color[v] == color[u])
            {
                return false;
            }            
        }
        return true;
    };

    for (int start_node = 0; start_node < rows; start_node++)
    {
        if (color[start_node] == -1 && !dfs(start_node, 0))
        {
            return false;
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

    sort(adjacency_matrix.begin(), adjacency_matrix.end(), []
                                    (const std::vector<T>& a, const std::vector<T>& b)
    {
        return a.back() < b.back();
    });

    int max_team_count = 0;
    std::vector<T> last_row;

    for (const auto& team : adjacency_matrix)
    {
        bool can_add = true;
        for (size_t i = 0; i < cols; i++)
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
            std::cout << "Graph contains a negative weighted cycle!" << std::endl;
            return;
        }
    }
}


Vertex* GraphBase::cloneGraph(Vertex* u, std::unordered_map<Vertex*, Vertex*>& visited) 
{
    if (u == nullptr) return nullptr;

    if (visited.count(u)) return visited[u];

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

int GraphBase::shortestProductionSequence(const std::string& s, const std::string& t,
                                          const std::unordered_set<std::string>& dict)
{
    if (s == t) return 0;

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

std::vector<int> GraphBase::shortestPathWithFewestEdges(int n, 
    std::vector<std::vector<pid>>& adj, int s, int t)
{
    // modify edge costs: c'(e) = c(e) + EPSILON
    for (int i = 0; i < n; i++)
    {
        for (auto& edge : adj[i])
        {
            edge.second += EPSILON; 
        }
    }
    
    // Dijkstra's Algorithm
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
        for (const auto& edge : edges)
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

    for (const auto& edge : edges)
    {
        int u = edge.source;
        int v = edge.destination;
        int w = edge.weight;

        if (distance[u] != INT_MAX && distance[u] + w < distance[v])
        {
            std::cout << "Graph contain a negative weighted cycle!" << std::endl;
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
        else if (rank[i_id] < rank[j_id])
        {
            parent[i_id] = j_id;
        }
        else {
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