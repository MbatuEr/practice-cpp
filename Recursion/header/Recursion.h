#ifndef RECURSION_H
#define RECURSION_H

#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath>
#include <string>
#include <queue>
#include <map>

struct Tree
{
    int val;
    Tree* left;
    Tree* right;

    Tree(int x);
};

struct Edges 
{
    int to;
    int weight;
};

class Recursion
{
    private:
        bool isSafe(const std::vector<int>& placement, int row, int col);

        void solveNQueensUtil(int n, int row, std::vector<int>& placement, std::vector<std::vector<std::string>>& solutions);

        void generatePermutationsRecursive(std::vector<int> arr, int n, std::vector<std::vector<int>>& result);
    
        void generatePowerSetRecursive(const std::vector<int>& set, int index, std::vector<int> current_subset, std::vector<std::vector<int>>& power_set);

        void generateSubsetsOfSizeKRecursive(int n, int k, int start, std::vector<int>& current_subset, std::vector<std::vector<int>>& result);

        void generateParenthesesRecursive(int n, int open, int close, std::string current, std::vector<std::string>& result);

        bool isPalindrome(const std::string& str);

        void generatePalindromicDecompositionsRecursive(const std::string& s, int index, std::vector<std::string>& current_decomposition, std::vector<std::vector<std::string>>& result);

        std::vector<Tree*> generateTreesHelper(int start, int end);

        bool isValid(const std::vector<std::vector<int>>& board, int row, int col, int num);

        // Depth-first search to find the deepest node and its distance from the start node.
        std::pair<int, int> dfs(int node, int parent, const std::vector<std::vector<Edges>>& adj, int& diameter);

    public:
        void towerOfHanoi(int n, char source, char destination, char auxiliary);

        std::vector<std::vector<std::string>> solveNQueens(int n);

        std::vector<std::vector<int>> generatePermutations(std::vector<int> arr);

        std::vector<std::vector<int>> generatePowerSet(const std::vector<int>& set);

        std::vector<std::vector<int>> generateSubsetsOfSizeK(int n, int k);

        std::vector<std::string> generateParentheses(int n);

        std::vector<std::vector<std::string>> generatePalindromicDecompositions(const std::string& s);

        std::vector<Tree*> generateTrees(int n);

        void printTree(Tree* root);

        bool solveSudoku(std::vector<std::vector<int>>& board, int row, int col);

        void printSudoku(std::vector<std::vector<int>>& board);

        std::vector<int> grayCode(int n);

        int treeDiameter(const std::vector<std::vector<Edges>>& adj);
};

#endif // RECURSION_H