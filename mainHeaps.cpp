#include "../header/Heaps.h"

int main() {
    Heaps heap;

    // Insert elements
    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    heap.insert(30);

    std::cout << "Max element: " << heap.get_max() << std::endl;

    // Extract the maximum element
    std::cout << "Extracted max: " << heap.extract_max() << std::endl;

    // Remove an element
    heap.remove(1);
    std::cout << "Max element after removal: " << heap.get_max() << std::endl;

    // Check if the heap is empty
    std::cout << "Is heap empty? " << (heap.is_empty() ? "Yes" : "No") << std::endl;

    // Heapify an array
    std::vector<int> array = {5, 3, 8, 4, 2, 7, 1};
    heap.heapify(array);

    std::cout << "Heap after heapify: ";
    while (!heap.is_empty()) 
    {
        std::cout << heap.extract_max() << " ";
    }
    std::cout << std::endl;

    // Heap sort
    std::vector<int> unsorted = {9, 4, 7, 1, 3, 8, 5};
    std::vector<int> sorted = Heaps::heap_sort(unsorted);

    std::cout << "Sorted array: ";
    for (int num : sorted) 
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}