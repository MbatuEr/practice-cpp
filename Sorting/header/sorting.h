#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>

class Sorting
{
    private:
        std::vector<int> data;
    
    public:
        Sorting();
        
        // Constructor.
        Sorting(const std::vector<int>& arr);

        // Merges two array in sorted order.
        void mergeSortedArrays(std::vector<int>& A, int m, std::vector<int>& B, int n);

        // Sorts an array so that all anagrams are next to each other.
        void groupAnagrams(std::vector<std::string>& strs);

        // Checks a given input whether it's in the array or not.
        int findInRotatedArray(const std::vector<int>& arr, int target);

        // Returns the element at index i in 0(1) time.
        int elementAt(int i) const;

        // Finds the given index in the list.
        int findElement(int x) const;

        // Split the vector into chunks.
        std::vector<std::vector<std::string>> splitIntoChunks(const std::vector<std::string>& data, int chunkSize);

        // Merges sorted chunks.
        std::vector<std::string> mergeChunks(const std::vector<std::vector<std::string>>& chunks);
};




#endif // SORTING_H