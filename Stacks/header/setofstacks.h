#ifndef SETOFSTACKS_H   
#define SETOFSTACKS_H   

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
        SetOfStacks(); 
        
        SetOfStacks(int capacity);

        void push(int value);

        int pop();

        int popAt(int index);

        bool isEmpty() const;

        void printStacks() const;

        void sortstack(std::stack<int>& a);
};

#endif // SETOFSTACKS_H