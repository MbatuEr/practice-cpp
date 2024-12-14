#include <stack>
#include <iostream>

using namespace std;

class Queue
{
    private:
        stack<int> stack1;  // Main stack for enqueue operations
        stack<int> stack2;  // Temporary stack for dequeue operations

    public:
        void enqueue(int value);
        int dequeue();
        bool isEmpty() const;
        int size() const;
};