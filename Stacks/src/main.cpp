#include "../header/stack.h"

int main()
{
    Stacks st;

    // Max value in the stack.
    st.push(3);
    st.push(5);
    st.push(2);
    st.push(7);
    st.push(6);

    std::cout << "Current max: " << st.max() << "\n"; 
    st.pop();
    std::cout << "Current max after pop: " << st.max() << "\n"; 
    st.pop();
    std::cout << "Current max after pop: " << st.max() << "\n"; 
    std::cout << "-------------------------------------------------" << std::endl;

    // If the string well-formed.
    Stacks formed;
    std::string test1 = "([]){()}";
    std::string test2 = "[()[]{()()}]";
    std::string test3 = "{)";
    std::string test4 = "[()[]{()()";

    std::cout << "Test 1: " << (formed.isWellFormed(test1) ? "Well Formed" : "Not Well Formed") << "\n";
    std::cout << "Test 2: " << (formed.isWellFormed(test2) ? "Well Formed" : "Not Well Formed") << "\n";
    std::cout << "Test 3: " << (formed.isWellFormed(test3) ? "Well Formed" : "Not Well Formed") << "\n";
    std::cout << "Test 4: " << (formed.isWellFormed(test4) ? "Well Formed" : "Not Well Formed") << "\n";
    std::cout << "-------------------------------------------------" << std::endl;

    // Simplified path.
    Stacks simplified;

    std::string path1 = "/usr/bin/../bin/gcc";
    std::string path2 = "scripts//./../scripts/awkscripts/././";
    std::string path3 = "/a/./b/../../c/";
    std::string path4 = "/../";
    std::string path5 = "/home//foo/";

    std::cout << "Simplified Path 1: " << simplified.simplifyPath(path1) << "\n";
    std::cout << "Simplified Path 2: " << simplified.simplifyPath(path2) << "\n";
    std::cout << "Simplified Path 3: " << simplified.simplifyPath(path3) << "\n";
    std::cout << "Simplified Path 4: " << simplified.simplifyPath(path4) << "\n";
    std::cout << "Simplified Path 5: " << simplified.simplifyPath(path5) << "\n";
    std::cout << "-------------------------------------------------" << std::endl;

    // Posting list.
    Stacks lists;

    auto L = std::make_shared<PostingsListNode>();
    auto a = std::make_shared<PostingsListNode>();
    auto b = std::make_shared<PostingsListNode>();
    auto c = std::make_shared<PostingsListNode>();
    auto d = std::make_shared<PostingsListNode>();

    L->next = a; a->next = b; b->next = c; c->next = d;
    a->jump = c; c->jump = b; b->jump = d; d->jump = nullptr;

    std::cout << "Recursive Method:\n";
    int order = 0;
    lists.setJumpOrderRecursive(L, order);
    lists.printPostingsList(L);

    L->order = a->order = b->order = c->order = d->order = -1;

    std::cout << "\nIterative Method:\n";
    lists.setJumpOrderIterative(L);
    lists.printPostingsList(L);
    std::cout << "-------------------------------------------------" << std::endl; 

    // Sunset view.
    Stacks view;

    std::vector<int> buildings = {7, 4, 8, 2, 9};  // heights in east-to-west order.
    std::vector<int> result = view.findBuildingsWithSunsetView(buildings);

    std::cout << "Buildings with sunset views: ";
    for (int index : result) 
    {
        std::cout << buildings[index] << " ";
    }
    std::cout << std::endl;    
    std::cout << "-------------------------------------------------" << std::endl; 
    return 0;
}