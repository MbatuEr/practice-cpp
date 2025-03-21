#ifndef HEAPS_H
#define HEAPS_H

#include <iostream>
#include <stdexcept>
#include <algorithm> 
#include <vector>

class Heaps 
{
    private:
        std::vector<int> data;              // Internal storage for the heap.

        // Sifts up an element to maintain heap property. 
        void sift_up(int index);

        // Sifts down an element to maintain heap property .
        void sift_down(int index);
        
        int get_size() const;

    public:
        Heaps() = default;

        void insert(int value);

        int get_max() const;

        bool is_empty() const;

        int extract_max();

        void remove(int index);

        // Creates a heap from an unsorted array.
        void heapify(const std::vector<int>& array);

        static std::vector<int> heap_sort(std::vector<int> array);
};

#endif // HEAPS_H
