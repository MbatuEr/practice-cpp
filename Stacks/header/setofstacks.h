#include <iostream>
#include <vector>
#include <stack>
#include <stdexcept>


class SetOfStacks
{
    private:
        std::vector<std::stack<int>> stacks; 
        int capacity;                        

    public:
        // Default constructor.
        SetOfStacks(); 
        
        SetOfStacks(int capacity);

        // Push an element onto the stack.
        void push(int value);

        // Pop an element from the stack.
        int pop();

        // Pop an element from a specific stack.
        int popAt(int index);

        // Check if the set of stacks is empty.
        bool isEmpty() const;

        // Print all stacks for debugging purposes.
        void printStacks() const;

        // Sorts the stack smallest to highest value.
        void sortstack(std::stack<int>& a);
};