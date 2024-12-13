#include <iostream>
#include <vector>
#include <stack>
#include <stdexcept>


class SetOfStacks
{
    private:
    std::vector<std::stack<int>> stacks; // Vector of stacks
    int capacity;                        // Capacity of each stack

    public:
        SetOfStacks(int capacity);
        void push(int value);
        int pop();
        int popAt(int index);
        bool isEmpty() const;
        void printStacks() const;
};