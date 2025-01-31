#include "../header/PriorityQueue.h"

int main() 
{
    // Merging arrays.
    PriorityQueues pq;

    std::vector<std::vector<int>> sequences = 
    {
        {3, 5, 7},
        {0, 6},
        {0, 6, 28}
    };
    std::vector<int> mergedSequence = pq.mergeSortedArrays(sequences);

    std::cout << "Merged Sorted Sequence: ";
    for (int num : mergedSequence) 
    {
        std::cout << num << " ";
    }
    std::cout << "\n-------------------------------------------------" << std::endl;

    // Sorting an increasing-decreasing array.
    std::vector<int> arr = {57, 131, 493, 294, 221, 339, 418, 452, 442, 190};
    
    std::vector<int> sortedArray = pq.sortIncreasingDecreasingArray(arr);

    std::cout << "Sorted Array: ";
    for (int num : sortedArray) 
    {
        std::cout << num << " ";
    }
    std::cout << "\n-------------------------------------------------" << std::endl;

    // Sorting an array which is k away at most.
    std::vector<int> k_sorted_arr = {3, -1, 2, 6, 4, 5, 8};
    int k = 2;

    std::vector<int> sortedArr = pq.sortKSortedArray(k_sorted_arr, k);

    std::cout << "Sorted Array: ";
    for (int num : sortedArr) 
    {
        std::cout << num << " ";
    }
    std::cout << "\n-------------------------------------------------" << std::endl;

    // Closest stars.
    std::vector<Star> stars = {
        Star(1.0, 2.0, 3.0),
        Star(4.0, 5.0, 6.0),
        Star(7.0, 8.0, 9.0),
        Star(1.1, 2.1, 3.1),
        Star(0.5, 0.5, 0.5)
    };

    int key = 3;

    std::vector<Star> closestStars = PriorityQueues::findKClosestStars(stars, k);

    std::cout << "The " << key << " closest stars to Earth are:\n";
    for (const auto& star : closestStars) 
    {
        std::cout << "Star at (" << star.x << ", " << star.y << ", " << star.z << ") with distance " 
                  << star.distanceToEarth() << " light years.\n";
    }
    std::cout << "-------------------------------------------------" << std::endl;

    // Calculating median at each step.
    std::vector<int> sequence = {1, 0, 3, 5, 2, 0, 1};
    for (int num : sequence) 
    {
        pq.insertForMedian(num);
        std::cout << pq.getMedian() << " ";
    }
    std::cout << "\n-------------------------------------------------" << std::endl;

    // Max elements.
    int x = 3;
    std::vector<int> max_values = {16, 60, 73, 45, 52, 30, 81};

    std::vector<int> values = pq.findkLargestElements(max_values, x);

    std::cout << "Highest " << x << " values are: ";
    for(int value : values)
    {
        std::cout << value << " ";
    }
    std::cout << "\n-------------------------------------------------" << std::endl;

    return 0;
}