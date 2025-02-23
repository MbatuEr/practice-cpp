#include "../header/sorting.h"

int main() 
{
    Sorting sort;

    // Merge arrays.
    std::vector<int> A = {1, 3, 5, 0, 0, 0};  
    std::vector<int> B = {2, 4, 6};
    int m = 3; 
    int n = 3;  

    sort.mergeSortedArrays(A, m, B, n);

    for (int i = 0; i < m + n; ++i) 
    {
        std::cout << A[i] << " ";
    }
    std::cout << "\n----------------------------------------------" << std::endl;

    // Anagrams next to each other.
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    sort.groupAnagrams(strs);

    for (const auto& str : strs) {
        std::cout << str << " ";
    }
    std::cout << "\n----------------------------------------------" << std::endl;

    // Check if the input is in the array.
    std::vector<int> arr = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    int target = 3;

    int result = sort.findInRotatedArray(arr, target);

    if (result != -1) {
        std::cout << "Element " << target << " found at index " << result << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the array" << std::endl;
    }
    std::cout << "----------------------------------------------" << std::endl;

    // Find the given index in the list.
    Sorting sorts({1, 3, 5, 7, 9, 11, 13, 15, 17, 19});
    int x = 9;
    int index = sorts.findElement(x);

    if (index != -1) 
    {
        std::cout << "Element " << x << " found at index " << index << std::endl;
    } else {
        std::cout << "Element " << x << " not found." << std::endl;
    }
    std::cout << "----------------------------------------------" << std::endl;

    // Sorting by heap sort.
    std::vector<std::string> data = {
        "zebra", "apple", "orange", "mango", "banana",
        "kiwi", "grape", "pear", "peach", "strawberry",
        "cherry", "blueberry", "plum", "raspberry", "lemon",
        "lime", "watermelon", "blackberry", "pineapple", "coconut"
    };

    int chunk_size = 5; 

    std::vector<std::vector<std::string>> chunks = sort.splitIntoChunks(data, chunk_size);

    std::vector<std::string> sortedData = sort.mergeChunks(chunks);

    std::cout << "Sorted data:\n";

    for (const auto& str : sortedData) 
    {
        std::cout << str << " ";
    }
    std::cout << "\n----------------------------------------------" << std::endl;

    // Max number of concurrent events.
    std::vector<Event> events = {{1, 3}, {2, 4}, {5, 8}, {6, 7}, {8, 9}, {14, 17}, {4, 6}, {1, 5}, {13, 15}};

    int result_of_events = sort.maxConcurrentEvents(events);
    std::cout << "Maximum number of concurrent events: " << result_of_events << std::endl;
    std::cout << "----------------------------------------------" << std::endl;

    // Union of intervals. 
    std::vector<Event> intervals = {
        {0, 3}, {1, 1}, {2, 4}, {3, 4}, {5, 7}, {7, 8}, {8, 11}, {9, 11}, {12, 14}, {12, 16}, {13, 15}, {16, 17}
    };

    std::vector<Event> unions = sort.computeUnion(intervals);

    std::cout << "Union of intervals: ";
    for (const auto& interval : unions) {
        std::cout << "[" << interval.start << "," << interval.end << "]" << " ";
    }
    std::cout << "\n----------------------------------------------" << std::endl;

    // Sorting string & int pairs by integers.
    std::vector<Student> students = {
        {"Alice", 20}, {"Bob", 22}, {"Charlie", 20}, {"David", 21}, {"Eve", 22}, {"Frank", 21}
    };

    std::cout << "Input vector: " << std::endl;
    for (const auto& student : students) 
    {
        std::cout << "[" << student.name << ", " << student.age << "] ";
    }
    std::cout << std::endl;

    sort.sortingStudentsByAge(students);
    std::cout << "After sorting by numbers: " << std::endl;
    for (const auto& student : students) 
    {
        std::cout << "[" << student.name << ", " << student.age << "] ";
    }
    std::cout << "\n----------------------------------------------" << std::endl;
    
    // Sorting into two different arrays.
    std::vector<Team> Fenerbahce = {
        {"Livakovic", 190}, {"Kadioglu", 180}, {"Djiku", 188}, {"Becao", 194}, {"Osayi", 184}, {"Ismail", 183}, {"Fred", 173},
        {"Kahveci", 180}, {"Szymanski", 174}, {"Tadic", 181}, {"Dzeko", 193}
    };

    std::vector<Team> Galatasaray = {
        {"Muslera", 188}, {"Baris", 183}, {"Davinson", 192}, {"Nelsson", 187}, {"Boey", 181}, {"Torreira", 169}, {"Demirbay", 182},
        {"Ziyech", 182}, {"Mertens", 170}, {"Akturkoglu", 179}, {"Icardi", 185}
    };

    sort.teamPhoto(Fenerbahce, Galatasaray);
    std::cout << "----------------------------------------------" << std::endl;

    // Perform Quick Sort.
    srand(time(0));
    std::vector<int> qvec = {10, 80, 30, 90, 40, 50, 70};
    Sorting qs(qvec);
    
    qs.quickSort(0, qvec.size() - 1);

    std::cout << "Sorted Array: ";
    qs.printValues();
    std::cout << "\n----------------------------------------------" << std::endl;
    
    // Perform Bucket sort.
    std::vector<float> bucket_arr = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};

    std::cout << "Original array: \n";
    for (float num : bucket_arr) 
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;    

    sort.bucketSort(bucket_arr);

    std::cout << "Sorted array: \n";
    for (float num : bucket_arr) 
    {
        std::cout << num << " ";
    }
    std::cout << "\n----------------------------------------------" << std::endl;

    // Perform Radix sort.
    std::vector<int> radix_arr = {17012, 45345, 75234, 90714, 12802, 234, 23, 4466};

    std::cout << "Original array: \n";
    for (float num : radix_arr) 
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;    

    sort.radixSort(radix_arr);

    std::cout << "Sorted array: \n";
    for (float num : radix_arr) 
    {
        std::cout << num << " ";
    }
    std::cout << "\n----------------------------------------------" << std::endl;

    // An optimized quick sort.
    std::vector<int> nums = {5, 2, 4, 3, 1, 6};
    int k = 3;
    int select = sort.kthLargestNumber(nums, k);
    std::cout << "The " << k << "th largest number is: " << select << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    return 0;
}