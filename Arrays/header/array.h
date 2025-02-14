#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cstdlib> 
#include <ctime>   
#include <cmath>
#include <unordered_set>
#include <random>

using namespace std;

class Array
{
    public:
        // Sorts a vector around a pivot. 
        void DutchNationalFlag(int pivot, vector<int>& nums);

        // Adds two binary numbers represented as strings.
        string AddBinary(string s1, string s2);
        
        // Multiplies two large integers represented as vectors of their digits.
        vector<int>Multiply(const vector<int>& v1, const vector<int>& v2);
        
        // Check if it is possible to reach the last index of the array by jumping.
        bool CanReachEnd(const vector <int>& vec); 
        
        // Removes duplicate elements from a vector.
        void DeleteDuplicates(vector <int>& vec);
        
        // Calculates the maximum profit that can be obtained by buying and selling a stock once.
        int ProfitFromStock(const vector <int>& stocklist);
        
        // Finds all prime numbers less than a given key value.
        vector<int>FindPrimeValues(int key_value);
        
        // Rearranges a vector based on the permutation order.
        void PermutingElements(vector<int>& vec1, vector<int>& vec2);
        
        // Computes the next lexicographical permutation of the input vector.
        void FindNextPermutation(vector<int>& vec);
        
        // Randomly selects a subset of a specified size from the input vector.
        void OfflineRandomSampling(int size, vector<int>& vec);
        
        // Updates an array's elements based on their associated probabilities.
        void UpdateArrayWithProbabilities(int size, vector<int>& input_array, vector<double>& probabilities);
        
        // Validates whether the given Sudoku board configuration is valid.
        bool IsValidSudoku(vector<vector<int>>& board);  
        
        // Returns the elements of a 2D array in spiral order as a 1D vector.
        vector<int> SpiralOrderOfArray(vector<vector<int>>& vec);
        
        // Rotates a 2D array 90 degrees clockwise.
        vector<vector<int>> Rotating2DArray(vector<vector<int>>& vec);
        
        // Generates a specific row of Pascal's Triangle.
        vector<int> GeneratePascalTriangle(int n, int row, int column);
        
        // Replaces spaces in a string with '%20'.
        static string ReplaceSpaces(string& str, int truelength);

        // Compresses a string using the counts of repeated characters.  
        string StringCompression(string& str);
        
        // Checks if one string is a rotation of another string.
        bool IsSubString(string& s1, string& s2);
};

#endif // ARRAY_H