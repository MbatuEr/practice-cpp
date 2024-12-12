#include <iostream>
#include <stdexcept>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

class Stacks
{
    private:
        int* arr;        // Single array for all three stacks
        int size;        // Total size of the array
        int top1, top2, top3; // Top indices for each stack
        int stackSize;   // Size of each stack in fixed division
        vector<int> min1, min2, min3; // Vectors to track the minimum for each stack

    public:
        Stacks(int totalsize);
        ~Stacks();
        void push(int stacknum, int value);
        int pop(int stacknum);
        bool is_empty(int stacknum);
        int getmin(int stacknum);
};