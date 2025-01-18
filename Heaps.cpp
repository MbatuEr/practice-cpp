#include "../header/Heaps.h"

void Heaps::insert(int value) 
{
    data.push_back(value);
    sift_up(data.size() - 1);
}

void Heaps::sift_up(int index) 
{
    while (index > 0) 
    {
        int parent = (index - 1) / 2;
        if (data[index] > data[parent]) 
        {
            std::swap(data[index], data[parent]);
            index = parent;
        } 
        else 
        {
            break;
        }
    }
}

int Heaps::get_max() const 
{
    if (is_empty()) 
    {
        throw std::runtime_error("Heap is empty");
    }
    return data[0];
}

int Heaps::get_size() const 
{
    return data.size();
}

bool Heaps::is_empty() const 
{
    return data.empty();
}

int Heaps::extract_max() 
{
    if (is_empty()) 
    {
        throw std::runtime_error("Heap is empty");
    }

    int max_value = data[0];
    data[0] = data.back();
    data.pop_back();
    sift_down(0);
    
    return max_value;
}

void Heaps::sift_down(int index) 
{
    int size = data.size();

    while (index < size) 
    {
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        int largest = index;

        if (left_child < size && data[left_child] > data[largest]) 
        {
            largest = left_child;
        }
        if (right_child < size && data[right_child] > data[largest]) 
        {
            largest = right_child;
        }
        if (largest != index) 
        {
            std::swap(data[index], data[largest]);
            index = largest;
        } 
        else 
        {
            break;
        }
    }
}

void Heaps::remove(int index) 
{
    if (index < 0 || index >= get_size()) 
    {
        throw std::out_of_range("Index out of range");
    }

    data[index] = data.back();
    data.pop_back();
    
    if (index < get_size()) 
    {
        sift_up(index);
        sift_down(index);
    }
}

void Heaps::heapify(const std::vector<int>& array) 
{
    data = array;
    for (int i = (data.size() / 2) - 1; i >= 0; --i) 
    {
        sift_down(i);
    }
}

std::vector<int> Heaps::heap_sort(std::vector<int> array) 
{
    Heaps heap;
    heap.heapify(array);

    for (int i = array.size() - 1; i >= 0; --i) 
    {
        array[i] = heap.extract_max();
    }
    return array;
}
