#include "../header/setofstacks.h"

    SetOfStacks::SetOfStacks(int capacity) 
    {
        if (capacity <= 0) 
        {
            throw std::invalid_argument("Capacity must be greater than 0.");
        }
        this->capacity = capacity;
    }

    // Push an element onto the stack
    void SetOfStacks::push(int value) 
    {
        if (stacks.empty() || stacks.back().size() == capacity) 
        {
            // Create a new stack if no stacks exist or the last stack is full
            stacks.emplace_back(std::stack<int>());
        }
        stacks.back().push(value);
    }

    // Pop an element from the stack
    int SetOfStacks::pop() 
    {
        if (stacks.empty()) 
        {
            throw std::underflow_error("Set of Stacks is empty.");
        }

        int value = stacks.back().top();
        stacks.back().pop();

        // Remove the stack if it becomes empty
        if (stacks.back().empty()) 
        {
            stacks.pop_back();
        }
        return value;
    }

    // Pop an element from a specific stack
    int SetOfStacks::popAt(int index) 
    {
        if (index < 0 || index >= stacks.size()) 
        {
            throw std::out_of_range("Invalid stack index.");
        }

        if (stacks[index].empty()) 
        {
            throw std::underflow_error("Specified stack is empty.");
        }

        int value = stacks[index].top();
        stacks[index].pop();

        // Remove the stack if it becomes empty
        if (stacks[index].empty() && index == stacks.size() - 1) 
        {
            stacks.pop_back();
        }
        return value;
    }

    // Check if the set of stacks is empty
    bool SetOfStacks::isEmpty() const 
    {
        return stacks.empty();
    }

    // Print all stacks for debugging purposes
    void SetOfStacks::printStacks() const 
    {
        for (size_t i = 0; i < stacks.size(); ++i) 
        {
            std::cout << "Stack " << i + 1 << ": ";
            std::stack<int> temp = stacks[i]; // Copy the stack to print it
            std::vector<int> elements;

            while (!temp.empty()) 
            {
                elements.push_back(temp.top());
                temp.pop();
            }
            
            for (auto it = elements.rbegin(); it != elements.rend(); ++it) 
            {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }
    }

int main() 
{
    try {
        SetOfStacks stacks(3); // Create a SetOfStacks with capacity 3 per stack

        // Push elements
        stacks.push(1);
        stacks.push(2);
        stacks.push(3);
        stacks.push(4);
        stacks.push(5);
        stacks.push(6);

        std::cout << "Initial stacks:" << std::endl;
        stacks.printStacks();

        // Pop an element
        std::cout << "Popped: " << stacks.pop() << std::endl;

        std::cout << "Stacks after pop:" << std::endl;
        stacks.printStacks();

        // Pop an element from a specific stack
        std::cout << "Popped from stack 1: " << stacks.popAt(0) << std::endl;

        std::cout << "Stacks after popAt(0):" << std::endl;
        stacks.printStacks();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
