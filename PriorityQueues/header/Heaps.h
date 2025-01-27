#ifndef HEAPS_H
#define HEAPS_H

#include <iostream>
#include <stdexcept>
#include <algorithm> 
#include <vector>

class Heaps 
{
    private:
        std::vector<int> data; // Internal storage for the heap.

        // Sifts up an element to maintain heap property. 
        void sift_up(int index);

        // Returns the number of elements in the heap.
        int get_size() const;

        // Sifts down an element to maintain heap property .
        void sift_down(int index);
    
    public:
        // Constructor.
        Heaps() = default;

        // Inserts a new element into the heap.
        void insert(int value);

        // Returns the maximum element without removing it.
        int get_max() const;

        // Checks if the heap is empty.
        bool is_empty() const;

        // Removes and return the maximum element.
        int extract_max();

        // Removes an element at a specific index.
        void remove(int index);

        // Creates a heap from an unsorted array.
        void heapify(const std::vector<int>& array);

        // Performs heap sort on an array.
        static std::vector<int> heap_sort(std::vector<int> array);
};

#endif // HEAPS_H
