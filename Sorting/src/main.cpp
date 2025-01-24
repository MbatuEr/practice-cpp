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

    int chunkSize = 5; 

    std::vector<std::vector<std::string>> chunks = sort.splitIntoChunks(data, chunkSize);

    std::vector<std::string> sortedData = sort.mergeChunks(chunks);

    std::cout << "Sorted data:\n";
    for (const auto& str : sortedData) 
    {
        std::cout << str << " ";
    }
    std::cout << "\n----------------------------------------------" << std::endl;
    return 0;
}