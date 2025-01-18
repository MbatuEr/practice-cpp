#include "../header/Heaps.h"

int main() {
    // Merging arrays.
    Heaps merger;

    std::vector<std::vector<int>> sequences = 
    {
        {3, 5, 7},
        {0, 6},
        {0, 6, 28}
    };

    std::vector<int> mergedSequence = merger.mergeSortedSequences(sequences);

    std::cout << "Merged Sorted Sequence: ";
    for (int num : mergedSequence) 
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;

    // Sorting an increasing-decreasing array.
    Heaps sorted;
    
    std::vector<int> arr = {57, 131, 493, 294, 221, 339, 418, 452, 442, 190};
    
    std::vector<int> sortedArray = sorted.sortKIncreasingDecreasingArray(arr);

    std::cout << "Sorted Array: ";
    for (int num : sortedArray) 
    {
        std::cout << num << " ";
    }
    std::cout << "\n-------------------------------------------------" << std::endl;

    return 0;
}