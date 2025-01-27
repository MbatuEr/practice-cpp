#include "../header/PriorityQueue.h"

Star::Star(double x, double y, double z) : x(x), y(y), z(z) {}

bool Element::operator>(const Element& other) const 
{
    return value > other.value;
}

bool CompareDistance::operator()(const Star& a, const Star& b) 
{
    return a.distanceToEarth() > b.distanceToEarth();  // Min-heap for closest stars
}

double Star::distanceToEarth() const 
{
    return std::sqrt(x * x + y * y + z * z);
}

std::vector<int> PriorityQueues::mergeSortedArrays(const std::vector<std::vector<int>>& sortedArrays) 
{
    for (size_t i = 0; i < sortedArrays.size(); ++i) 
    {
        if (!sortedArrays[i].empty()) 
        {
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

std::vector<int> PriorityQueues::sortIncreasingDecreasingArray(const std::vector<int>& arr) 
{
    std::vector<std::vector<int>> sortedArrays = splitIntoSortedSubarrays(arr);

    return mergeSortedArrays(sortedArrays);
}

std::vector<std::vector<int>> PriorityQueues::splitIntoSortedSubarrays(const std::vector<int>& arr) 
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

std::vector<int> PriorityQueues::sortKSortedArray(const std::vector<int>& arr, int k)
{
    std::vector<int> result;

    for (int i = 0; i <= k && i < arr.size(); ++i) 
    {
        ksorted.push(arr[i]);
    }

    for (int i = k + 1; i < arr.size(); ++i) 
    {
        result.push_back(ksorted.top());
        ksorted.pop();

        ksorted.push(arr[i]);
    }

    while (!ksorted.empty()) 
    {
        result.push_back(ksorted.top());
        ksorted.pop();
    }

    return result;
}

std::vector<Star> PriorityQueues::findKClosestStars(const std::vector<Star>& stars, int k) 
{
    if (k <= 0) return {};
     
    std::priority_queue<Star, std::vector<Star>, CompareDistance> pq;

    for (const auto& star : stars) 
    {
        pq.push(star);
    }

    std::vector<Star> closestStars;
    for (int i = 0; i <= k; ++i) 
    {
        closestStars.push_back(pq.top());
        pq.pop();
    }

    return closestStars;
}

void PriorityQueues::insertForMedian(int num) 
{
    if (left.empty() || num <= left.top()) 
    {
        left.push(num);
    } 
    else 
    {
        right.push(num);
    }

    if (left.size() > right.size() + 1) 
    {
        right.push(left.top());
        left.pop();
    } 
    else if (right.size() > left.size()) 
    {
        left.push(right.top());
        right.pop();
    }
}

double PriorityQueues::getMedian() const 
{
    if (left.size() > right.size()) 
    {
        return left.top();
    } 
    else 
    {
        return (left.top() + right.top()) / 2.0;
    }
}

std::vector<int> PriorityQueues::findkLargestElements(const std::vector<int>& arr, int k)
{
    if(arr.empty()) return arr;
    
    std::vector<int> result;

    for(int value : arr)
    {
        maxElement.push(value);
    }

    for(int i = 0 ; i < k; i++)
    {
       result.push_back(maxElement.top());
       maxElement.pop();
    }

    return result;
}