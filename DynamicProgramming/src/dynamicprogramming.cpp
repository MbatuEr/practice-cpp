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
    for (int i = 1; i < n; i++)
    {
        std::vector<int> current_row(n, 1);
        for (int j = 1; j < n; j++)
        {
            current_row[j] = current_row[j - 1] + prev_row[j];
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

int Dp::binomialCoefficient(int n, int k)
{
    std::vector<std::vector<int>> x_choose_y(n + 1, std::vector<int>(k + 1, 0));
    return computeXChooseY(n, k, x_choose_y);
}

bool Dp::findPattern(const std::vector<std::vector<int>>& grid, const std::vector<int>& pattern)
{
    int rows = grid.size();
    if (rows == 0) return pattern.empty();
    int cols = grid[0].size();
    
    std::vector<std::vector<std::vector<int>>> dp(rows, 
                std::vector<std::vector<int>>(cols, std::vector<int>(pattern.size(), -1)));

    std::function<bool(int, int, int)> dfs = [&](int row, int col, int pattern_index) 
    {
        if (pattern_index == pattern.size()) return true;

        if (row < 0 || row >= rows || col < 0 || col >= cols || 
            grid[row][col] != pattern[pattern_index]) 
        {
            return false;
        }

        if (dp[row][col][pattern_index] != -1) 
        {
            return dp[row][col][pattern_index] == 1;
        }
        
        int temp = grid[row][col];
        const_cast<std::vector<std::vector<int>>&>(grid)[row][col] = -1;

        bool found = dfs(row + 1, col, pattern_index + 1) ||
                     dfs(row - 1, col, pattern_index + 1) ||
                     dfs(row, col + 1, pattern_index + 1) ||
                     dfs(row, col - 1, pattern_index + 1);

        const_cast<std::vector<std::vector<int>>&>(grid)[row][col] = temp; 
        dp[row][col][pattern_index] = found;
        return found;
    };

    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            if (dfs(i, j, 0)) return true;
        }
    }

    return false;
}

int Dp::knapsack(int cap, const std::vector<int>& weights, const std::vector<int>& values)
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
        if (dictionary.find(domain.substr(0, i + 1)) != dictionary.end())
        {
            last_length[i] = i + 1;
        }

        if (last_length[i] == -1)
        {
            for (int j = 0; j < i; j++)
            {
                if (dictionary.find(domain.substr(j + 1, i - j)) != dictionary.end())
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

int Dp::minimumPathWeight(const std::vector<std::vector<int>>& triangle)
{
    if (triangle.empty()) return 0;

    std::vector<int> prev_row(triangle.front());
    for (int i = 1; i < triangle.size(); i++)
    {
        std::vector<int> current_row(triangle[i]);
        current_row[0] += prev_row[0];
        for (int j = 1; j < triangle.size(); j++)
        {
            current_row[j] += std::min(prev_row[j - 1], prev_row[j]);
        }
        current_row.back() += prev_row.back();
        prev_row = current_row;
    }

    return *std::min_element(prev_row.begin(), prev_row.end());
}

int Dp::computeMaximumRevenueForRange(const std::vector<int>& coins, int a, int b,
                                      std::vector<std::vector<int>>& max_revenue_for_range)
{
    if(a > b) return 0;

    if (max_revenue_for_range[a][b] == 0)
    {
        int max_revenue_a = coins[a] + 
        std::min(computeMaximumRevenueForRange(coins, a + 1, b - 1, max_revenue_for_range),
                 computeMaximumRevenueForRange(coins, a + 2, b, max_revenue_for_range));

        int max_revenue_b = coins[b] + 
        std::min(computeMaximumRevenueForRange(coins, a + 1, b - 1, max_revenue_for_range),
                 computeMaximumRevenueForRange(coins, a, b - 2, max_revenue_for_range));

        max_revenue_for_range[a][b] = std::max(max_revenue_a, max_revenue_b);
    }

    return max_revenue_for_range[a][b];
}

int Dp::maximumRevenue(const std::vector<int>& coins)
{
    std::vector<std::vector<int>> max_revenue_for_range(coins.size(), 
                                    std::vector<int>(coins.size(), 0));
    return computeMaximumRevenueForRange(coins, 0, coins.size() - 1, max_revenue_for_range);
}

int Dp::minimumMessiness(const std::vector<std::string>& words, int line_length)
{
    std::vector<int> min_messiness(words.size(), std::numeric_limits<int>::max());
    int num_remaining_blanks = line_length - words[0].size();
    min_messiness[0] = num_remaining_blanks * num_remaining_blanks;

    for (int i = 1; i < words.size(); i++)
    {
        num_remaining_blanks = line_length - words[i].size();
        min_messiness[i] = min_messiness[i - 1] + 
                           num_remaining_blanks * num_remaining_blanks;

        for (int j = i - 1; j >= 0; j--)
        {
            num_remaining_blanks -= words[j].size() + 1;
            if (num_remaining_blanks < 0)
            {
                break;
            }
            
            int first_j_messiness = j - 1 < 0 ? 0 : min_messiness[j - 1];
            int current_line_messiness = num_remaining_blanks * num_remaining_blanks;

            min_messiness[i] = std::min(min_messiness[i], 
                                        first_j_messiness + current_line_messiness);
        }        
    }
    return min_messiness.back();
}

int Dp::longestNondecreasingSubsequenceLength(const std::vector<int>& A)
{
    std::vector<int> max_length(A.size(), 1);
    for (int i = 1; i < A.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[i] >= A[j])
            {
                max_length[i] = std::max(max_length[i], max_length[j] + 1);
            }            
        }        
    }
    return *std::max_element(max_length.begin(), max_length.end());
}