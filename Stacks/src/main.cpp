#include "../header/stack.h"

using namespace std;
int main()
{
    Stacks st(15);

    st.push(1, 10);
    st.push(2, 20);
    st.push(3, 30);

    cout << "Pop from Stack 1: " << st.pop(1) << endl;
    cout << "Pop from Stack 2: " << st.pop(2) << endl;
    cout << "Pop from Stack 3: " << st.pop(3) << endl;
    
    cout << "--------------------------------------------------------------" << endl;

    st.push(1,10);
    st.push(1,7);
    st.push(1,5);

    cout << "Pop from stack 1: " << st.getmin(1) << endl;
    st.pop(1);
    cout << "Pop from stack 2: " << st.getmin(1) << endl;
    st.pop(1);
    cout << "Pop from stack 3: " << st.getmin(1) << endl;

    return 0;
}