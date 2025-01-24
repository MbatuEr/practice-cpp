#include "../header/sorting.h"

Sorting::Sorting() {}

Sorting::Sorting(const std::vector<int>& arr) : data(arr) {}

void Sorting::mergeSortedArrays(std::vector<int>& A, int m, std::vector<int>& B, int n) 
{    
    int i = m - 1;  
    int j = n - 1;  
    int k = m + n - 1; 

    while (i >= 0 && j >= 0) 
    {
        if (A[i] > B[j]) 
        {
            A[k--] = A[i--];  
        } 
        else {
            A[k--] = B[j--];  
        }
    }

    while (j >= 0) 
    {
        A[k--] = B[j--];
    }
}

void Sorting::groupAnagrams(std::vector<std::string>& strs) 
{
    std::unordered_map<std::string, std::vector<std::string>> anagramGroups;

    for (const auto& str : strs) 
    {
        std::string sortedStr = str;
        std::sort(sortedStr.begin(), sortedStr.end());

        anagramGroups[sortedStr].push_back(str);
    }
    int index = 0;

    for (auto& group : anagramGroups) 
    {
        for (const auto& anagram : group.second) 
        {
            strs[index++] = anagram;
        }
    }
    std::reverse(strs.begin(), strs.end());
}

int Sorting::findInRotatedArray(const std::vector<int>& arr, int target) 
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // Avoid overflow.

        if(arr[mid] == target) return mid;

        if (arr[left] <= arr[mid])
        {
            if (arr[left] <= target && target <= arr[mid])
            {
                right = mid - 1;
            }
            else {
                left = mid - 1;
            }
        }
        else {
            if (arr[mid] <= target && target <= arr[right])
            {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int Sorting::elementAt(int i) const
{
    if (i >= 0 && i < data.size())
    {
        return data[i];
    }
    return -1;
}

int Sorting::findElement(int x) const
{
    int index = 1;
    while (elementAt(index) != -1 && elementAt(index) < x) index *= 2;
    
    int left = index / 2;
    int right = index;
    
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        int element = elementAt(mid);

        if (element == -1 || element > x) right = mid - 1;
             
        else if (element < x) left = mid + 1;

        else return mid;
    }
    return -1;
}

std::vector<std::vector<std::string>> Sorting::splitIntoChunks(const std::vector<std::string>& data, int chunkSize) 
{
    std::vector<std::vector<std::string>> chunks;

    for (size_t i = 0; i < data.size(); i += chunkSize) 
    {
        std::vector<std::string> chunk(data.begin() + i, data.begin() + std::min(i + chunkSize, data.size()));

        std::sort(chunk.begin(), chunk.end());
        chunks.push_back(chunk);
    }

    return chunks;
}

std::vector<std::string> Sorting::mergeChunks(const std::vector<std::vector<std::string>>& chunks) 
{
    auto cmp = [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) 
    {
        return a.first > b.first; 
    };

    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, decltype(cmp)> minHeap(cmp);

    std::vector<int> indices(chunks.size(), 0);

    for (int i = 0; i < chunks.size(); ++i) 
    {
        if (!chunks[i].empty()) 
        {
            minHeap.emplace(chunks[i][0], i);
        }
    }

    std::vector<std::string> result;

    // Merge chunks
    while (!minHeap.empty()) 
    {
        auto [smallestString, chunkIndex] = minHeap.top();
        minHeap.pop();

        result.push_back(smallestString);

        indices[chunkIndex]++;
        
        if (indices[chunkIndex] < chunks[chunkIndex].size()) 
        {
            minHeap.emplace(chunks[chunkIndex][indices[chunkIndex]], chunkIndex);
        }
    }

    return result;
}
