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
        // Checks if placing a queen is safe.
        bool isSafe(const std::vector<int>& placement, int row, int col);

        // Recursive helper function to placing queens.
        void solveNQueensUtil(int n, int row, std::vector<int>& placement, std::vector<std::vector<std::string>>& solutions);

        // Recursive function to generate permutations.
        void generatePermutationsRecursive(std::vector<int> arr, int n, std::vector<std::vector<int>>& result);
    
        // Recursive function to generate the power set.
        void generatePowerSetRecursive(const std::vector<int>& set, int index, std::vector<int> current_subset, std::vector<std::vector<int>>& power_set);

        // Recursive function to compute all subsets of size k from 1 to n.
        void generateSubsetsOfSizeKRecursive(int n, int k, int start, std::vector<int>& current_subset, std::vector<std::vector<int>>& result);

        // Recursive function to computes a number of parantheses with a given input.
        void generateParenthesesRecursive(int n, int open, int close, std::string current, std::vector<std::string>& result);

        // Checks if the given input is palindrome.
        bool isPalindrome(const std::string& str);

        // Recursive function to check plaindromic decompositions.
        void generatePalindromicDecompositionsRecursive(const std::string& s, int index, std::vector<std::string>& current_decomposition, std::vector<std::vector<std::string>>& result);

        // Helper function to generate trees recursively.
        std::vector<Tree*> generateTreesHelper(int start, int end);

        // Checks the validation of sudoku board.
        bool isValid(const std::vector<std::vector<int>>& board, int row, int col, int num);

        // Depth-first search to find the deepest node and its distance from the start node.
        std::pair<int, int> dfs(int node, int parent, const std::vector<std::vector<Edges>>& adj, int& diameter);

    public:
        // Implements the recursive logic of the Tower of Hanoi problem.
        void towerOfHanoi(int n, char source, char destination, char auxiliary);

        // Initializes the vector and calls the helper function. 
        std::vector<std::vector<std::string>> solveNQueens(int n);

        // Wrapper function to generate permutation.
        std::vector<std::vector<int>> generatePermutations(std::vector<int> arr);

        // Generate the power set (initiates the recursion).
        std::vector<std::vector<int>> generatePowerSet(const std::vector<int>& set);

        // Computes all the subsets of size k (initiates the recursion).
        std::vector<std::vector<int>> generateSubsetsOfSizeK(int n, int k);

        // Computes a number of parantheses with a given input (initiates the recursion).
        std::vector<std::string> generateParentheses(int n);

        // Checks plaindromic decompositions (initiates the recursion). 
        std::vector<std::vector<std::string>> generatePalindromicDecompositions(const std::string& s);

        // Function to generate all distinct binary trees with `n` nodes.
        std::vector<Tree*> generateTrees(int n);

        // Function to print the tree in level order traversal (BFS).
        void printTree(Tree* root);

        // Recursive function to complete a  9x9 sudoku board.
        bool solveSudoku(std::vector<std::vector<int>>& board, int row, int col);

        // Prints the completed sudoku board.
        void printSudoku(std::vector<std::vector<int>>& board);

        // Computes n-bit gray code with the given input.
        std::vector<int> grayCode(int n);

        // Computes the diameter of a tree.
        int treeDiameter(const std::vector<std::vector<Edges>>& adj);
};

#endif // RECURSION_H