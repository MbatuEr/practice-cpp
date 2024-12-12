#include "../header/stack.h"

using namespace std;

Stacks::Stacks(int totalsize)
{
    size = totalsize;
    arr = new int[size];
    stackSize = size / 3;
    top1 = -1;                      // Stack 1 starts from index 0
    top2 = stackSize - 1;           // Stack 2 starts from index 1
    top3 = (2 * stackSize) - 1;     // Stack 3 starts from index 2

    // Inıtıalize min tracking for each stack
    min1.push_back(INT_MAX);
    min2.push_back(INT_MAX);
    min3.push_back(INT_MAX);
}

Stacks::~Stacks()
{
    delete[] arr;
}

void Stacks::push(int stacknum, int value)
{
    switch (stacknum)
    {
        case 1:
            if (top1 < stackSize -1)
            {
                arr[++top1] = value;
                min1.push_back(std::min(min1.back(), value)); // update min
            } else 
            {
                throw overflow_error("Stack 1 overflow");
            }
            break;
        case 2:
            if (top2 < (2 * stackSize) -1)
            {
                arr[++top2] = value;
                min2.push_back(std::min(min1.back(), value)); // update min
            } else 
            {
                throw overflow_error("Stack 2 overflow");
            }
            break;
        case 3:
            if (top3 < size -1)
            {
                arr[++top3] = value;
                min3.push_back(std::min(min1.back(), value)); // update min
            } else 
            {
                throw overflow_error("Stack 3 overflow");
            }
            break;

        default:
            throw invalid_argument("Invalid stack number");
    }
}

int Stacks::pop(int stacknum)
{
    switch (stacknum)
    {
        case 1:
            if (top1 >= 0)
            {
                min1.pop_back();
                return arr[top1--];
                
            } else 
            {
                throw underflow_error("Stack 1 underflow");
            }
            break;
        case 2:
            if (top2 >= stackSize)
            {
                min2.pop_back();
                return arr[top2--];
            } else 
            {
                throw underflow_error("Stack 2 underflow");
            }
            break;
        case 3:
            if (top3 >= 2* stackSize)
            {
                min3.pop_back();
                return arr[top3--];
            } else 
            {
                throw underflow_error("Stack 3 underflow");
            }
            break;
        default:
            throw invalid_argument("Invalid stack number");
    }
}

bool Stacks::is_empty(int stackNum) 
{
    switch (stackNum) 
    {
        case 1:
            return top1 == -1;
        case 2:
            return top2 == stackSize - 1;
        case 3:
            return top3 == (2 * stackSize) - 1;
        default:
            throw invalid_argument("Invalid Stack Number");
    }
}

int Stacks::getmin(int stacknum)
{
    switch (stacknum)
    {
    case 1:
        if (top1 >= 0)
        {
            return min1.back();
        } else 
        {
            throw underflow_error("Stack 1 is empty.");
        }
    case 2:
        if (top2 >= stackSize)
        {
            return min2.back();
        } else 
        {
            throw underflow_error("Stack 2 is empty.");
        }
    case 3:
        if (top3 >= 2 * stackSize)
        {
            return min3.back();
        } else 
        {
            throw underflow_error("Stack 3 is empty.");
        }

    default:
        throw invalid_argument("Invalid stack number.");
    }
}