#include "../header/setofstacks.h"

    SetOfStacks::SetOfStacks() {}  
    
    SetOfStacks::SetOfStacks(int capacity) 
    {
        if (capacity <= 0) 
        {
            throw std::invalid_argument("Capacity must be greater than 0.");
        }
        this->capacity = capacity;
    }

    void SetOfStacks::push(int value) 
    {
        if (stacks.empty() || stacks.back().size() == capacity) 
        {
            stacks.emplace_back(std::stack<int>());
        }
        stacks.back().push(value);
    }

    int SetOfStacks::pop() 
    {
        if (stacks.empty()) 
        {
            throw std::underflow_error("Set of Stacks is empty.");
        }

        int value = stacks.back().top();
        stacks.back().pop();

        if (stacks.back().empty()) 
        {
            stacks.pop_back();
        }
        return value;
    }

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

        if (stacks[index].empty() && index == stacks.size() - 1) 
        {
            stacks.pop_back();
        }
        return value;
    }

    bool SetOfStacks::isEmpty() const 
    {
        return stacks.empty();
    }

    void SetOfStacks::printStacks() const 
    {
        for (size_t i = 0; i < stacks.size(); ++i) 
        {
            std::cout << "Stack " << i + 1 << ": ";
            std::stack<int> temp = stacks[i]; 
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

    void SetOfStacks::sortstack(std::stack<int>& s)
    {
        std::stack<int> tempstack;

        while (!s.empty())
        {
            int current = s.top();
            s.pop();

            while (!tempstack.empty() && tempstack.top() > current)
            {
                s.push(tempstack.top());
                tempstack.pop();
            }

            tempstack.push(current);
        }
        while (!tempstack.empty())
        {
            s.push(tempstack.top());
            tempstack.pop();
        }
    }

int main() 
{
    try {
        SetOfStacks stacks(3);

        stacks.push(1);
        stacks.push(2);
        stacks.push(3);
        stacks.push(4);
        stacks.push(5);
        stacks.push(6);

        std::cout << "Initial stacks:" << std::endl;
        stacks.printStacks();

        std::cout << "Popped: " << stacks.pop() << std::endl;

        std::cout << "Stacks after pop:" << std::endl;
        stacks.printStacks();

        std::cout << "Popped from stack 1: " << stacks.popAt(0) << std::endl;

        std::cout << "Stacks after popAt(0):" << std::endl;
        stacks.printStacks();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "---------------------------------------------------" << std::endl;
    
    std::stack<int> s;

    s.push(34);
    s.push(3);
    s.push(31);
    s.push(98);
    s.push(92);
    s.push(23);
    
    std::cout << "Original Stack: ";
    std::stack<int> temp = s;
    
    while (!temp.empty()) 
    {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << std::endl;

    SetOfStacks sorter;
    sorter.sortstack(s);

    std::cout << "Sorted Stack: ";
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;

    return 0;
}
