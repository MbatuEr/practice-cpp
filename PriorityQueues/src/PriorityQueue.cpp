#include "../header/PriorityQueue.h"

Star::Star(double x, double y, double z) : x(x), y(y), z(z) {}

Pair::Pair(std::string s, int f) : str(s), freq(f) {}

bool Element::operator>(const Element& other) const 
{
    return value > other.value;
}

bool CompareDistance::operator()(const Star& a, const Star& b)
{
    return a.distanceToEarth() > b.distanceToEarth();           // Min-heap for closest stars
}

double Star::distanceToEarth() const
{
    return std::sqrt(x*x + y*y + z*z);
}

bool Pair::operator>(const Pair& other) const
{
    return freq > other.freq;
}

std::vector<int> PriorityQueues::mergeSortedArrays(
                                 const std::vector<std::vector<int>>& sorted_arrays) 
{
    for (size_t i = 0; i < sorted_arrays.size(); i++)
    {
        if (!sorted_arrays.empty())
        {
            min_heap.push({sorted_arrays[i][0], static_cast<int>(i), 0});
        }
    }
    std::vector<int> result;
    
    while (!min_heap.empty())
    {
        Element current = min_heap.top();
        min_heap.pop();
        result.push_back(current.value);

        if (current.element_index + 1 < sorted_arrays[current.array_index].size())
        {
            min_heap.push({
                sorted_arrays[current.array_index][current.element_index + 1],
                current.array_index,
                current.element_index + 1
            });
        }        
    }
    return result;
}

std::vector<int> PriorityQueues::sortIncreasingDecreasingArray(const std::vector<int>& arr)
{
    std::vector<std::vector<int>> sorted_arrays = splitIntoSortedSubarrays(arr);
    return mergeSortedArrays(sorted_arrays);
}

std::vector<std::vector<int>> PriorityQueues::splitIntoSortedSubarrays(
                                              const std::vector<int>& arr)
{
    std::vector<std::vector<int>> sorted_arrays;
    bool increasing = true;
    int start = 0;
    
    for (size_t i = 0; i <= arr.size(); i++)
    {
        if (i == arr.size() || arr[i] > arr[i - 1] != increasing)
        {
            std::vector<int> segment(arr.begin() + start, arr.begin() + i);
            if (!increasing)
            {
                std::reverse(segment.begin(), segment.end());
            }
            sorted_arrays.push_back(segment);
            start = i;
            increasing = !increasing;
        }        
    }
    return sorted_arrays;
}

std::vector<int> PriorityQueues::sortKSortedArray(const std::vector<int>& arr, int k)
{
    std::vector<int> result;
    for (int i = 0; i <= k && i < arr.size(); i++)
    {
        k_sorted.push(arr[i]);
    }

    for (int i = k + 1; i < arr.size(); i++)
    {
        result.push_back(k_sorted.top());
        k_sorted.pop();

        k_sorted.push(arr[i]);
    }

    while (!k_sorted.empty())
    {
        result.push_back(k_sorted.top());
        k_sorted.pop();
    }
    
    return result;    
}

std::vector<Star> PriorityQueues::findKClosestStars(const std::vector<Star>& stars, int k)
{
    if(k <= 0) return {};

    std::priority_queue<Star, std::vector<Star>, CompareDistance> pq;

    for (const auto& star : stars)
    {
        pq.push(star);
    }
    
    std::vector<Star> closest_stars;
    for (int i = 0; i <= k; i++)
    {
        closest_stars.push_back(pq.top());
        pq.pop();
    }
    return closest_stars;
}

void PriorityQueues::insertForMedian(int num)
{
    if (left.empty() || num <= left.top())
    {
        left.push(num);
    }
    else {
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
    if(left.size() > right.size())
    {
        return left.top();
    } 
    else {
        return (left.top() + right.top()) / 2.0;
    }
}

std::vector<int> PriorityQueues::findkLargestElements(const std::vector<int>& arr, int k)
{
    if(arr.empty()) return arr;

    std::vector<int> result;
    for (int i = 0; i < arr.size(); i++)
    {
        max_element.push(arr[i]);
    }

    for (int i = 0; i < k; i++)
    {
        result.push_back(max_element.top());
        max_element.pop();
    }
    
    return result;
}

std::vector<std::string> PriorityQueues::mostFrequentStrings(
                                         const std::vector<std::string>& strs, int k)
{
    std::unordered_map<std::string, int> freqs;
    for (const std::string& str : strs)
    {
        freqs[str]++;
    }
    
    for (const auto& [str, freq] : freqs)
    {
        most_frequent.emplace(str, freq);
        if (most_frequent.size() > k)
        {
            most_frequent.pop();
        }        
    }
    
    std::vector<std::string> result;
    while (!most_frequent.empty())
    {
        result.push_back(most_frequent.top().str);
        most_frequent.pop();
    }
    
    return result;
}