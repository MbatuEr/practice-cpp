#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_map>

struct Element 
{
    int value;
    int array_index;
    int element_index;
    
    bool operator>(const Element& other) const;
};

class Star 
{
    public:
        double x, y, z;

        Star(double x, double y, double z);

        double distanceToEarth() const;
};

struct CompareDistance 
{
    bool operator()(const Star& a, const Star& b);
};

struct Pair 
{

    std::string str;
    int freq;
    
    Pair(std::string s, int f);
    
    bool operator>(const Pair& other) const;
};

class PriorityQueues 
{
    private:
        std::vector<int> data;
        std::priority_queue<Element, std::vector<Element>, std::greater<Element>> min_heap;
        std::priority_queue<int, std::vector<int>, std::greater<int>> k_sorted;
        std::priority_queue<int> left; 
        std::priority_queue<int, std::vector<int>, std::greater<int>> right; 
        std::priority_queue<int> max_element;
        std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> most_frequent; 

        std::vector<std::vector<int>> splitIntoSortedSubarrays(const std::vector<int>& arr);
        
    public:
        std::vector<int> mergeSortedArrays(const std::vector<std::vector<int>>& sorted_arrays);

        std::vector<int> sortIncreasingDecreasingArray(const std::vector<int>& arr);

        std::vector<int> sortKSortedArray(const std::vector<int>& arr, int k);

        static std::vector<Star> findKClosestStars(const std::vector<Star>& stars, int k);

        void insertForMedian(int num);

        double getMedian() const;

        std::vector<int> findkLargestElements(const std::vector<int>& arr, int k);

        std::vector<std::string> mostFrequentStrings(const std::vector<std::string>& strs, int k);
};

#endif // PRIORITYQUEUE_H
