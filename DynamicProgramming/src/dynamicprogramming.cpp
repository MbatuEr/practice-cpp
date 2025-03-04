#include "../header/dynamicprogramming.h"

int Dp::numberOfScoreCombinations(int final_score, const std::vector<int>& scores)
{
    std::vector<int> combinations(final_score + 1, 0);
    combinations[0] = 1;

    for (int score : scores)
    {
        for (int i = score; i <= final_score; i++)
        {
            combinations[i] += combinations[i - score];
        }
    }
    return combinations[final_score];
}

int Dp::levenshteinDistance(const std::string& s1, const std::string& s2)
{
    int len1 = s1.size(), len2 = s2.size();
    std::vector<int> prev_row(len2 + 1, 0);
    
    for (int j = 0; j <= len2; ++j) 
    {
        prev_row[j] = j;  
    }

    for (int i = 1; i <= len1; ++i) 
    {
        std::vector<int> current_row(len2 + 1, 0);
        current_row[0] = i;  

        for (int j = 1; j <= len2; ++j) 
        {
            if (s1[i - 1] == s2[j - 1]) 
            {
                current_row[j] = prev_row[j - 1];
            } 
            else {
                current_row[j] = 1 + std::min({prev_row[j],      // Deletion
                                              current_row[j - 1], // Insertion
                                              prev_row[j - 1]});  // Substitution
            }
        }
        prev_row = current_row;
    }

    return prev_row[len2];
}

int Dp::traversing2DArray(int n)
{
    std::vector<int> prev_row(n, 1);
    for(int i = 1; i < n; i++)
    {
        std::vector<int> current_row(n, 1);
        for (int j = 1; j < n; j++)
        {
            current_row[j] = prev_row[j] + current_row[j - 1];
        }
        prev_row = current_row;
    }
    
    return prev_row[n - 1];
}

int Dp::computeXChooseY(int x, int y, std::vector<std::vector<int>>& x_choose_y)
{
    if (y == 0 || y == x)
    {
        return 1;
    }

    if (x_choose_y[x][y] == 0)
    {
        int without_y = computeXChooseY(x - 1, y, x_choose_y);
        int with_y = computeXChooseY(x - 1, y - 1, x_choose_y);
        x_choose_y[x][y] = with_y + without_y;
    }
    
    return x_choose_y[x][y];
}

int Dp::binomial_coefficient(int n, int k)
{
    std::vector<std::vector<int>> x_choose_y(n + 1, std::vector<int>(k + 1, 0));
    return computeXChooseY(n, k, x_choose_y);
}

bool Dp::findPattern(const std::vector<std::vector<int>>& grid, const std::vector<int>& pattern) 
{
    int rows = grid.size();
    if (rows == 0) return pattern.empty();
    int cols = grid[0].size();

    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    
    std::vector<std::vector<std::vector<int>>> dp(rows, 
                std::vector<std::vector<int>>(cols, std::vector<int>(pattern.size(), -1)));

    std::function<bool(int, int, int)> search = [&](int row, int col, int pattern_index) 
    {
        if (pattern_index == pattern.size()) return true;

        if (row < 0 || row >= rows || col < 0 || col >= cols || 
            visited[row][col] || grid[row][col] != pattern[pattern_index]) 
        {
            return false;
        }

        if (dp[row][col][pattern_index] != -1) return dp[row][col][pattern_index] == 1;

        visited[row][col] = true;

        bool found = search(row + 1, col, pattern_index + 1) ||
                     search(row - 1, col, pattern_index + 1) ||
                     search(row, col + 1, pattern_index + 1) ||
                     search(row, col - 1, pattern_index + 1);

        visited[row][col] = false;
        dp[row][col][pattern_index] = found;
        return found;
    };

    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            if (search(i, j, 0)) return true;
        }
    }

    return false;
}    

int Dp::knapsack(int cap, std::vector<int> weights, std::vector<int> values)
{
    int n = values.size();
    std::vector<int> prev_row(cap + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        std::vector<int> current_row(cap + 1, 0);
        for (int c = 1; c < cap + 1; c++)
        {
            if (weights[i] <= c)
            {
                current_row[c] = std::max(values[i] + prev_row[c - weights[i]], prev_row[c]);
            }
            else {
                current_row[c] = prev_row[c];
            }
        }
        prev_row = current_row;
    }
    return prev_row[cap];
}

std::vector<std::string> Dp::decomposeIntoDictionaryWords(
    const std::string& domain, const std::unordered_set<std::string>& dictionary)
{
    std::vector<int> last_length(domain.size(), -1);
    for (int i = 0; i < domain.size(); i++)
    {
        if (dictionary.find(domain.substr(0, i + 1)) != dictionary.cend())
        {
            last_length[i] = i + 1;
        }
        if (last_length[i] == -1)
        {
            for (int j = 0; j < i; j++)
            {
                if (last_length[j] != -1 && 
                    dictionary.find(domain.substr(j + 1, i - j)) != dictionary.cend())
                {
                    last_length[i] = i - j;
                    break;
                }                
            }            
        }        
    }
    
    std::vector<std::string> decompositions;
    if (last_length.back() != -1)
    {
        int idx = domain.size() - 1;
    
        while (idx >= 0)
        {
            decompositions.emplace_back(
                domain.substr(idx + 1 - last_length[idx], last_length[idx]));
            idx -= last_length[idx];
        }
        std::reverse(decompositions.begin(), decompositions.end());
    }

    return decompositions;  
}
