#ifndef HEAPS_H
#define HEAPS_H

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using Element = std::pair<int, std::pair<int, int>>; 

class Heaps 
{
    private:
        std::priority_queue<Element, std::vector<Element>, std::greater<>> minHeap;

    public:
        // Method to merge sorted sequences.
        std::vector<int> mergeSortedSequences(const std::vector<std::vector<int>>& sequences);

        // Splits the array into k sorted subarrays.
        static std::vector<std::vector<int>> splitIntoSortedSubarrays(const std::vector<int>& arr);

        // Merges k sorted arrays.
        static std::vector<int> mergeSortedArrays(const std::vector<std::vector<int>>& sortedArrays);

        // Helper function to sort an increasing-decreasing array.
        static std::vector<int> sortKIncreasingDecreasingArray(const std::vector<int>& arr);
};

#endif // HEAPS_H
