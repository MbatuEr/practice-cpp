#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cstdlib> // for rand and srand
#include <ctime>   // for time
#include <cmath>
#include <unordered_set>


using namespace std;

class Array
{
    public:
        void DutchNationalFlag(int pivot, vector<int>& nums);
        string AddBinary(string s1, string s2);
        vector<int>Multiply(const vector<int>& v1, const vector<int>& v2);
        bool CanReachEnd(const vector <int>& vec); 
        vector<int>DeleteDuplicates(vector <int>& vec);
        int ProfitFromStock(const vector <int>& stocklist);
        vector<int>FindPrimeValues(int key_value);
        void PermutingElements(vector<int>& vec1, vector<int>& vec2);
        void FindNextPermutation(vector<int>& vec);
        void OfflineRandomSampling(int size, vector<int>& vec);
        void UpdateArrayWithProbabilities(int size, vector<int>& input_array, vector<double>& probabilities);
        bool IsValidSudoku(vector<vector<int>>& board);  
        vector<int> SpiralOrderOfArray(vector<vector<int>>& vec);
        vector<vector<int>> Rotating2DArray(vector<vector<int>>& vec);
        vector<int> GeneratePascalTriangle(int n, int row, int column);
        static string ReplaceSpaces(string& str, int truelength);
        string StringCompression(string& str);
        bool IsSubString(string& s1, string& s2);
};
#endif