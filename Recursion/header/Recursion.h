#ifndef RECURSION_H
#define RECURSION_H

#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath>
#include <string>
#include <queue>
#include <map>

// Definition for a binary tree node.
struct Tree
{
    int val;
    Tree* left;
    Tree* right;

    Tree(int x);
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
        void generatePowerSetRecursive(const std::vector<int>& set, int index, std::vector<int> currentSubset, std::vector<std::vector<int>>& powerSet);

        // Recursive function to compute all subsets of size k from 1 to s.
        void generateSubsetsOfSizeKRecursive(int n, int k, int start, std::vector<int>& currentSubset, std::vector<std::vector<int>>& result);

        // Recursive function to computes a number of parantheses with a given input.
        void generateParenthesesRecursive(int n, int open, int close, std::string current, std::vector<std::string>& result);

        // Checks if the given input is palindrome.
        bool isPalindrome(const std::string& str);

        // Recursive function to check plaindromic decompositions.
        void generatePalindromicDecompositionsRecursive(const std::string& s, int index, std::vector<std::string>& current_decomposition, std::vector<std::vector<std::string>>& result);

        // Helper function to generate trees recursively.
        std::vector<Tree*> generateTreesHelper(int start, int end);

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
};

#endif // RECURSION_H