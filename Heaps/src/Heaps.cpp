#include "../header/Heaps.h"

std::vector<int> Heaps::mergeSortedSequences(const std::vector<std::vector<int>>& sequences) 
{
    for (int i = 0; i < sequences.size(); ++i) 
    {
        if (!sequences[i].empty()) 
        {
            minHeap.push({sequences[i][0], {i, 0}});
        }
    }

    std::vector<int> result;

    while (!minHeap.empty()) 
    {
        auto current = minHeap.top();
        minHeap.pop();

        int value = current.first;
        int seqIndex = current.second.first;
        int elemIndex = current.second.second;

        result.push_back(value);

        if (elemIndex + 1 < sequences[seqIndex].size()) 
        {
            minHeap.push({sequences[seqIndex][elemIndex + 1], {seqIndex, elemIndex + 1}});
        }
    }

    return result;
}

std::vector<int> Heaps::sortKIncreasingDecreasingArray(const std::vector<int>& arr) 
{
    std::vector<std::vector<int>> sortedArrays = splitIntoSortedSubarrays(arr);

    return mergeSortedArrays(sortedArrays);
}

std::vector<std::vector<int>> Heaps::splitIntoSortedSubarrays(const std::vector<int>& arr) 
{
    std::vector<std::vector<int>> sortedArrays;
    bool increasing = true; 
    int start = 0;

    for (size_t i = 1; i <= arr.size(); ++i) 
    {
        if (i == arr.size() || (arr[i] > arr[i - 1]) != increasing) 
        {
            std::vector<int> segment(arr.begin() + start, arr.begin() + i);
            if (!increasing) 
            {
                std::reverse(segment.begin(), segment.end());
            }
            sortedArrays.push_back(segment);
            start = i;
            increasing = !increasing;
        }
    }

    return sortedArrays;
}

std::vector<int> Heaps::mergeSortedArrays(const std::vector<std::vector<int>>& sortedArrays) 
{
    struct Element 
    {
        int value;
        int arrayIndex;
        int elementIndex;
        
        bool operator>(const Element& other) const {
            return value > other.value;
        }
    };

    std::priority_queue<Element, std::vector<Element>, std::greater<Element>> minHeap;

    for (size_t i = 0; i < sortedArrays.size(); ++i) 
    {
        if (!sortedArrays[i].empty()) {
            minHeap.push({sortedArrays[i][0], static_cast<int>(i), 0});
        }
    }

    std::vector<int> result;

    while (!minHeap.empty()) 
    {
        Element current = minHeap.top();
        minHeap.pop();
        result.push_back(current.value);

        if (current.elementIndex + 1 < sortedArrays[current.arrayIndex].size()) 
        {
            minHeap.push({
                sortedArrays[current.arrayIndex][current.elementIndex + 1],
                current.arrayIndex,
                current.elementIndex + 1
            });
        }
    }

    return result;
}
