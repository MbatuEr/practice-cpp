#include "../header/sorting.h"

Sorting::Sorting() {}

Sorting::Sorting(const std::vector<int>& arr) : data(arr) {}

bool Team::operator<(const Team& other) const 
{
        return height < other.height;
}

std::size_t VectorHash::operator()(const std::vector<int>& vec) const
{
    std::size_t hash = 0;
    for (int num : vec) 
    {
        hash ^= std::hash<int>()(num) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
    }
    return hash;
}

void Sorting::mergeSortedArrays(std::vector<int>& A, int m, std::vector<int>& B, int n) 
{    
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0)
    {
        if(A[i] > B[j])
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
    std::unordered_map<std::vector<int>, std::vector<std::string>, VectorHash> anagramGroups;

    for (const auto& str : strs)
    {
        std::vector<int> freq(26,0);
        for(char c : str)
        {
            freq[c - 'a']++;
        }
        anagramGroups[freq].push_back(str);
    }

    int index = 0;
    for(auto& group : anagramGroups)
    {
        for (const auto& anagram : group.second)
        {
            strs[index++] = anagram;
        }
    }
    reverse(strs.begin(), strs.end());
}

int Sorting::findInRotatedArray(const std::vector<int>& arr, int target) 
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target) return mid;

        if(arr[left] < arr[mid])
        {
            if (arr[left] <= target && target <= arr[mid])
            {
                right = mid - 1;
            }
            else {
                left = mid + 1;
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
    if(i >= 0 && i < data.size()) return data[i];

    return -1;
}

int Sorting::findElement(int x) const
{
    int index = 1;
    while (elementAt(index) != 1 && elementAt(index) < x) index *= 2;

    int left = index / 2;
    int right = index;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int element = elementAt(mid);

        if(element == x) return mid;

        else if(element != 1 && element > x) right = mid - 1;
        
        else  left = mid + 1;
    }
    return -1;
}

std::vector<std::vector<std::string>> Sorting::splitIntoChunks(const std::vector<std::string>& data, int chunk_size) 
{
    std::vector<std::vector<std::string>> chunks;
    for (size_t i = 0; i < data.size(); i += chunk_size)
    {
        std::vector<std::string> chunk(data.begin() + i, data.begin() + std::min(i + chunk_size, data.size()));
        std::sort(chunk.begin(), chunk.end());
        chunks.push_back(chunk);    
    }

    return chunks;
}    

std::vector<std::string> Sorting::mergeChunks(const std::vector<std::vector<std::string>>& chunks) 
{
    auto cmp = [] (const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        return a.first > b.first;
    };

    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, decltype(cmp)> min_heap(cmp);
    std::vector<int> indices(chunks.size(), 0);

    for(int i = 0; i < chunks.size(); i++)
    {
        if (!chunks.empty())
        {
            min_heap.emplace(chunks[i][0], i);
        }
    }

    std::vector<std::string> result;

    while (!min_heap.empty())
    {
        auto [smallest_string, chunk_index] = min_heap.top();
            min_heap.pop();

        result.push_back(smallest_string);
        indices[chunk_index]++;

        if (indices[chunk_index] < chunks[chunk_index].size())
        {
            min_heap.emplace(chunks[chunk_index][indices[chunk_index]], chunk_index);
        }
    }

    return result;
}

int Sorting::maxConcurrentEvents(std::vector<Event> events) 
{
    std::sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        return a.end < b.end;
    });

    int max_concurrent = 0;

    std::queue<Event> active;

    for(const auto& event : events)
    {
        while (!active.empty() && active.front().end <= event.start)
        {
            active.pop();
        }
        active.push(event);
        max_concurrent = std::max(max_concurrent, (int)active.size());
    }
    return max_concurrent;
}

std::vector<Event> Sorting::computeUnion(const std::vector<Event>& intervals)
{
    std::vector<Event> sorted_intervals = intervals;
    std::sort(sorted_intervals.begin(), sorted_intervals.end(), [](const Event& a, const Event& b) {
                return (a.start < b.start && a.end < b.end) ||
                        (a.start == b.start && a.end < b.end);
            });

    std::vector<Event> result;
    Event current = sorted_intervals[0];

    for (size_t i = 1; i < sorted_intervals.size(); i++)
    {
        const Event& next = sorted_intervals[i];
        if (current.end >= next.start)
        {
            current.end = std::max(current.end, next.end);
        }
        else {
            result.push_back(current);
            current = next;
        }
    }
    result.push_back(current);

    return result;
}

void Sorting::sortingStudentsByAge(std::vector<Student>& students)
{
    std::unordered_map<int, std::vector<Student>> age_buckets;
    for (const auto& student : students)
    {
        age_buckets[student.age].push_back(student);
    }

    std::vector<int> ages;
    for (const auto& [age, _] : age_buckets)
    {
        ages.push_back(age);
    }

    std::sort(ages.begin(), ages.end());

    size_t index = 0;
    for (int age : ages)
    {
        for (const auto& student : age_buckets[age])
        {
            students[index++] = student;
        }
    }
}

void Sorting::teamPhoto(std::vector<Team>& team1, std::vector<Team>& team2) 
{
   std::vector<Team> front_line;
   std::vector<Team> back_line;

   std::sort(team1.begin(), team1.end());
   std::sort(team2.begin(), team2.end());

   int team1_order = 0, team2_order = 0;
   while (team1_order < team1.size() && team2_order < team2.size() && front_line.size() < team1.size())
   {
        if (team1[team1_order] < team2[team2_order])
        {
            front_line.push_back(team1[team1_order]);
            team1_order++;
        }
        else {
            front_line.push_back(team2[team2_order]);
            team2_order++;
        }
   }

   while (team1_order < team1.size() && team2_order < team2.size() && back_line.size() < team1.size())
   {
        if (team1[team1_order] < team2[team2_order])
        {
            back_line.push_back(team1[team1_order]);
            team1_order++;
        }
        else {
            back_line.push_back(team2[team2_order]);
            team2_order++;
        }
   }

   while (team1_order < team1.size())
   {
        back_line.push_back(team1[team1_order]);
        team1_order++;
   }

   while (team2_order < team2.size())
   {
        back_line.push_back(team2[team2_order]);
        team2_order++;
   }

   printLine(front_line, back_line); 
}

void Sorting::printLine(const std::vector<Team>& front_line, const std::vector<Team>& back_line) 
{
    std::cout << "Back Line: " << std::endl;
    for (const auto& player : back_line) 
    {
        std::cout << "[" << player.name << ", " << player.height << "] ";
    }
    std::cout << std::endl;

    std::cout << "Front Line: " << std::endl;
    for (const auto& player : front_line) 
    {
        std::cout << "[" << player.name << ", " << player.height << "] ";
    }
    std::cout << std::endl;
}

void Sorting::quickSort(int low, int high) 
{
    if (low >= high) return;

    int i = low;
    int j = high;
    int pivot_index = low + rand() % (high - low + 1);
    int pivot = data[pivot_index];

    while (i <= j)
    {
        while(i <= high && data[i] < pivot) i++;
        while(j >= low && data[j] > pivot) j--;

        if(i <= j)
        {
            std::swap(data[i], data[j]);
            i++;
            j--;
        }
    }
    if(low < j) quickSort(low, j);
    if(high > i) quickSort(i, high);
}

void Sorting::printValues() 
{
    for (int val : data) 
    {
        std::cout << val << " ";
    }
}

void Sorting::bucketSort(std::vector<float>& arr) 
{
    int n = arr.size();
    if(n <= 1) return;

    std::vector<std::list<float>> buckets(n);
    for(float num : arr)
    {
        int bucket_index = static_cast<int> (num * n);
        buckets[bucket_index].push_back(num);
    }

    for (int i = 0; i < n; i++)
    {
        buckets[i].sort();
    }

    int index = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (float num : buckets[i])
        {
            arr[index++] = num;
        }
    }
}

int Sorting::getMax(const std::vector<int>& arr) 
{
    return *std::max_element(arr.begin(), arr.end());
}

void Sorting::countingSort(std::vector<int>& arr, int exp) 
{
    int n = arr.size();
    std::vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }
    
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit] --;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void Sorting::radixSort(std::vector<int>& arr) 
{
    int maxVal = getMax(arr);
    for (int exp = 1; maxVal / exp > 0; exp *= 10) 
    {
        countingSort(arr, exp);
    }
}
