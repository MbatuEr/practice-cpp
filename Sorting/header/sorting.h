#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <list>
#include <random>

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

        int elementAt(int i) const;

        void printLine(const std::vector<Team>& front_line, 
                        const std::vector<Team>& back_line);

        void countingSort(std::vector<int>& arr, int exp);

        // Finds kth largest integer in the list.
        int quickSelect(std::vector<int>& nums, int left, int right, int k);
        
        // An optimized quick sort algorithm.
        int partition(std::vector<int>& nums, int left, int right);

    public:
        Sorting();
        
        // Constructor for findElement().
        Sorting(const std::vector<int>& arr);

        void mergeSortedArrays(std::vector<int>& A, int m, std::vector<int>& B, int n);

        void groupAnagrams(std::vector<std::string>& strs);

        // Checks a given input whether it's in the array or not.
        int findInRotatedArray(const std::vector<int>& arr, int target);

        int findElement(int x) const;

        std::vector<std::vector<std::string>> splitIntoChunks(
                                const std::vector<std::string>& data, int chunk_size);

        std::vector<std::string> mergeChunks(
                        const std::vector<std::vector<std::string>>& chunks);

        int maxConcurrentEvents(std::vector<Event> events);

        std::vector<Event> computeUnion(const std::vector<Event>& intervals);

        void sortingStudentsByAge(std::vector<Student>& students);

        void teamPhoto(std::vector<Team>& team1, std::vector<Team>& team2);

        void quickSort(int low, int high);

        void printValues();

        void bucketSort(std::vector<float>& arr);

        void radixSort(std::vector<int>& arr);

        int kthLargestNumber(std::vector<int>& nums, int k);        
};

#endif // SORTING_H