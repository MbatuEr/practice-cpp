#include "../header/Recursion.h"

Tree::Tree(int x) : val(x), left(NULL), right(NULL) {}

void Recursion::towerOfHanoi(int n, char source, char destination, char auxiliary) 
{
    if (n == 1)
    {
        std::cout << "Move disk 1 from " << source << "to " << destination << std::endl;
        return;
    }

    towerOfHanoi(n - 1, source, auxiliary, destination);
    std::cout << "Move disk " << n << " from " << source << " to " << destination << std::endl;
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

bool Recursion::isSafe(const std::vector<int>& placement, int row, int col) 
{
    for (int i = 0; i < row; i++)
    {
        if (placement[i] == col)
        {
            return false;
        }
        if (abs(placement[i] - col) == abs(i - row))
        {
            return false;
        }
    }
    return true;
}

void Recursion::solveNQueensUtil(int n, int row, std::vector<int>& placement, std::vector<std::vector<std::string>>& solutions) 
{
    if (row == n)
    {
        std::vector<std::string> board(n, std::string(n, '.'));
        for (int i = 0; i < n; i++)
        {
            board[i][placement[i]] = 'Q';
        }
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(placement, row, col))
        {
            placement[row] = col;
            solveNQueensUtil(n, row + 1, placement, solutions);
        }
    } 
}

std::vector<std::vector<std::string>> Recursion::solveNQueens(int n) 
{
    std::vector<std::vector<std::string>> solutions;
    std::vector<int> placement(n);
    solveNQueensUtil(n, 0, placement, solutions);
    return solutions;
}

void Recursion::generatePermutationsRecursive(std::vector<int> arr, int n, std::vector<std::vector<int>>& result) 
{
    if (n == 1)
    {
        result.push_back(arr);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        std::swap(arr[i], arr[n - 1]);
        generatePermutationsRecursive(arr, n - 1, result);
        std::swap(arr[i], arr[n - 1]);
    }
}

std::vector<std::vector<int>> Recursion::generatePermutations(std::vector<int> arr) 
{
    std::vector<std::vector<int>> result;
    generatePermutationsRecursive(arr, arr.size(), result);
    std::sort(result.begin(), result.end());
    return result;
}

void Recursion::generatePowerSetRecursive(const std::vector<int>& set, int index, std::vector<int> current_subset, std::vector<std::vector<int>>& power_set) 
{
    if (index == set.size())
    {
        power_set.push_back(current_subset);
        return;
    }

    generatePowerSetRecursive(set, index + 1, current_subset, power_set);
    current_subset.push_back(set[index]);
    generatePowerSetRecursive(set, index + 1, current_subset, power_set);
}

std::vector<std::vector<int>> Recursion::generatePowerSet(const std::vector<int>& set) 
{
    std::vector<std::vector<int>> power_set;
    std::vector<int> current_subset;
    generatePowerSetRecursive(set, 0, current_subset, power_set);
    return power_set;
}

void Recursion::generateSubsetsOfSizeKRecursive(int n, int k, int start, std::vector<int>& current_subset, std::vector<std::vector<int>>& result) 
{
    if (current_subset.size() == k)
    {
        result.push_back(current_subset);
        return;
    }

    if (start > n)
    {
        return;
    }
    
    generateSubsetsOfSizeKRecursive(n, k, start + 1, current_subset, result);
    current_subset.push_back(start);
    generateSubsetsOfSizeKRecursive(n, k, start + 1, current_subset, result);
    current_subset.pop_back();
}

std::vector<std::vector<int>> Recursion::generateSubsetsOfSizeK(int n, int k) 
{
    std::vector<std::vector<int>> result;
    std::vector<int> current_subset;

    generateSubsetsOfSizeKRecursive(n, k, 1, current_subset, result);
    reverse(result.begin(), result.end());

    return result;
}

void Recursion::generateParenthesesRecursive(int n, int open, int close, std::string current, std::vector<std::string>& result) 
{
    if (open == n && close == n)
    {
        result.push_back(current);
        return;
    }

    if (open < n)
    {
        generateParenthesesRecursive(n, open + 1, close, current + "(", result);
    }
    
    if (close < open)
    {
        generateParenthesesRecursive(n, open, close + 1, current + ")", result);
    }
}

std::vector<std::string> Recursion::generateParentheses(int n) 
{
    std::vector<std::string> result;
    generateParenthesesRecursive(n, 0, 0, "", result);
    return result;
}

bool Recursion::isPalindrome(const std::string& str) 
{
    std::string reversed_str = str;
    reverse(reversed_str.begin(), reversed_str.end());
    return str == reversed_str;   
}

void Recursion::generatePalindromicDecompositionsRecursive(const std::string& s, int index, std::vector<std::string>& current_decomposition, std::vector<std::vector<std::string>>& result)
{
    if (index == s.length())
    {
        result.push_back(current_decomposition);
        return;
    }

    for (int i = index; i < s.length(); i++)
    {
        std::string prefix = s.substr(index, i - index + 1);
        if (isPalindrome(prefix))
        {
            current_decomposition.push_back(prefix);
            generatePalindromicDecompositionsRecursive(s, i + 1, current_decomposition, result);
            current_decomposition.pop_back();
        }
    }
}

std::vector<std::vector<std::string>> Recursion::generatePalindromicDecompositions(const std::string& s) 
{
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> current_decompositions;
    generatePalindromicDecompositionsRecursive(s, 0, current_decompositions, result);
    return result;
}

std::vector<Tree*> Recursion::generateTreesHelper(int start, int end) 
{
    std::vector<Tree*> result;
    if (start > end) 
    {
        result.push_back(NULL);
        return result;
    }
    
    std::map<std::pair<int, int>, std::vector<Tree*>> mem;
    auto key = std::make_pair(start, end);
    
    if (mem.find(key) != mem.end()) 
    {
        return mem[key];
    }

    for (int i = start; i <= end; i++) 
    {
        std::vector<Tree*> leftSubtrees = generateTreesHelper(start, i - 1);
        std::vector<Tree*> rightSubtrees = generateTreesHelper(i + 1, end);
        
        for (Tree* left : leftSubtrees) 
        {
            for (Tree* right : rightSubtrees) 
            {
                Tree* root = new Tree(i);
                root->left = left;
                root->right = right;
                result.push_back(root);
            }
        }
    }

    mem[key] = result;
    return result;
}

std::vector<Tree*> Recursion::generateTrees(int n) 
{
    if (n == 0) 
    {
        return std::vector<Tree*>();
    }

    return generateTreesHelper(1, n);
}

void Recursion::printTree(Tree* root) 
{
    if (root == NULL) 
    {
        std::cout << "NULL";
        return;
    }

    std::queue<Tree*> q;
    q.push(root);

    while (!q.empty()) 
    {
        int level_size = q.size();
        for (int i = 0; i < level_size; i++) 
        {
            Tree* node = q.front();
            q.pop();
            if (node == NULL) 
            {
                std::cout << "NULL ";
            } 
            else {
                std::cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            }
        }
        std::cout << std::endl;
    }
}

bool Recursion::isValid(const std::vector<std::vector<int>>& board, int row, int col, int num)
{
    for (int j = 0; j < board[0].size(); j++)
    {
        if(board[row][j] == num) return false; 
    }

    for (int i = 0; i < board.size(); i++)
    {
        if(board[i][col] == num) return false; 
    }
    
    int block_row_start = row - row % 3;
    int block_col_start = col - col % 3;

    for (int i = block_row_start; i < block_row_start + 3; i++)
    {
        for (int j = block_col_start; j < block_col_start + 3; j++)
        {
            if(board[i][j] == num) return false;
        }
    }

    return true;
}

bool Recursion::solveSudoku(std::vector<std::vector<int>>& board, int row, int col)
{
    if (row == board.size())
    {
        return true; 
    }

    if (col == board[0].size())
    {
        return solveSudoku(board, row + 1, 0);
    }

    if (board[row][col] != 0)
    {
        return solveSudoku(board, row, col + 1);
    }

    for (int num = 1; num <= board.size(); num++)
    {
        if (isValid(board, row, col, num))
        {
            board[row][col] = num;
            if(solveSudoku(board, row, col + 1))
            {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

void Recursion::printSudoku(std::vector<std::vector<int>>& board)
{
    int row_count = 0, col_count = 0;
    std::cout << "Solution found:\n-------------------------" << std::endl;
    for (int i = 0; i < board.size(); i++)
    {
        row_count++;
        std::cout << "| ";
        for (int j = 0 ; j < board[0].size(); j++)
        {
            col_count++;
            std::cout << board[i][j] << " ";
            if (col_count % 3 == 0)
            {
                std::cout << "| ";
            }
        }
        std::cout << std::endl;
        if (row_count % 3 == 0)
        {
            std::cout << "-------------------------" << std::endl;
        }
    }
}

std::vector<int> Recursion::grayCode(int n)
{
    std::vector<int> result;
    if (n == 0)
    {
        result.push_back(0);
        return result;
    }

    std::vector<int> recursive_result = grayCode(n - 1);
    for (int num : recursive_result)
    {
        result.push_back(num);
    }

    int msb = 1 << (n - 1);
    for (int i = recursive_result.size() - 1; i >= 0; --i)
    {
        result.push_back(recursive_result[i] | msb);
    }

    return result;  
}

std::pair<int, int> Recursion::dfs(int node, int parent, const std::vector<std::vector<Edges>>& adj, int& diameter)
{
    int max_dist = 0;

    for (const auto& edge : adj[node])
    {
        if (edge.to != parent)
        {
            std::pair<int, int> result = dfs(edge.to, node, adj, diameter);
            int dist = result.second + edge.weight;
            max_dist = std::max(max_dist, dist);
        }
    }
    diameter = std::max(diameter, max_dist);
    return {node, max_dist};
}

int Recursion::treeDiameter(const std::vector<std::vector<Edges>>& adj)
{
    int n = adj.size();
    if(n == 0) return 0;

    int diameter = 0;
    dfs(0, -1, adj, diameter);
    return diameter;
}