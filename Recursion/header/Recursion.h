#ifndef RECURSION_H
#define RECURSION_H

#include <iostream>
#include <vector>
#include <algorithm> 

class Recursion
{
    private:
        // Checks if placing a queen is safe.
        bool isSafe(const std::vector<int>& placement, int row, int col);

        // Recursive helper function to placing queens.
        void solveNQueensUtil(int n, int row, std::vector<int>& placement, std::vector<std::vector<std::string>>& solutions);

        // Recursive function to generate permutations.
        void generatePermutationsRecursive(std::vector<int> arr, int n, std::vector<std::vector<int>>& result);
    
    public:
        // Implements the recursive logic of the Tower of Hanoi problem.
        void towerOfHanoi(int n, char source, char destination, char auxiliary);

        // Initializes the vector and calls the helper function. 
        std::vector<std::vector<std::string>> solveNQueens(int n);

        // Wrapper function to generate permutation.
        std::vector<std::vector<int>> generatePermutations(std::vector<int> arr);
};

#endif // RECURSION_H