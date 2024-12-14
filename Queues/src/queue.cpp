#include "../header/queue.h"

using namespace std;

void Queue::enqueue(int value)
{
    stack1.push(value);
}

int Queue::dequeue()
{
    if (stack2.empty())
    {
        // Transfer elements from stack1 to stack2 if stack2 is empty
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
     // If stack2 is still empty, the queue is empty
    if (stack2.empty())
    {
        cerr << "Queue is empty! " << endl;
        return -1;
    }
    
    int value = stack2.top();
    stack2.pop();
    return value;
}

bool Queue::isEmpty() const
{
    return stack1.empty() && stack2.empty();
}

int Queue::size() const
{
    return stack1.size() + stack2.size();
}