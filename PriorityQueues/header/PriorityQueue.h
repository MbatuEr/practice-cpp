#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>

using pairs = std::pair<int, std::pair<int, int>>; 

struct Element 
{
    int value;
    int arrayIndex;
    int elementIndex;
    
    bool operator>(const Element& other) const;
};

class Star 
{
    public:
        double x, y, z;

        // Constructor.
        Star(double x, double y, double z);

        // Computes the distance from Earth (0, 0, 0).
        double distanceToEarth() const;
};

struct CompareDistance 
{
    bool operator()(const Star& a, const Star& b);
};

class PriorityQueues 
{
    private:
        std::vector<int> data;
        std::priority_queue<Element, std::vector<Element>, std::greater<Element>> minHeap;
        std::priority_queue<int, std::vector<int>, std::greater<int>> ksorted;
        std::priority_queue<int> left; 
        std::priority_queue<int, std::vector<int>, std::greater<int>> right; 
        std::priority_queue<int> maxElement; 

        // Splits the array into k sorted subarrays.
        std::vector<std::vector<int>> splitIntoSortedSubarrays(const std::vector<int>& arr);
        
    public:
        // Merges k sorted arrays.
        std::vector<int> mergeSortedArrays(const std::vector<std::vector<int>>& sortedArrays);

        // Sorts an increasing-decreasing array.
        std::vector<int> sortIncreasingDecreasingArray(const std::vector<int>& arr);
        
        // Sorts an array that elements of it k away at most from its correct sorted position. 
        std::vector<int> sortKSortedArray(const std::vector<int>& arr, int k);

        // Finds the k closest stars to Earth.
        static std::vector<Star> findKClosestStars(const std::vector<Star>& stars, int k);

        // Inserts a number into the data structure.
        void insertForMedian(int num);

        // Returns the current running median.
        double getMedian() const;

        // Finds the k number of highest elements in a heap.
        std::vector<int> findkLargestElements(const std::vector<int>& arr, int k);
};

#endif // PRIORITYQUEUE_H
