#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <list>

struct Event 
{
    int start, end;
};

struct Student 
{
    std::string name;
    int age;
};

struct Team 
{
    std::string name;
    int height;

    bool operator<(const Team& other) const;
};

// Custom hash function for std::vector<int>.
struct VectorHash 
{
    std::size_t operator()(const std::vector<int>& vec) const; 
};

class Sorting
{
    private:
        std::vector<int> data;

        // Returns the element at index i in 0(1) time.
        int elementAt(int i) const;

        // Prints the sorted arrays.
        void printLine(const std::vector<Team>& front_line, const std::vector<Team>& back_line);

        // Helper function to get the maximum value in the array.
        int getMax(const std::vector<int>& arr);

        // Counting sort for a specific digit represented by given value.
        void countingSort(std::vector<int>& arr, int exp);
    
    public:
        // Default constructor.
        Sorting();
        
        // Constructor for findElement().
        Sorting(const std::vector<int>& arr);

        // Merges two array in sorted order.
        void mergeSortedArrays(std::vector<int>& A, int m, std::vector<int>& B, int n);

        // Sorts an array so that all anagrams are next to each other.
        void groupAnagrams(std::vector<std::string>& strs);

        // Checks a given input whether it's in the array or not.
        int findInRotatedArray(const std::vector<int>& arr, int target);

        // Finds the given index in the list.
        int findElement(int x) const;

        // Splits the data into chunks and sorts each chunk.
        std::vector<std::vector<std::string>> splitIntoChunks(const std::vector<std::string>& data, int chunk_size);

        // Merges sorted chunks.
        std::vector<std::string> mergeChunks(const std::vector<std::vector<std::string>>& chunks);

        // Determines the max number of events that take place concurrently.
        int maxConcurrentEvents(std::vector<Event> events);

        // Computes the union of intervals.
        std::vector<Event> computeUnion(const std::vector<Event>& intervals);

        // Sorts string and integer pairs by comparing integers.
        void sortingStudentsByAge(std::vector<Student>& students);

        // Sorts two unsorted vectors into two different arrays.
        void teamPhoto(std::vector<Team>& team1, std::vector<Team>& team2);

        // Function to perform Quick Sort.
        void quickSort(int low, int high);

        // Prints the values in the data.
        void printValues();

        // Function to perform Bucket Sort.
        void bucketSort(std::vector<float>& arr);

        // Radix Sort implementation.
        void radixSort(std::vector<int>& arr);
};

#endif // SORTING_H