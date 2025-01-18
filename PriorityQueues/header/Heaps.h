#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <stdexcept>
#include <algorithm> 
#include <vector>

class Heaps 
{
    private:
    std::vector<int> data; // Internal storage for the heap
    
    public:
        // Constructors
        Heaps() = default;

        // Insert a new element into the heap
        void insert(int value);

        // Sift up an element to maintain heap property (used in insert)
        void sift_up(int index);

        // Return the maximum element without removing it
        int get_max() const;

        // Return the number of elements in the heap
        int get_size() const;

        // Check if the heap is empty
        bool is_empty() const;

        // Remove and return the maximum element
        int extract_max();

        // Sift down an element to maintain heap property (used in extract_max)
        void sift_down(int index);

        // Remove an element at a specific index
        void remove(int index);

        // Create a heap from an unsorted array
        void heapify(const std::vector<int>& array);

        // Perform heap sort on an array
        static std::vector<int> heap_sort(std::vector<int> array);
};

#endif // MAXHEAP_H
