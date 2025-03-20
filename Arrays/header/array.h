#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>    
#include <unordered_set>
#include <random>

class Array
{
    public:
        void DutchNationalFlag(int pivot, std::vector<int>& nums);

        std::string AddBinary(std::string s1, std::string s2);

        std::vector<int>Multiply(const std::vector<int>& v1, const std::vector<int>& v2);

        bool CanReachEnd(const std::vector <int>& vec); 

        void DeleteDuplicates(std::vector <int>& vec);

        int ProfitFromStock(const std::vector <int>& stocklist);

        std::vector<int>FindPrimeValues(int key_value);

        void PermutingElements(std::vector<int>& vec1, std::vector<int>& vec2);

        void FindNextPermutation(std::vector<int>& vec);

        void OfflineRandomSampling(int size, std::vector<int>& vec);

        void UpdateArrayWithProbabilities(int size, std::vector<int>& input_array, std::vector<double>& probabilities);

        bool IsValidSudoku(std::vector<std::vector<int>>& board);  

        std::vector<int> SpiralOrderOfArray(std::vector<std::vector<int>>& vec);

        std::vector<std::vector<int>> Rotating2DArray(std::vector<std::vector<int>>& vec);

        std::vector<int> GeneratePascalTriangle(int n);
        
        static std::string ReplaceSpaces(std::string& str, int truelength);
  
        std::string StringCompression(std::string& str);
        
        bool IsSubString(std::string& s1, std::string& s2);
};

#endif // ARRAY_H