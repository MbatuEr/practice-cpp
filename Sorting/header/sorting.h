#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <list>

struct Event {
    int start;
    int end;
};

struct Student {
    std::string name;
    int age;
};

struct Team {
    std::string name;
    int height;

    bool operator<(const Team& other) const;
};

class Sorting
{
    private:
        std::vector<int> data;  
    
    public:
        Sorting();
        
        // Constructor.
        Sorting(const std::vector<int>& arr);

        // Merges two array in sorted order.
        void mergeSortedArrays(std::vector<int>& A, int m, std::vector<int>& B, int n);

        // Sorts an array so that all anagrams are next to each other.
        void groupAnagrams(std::vector<std::string>& strs);

        // Checks a given input whether it's in the array or not.
        int findInRotatedArray(const std::vector<int>& arr, int target);

        // Returns the element at index i in 0(1) time.
        int elementAt(int i) const;

        // Finds the given index in the list.
        int findElement(int x) const;

        // Split the vector into chunks.
        std::vector<std::vector<std::string>> splitIntoChunks(const std::vector<std::string>& data, int chunkSize);

        // Merges sorted chunks.
        std::vector<std::string> mergeChunks(const std::vector<std::vector<std::string>>& chunks);

        // Determines the max number of events that take place concurrently.
        int maxConcurrentEvents(std::vector<Event> events);

        // Computes the union of intervals.
        std::vector<Event> computeUnion(const std::vector<Event>& intervals);

        // Counting sort.
        void sortingStudentsByAge(std::vector<Student>& students);

        // Sorts two unsorted vectors into two different arrays.
        void teamPhoto(std::vector<Team>& team1, std::vector<Team>& team2);

        // Prints the sorted arrays.
        void printLine(const std::vector<Team>& front_line, const std::vector<Team>& back_line);

        // Partition function to rearrange elements around the pivot.
        int partition(std::vector<int>& arr, int low, int high);

        // Quick Sort function.
        void quickSort(std::vector<int>& arr, int low, int high);

        // Function to perform Bucket Sort.
        void bucketSort(std::vector<float>& arr);

        // Radix Sort implementation.
        void radixSort(std::vector<int>& arr); 

        // Helper function to get the maximum value in the array.
        int getMax(const std::vector<int>& arr);
        
        // Counting sort for a specific digit represented by given value.
        void countingSort(std::vector<int>& arr, int exp);
};

#endif // SORTING_H