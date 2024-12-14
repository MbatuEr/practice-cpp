#include "../header/queue.h"

using namespace std;

int main()
{
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Dequeue: " << q.dequeue() << endl; 
    cout << "Dequeue: " << q.dequeue() << endl; 

    q.enqueue(4);
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl; 
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;    

    return 0;
}