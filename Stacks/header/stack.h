#include <iostream>
#include <stdexcept>
#include <stack>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <memory>

struct PostingsListNode 
{
    int order = -1;
    std::shared_ptr<PostingsListNode> next;
    std::shared_ptr<PostingsListNode> jump;
};

class Stacks
{
    private:
        std::stack<int> mainstack;
        std::stack<int> maxstack;
        std::stack<int> wellformed;
        std::stack<std::string> stackpath;
        std::stack<std::shared_ptr<PostingsListNode>> stack_order;
        std::stack<int> sunsetView; 

    public:
        // Push a value onto the stack.
        void push(int value);

        // Pop the top value from the stack.
        void pop();

        // Returns the maximum value in the stock.
        int max() const;

        // Checks strings if they are well-formed.
        bool isWellFormed(const std::string& str);

        // Simplifies the given paths.
        std::string simplifyPath(const std::string& path);

        // Recursive solution for setting jump order.
        void setJumpOrderRecursive(std::shared_ptr<PostingsListNode> node, int& order);

        // Iterative solution for setting jump order.
        void setJumpOrderIterative(std::shared_ptr<PostingsListNode> head);

        // Prints the postings list with orders.
        void printPostingsList(const std::shared_ptr<PostingsListNode>& head); 

        // Finds the windows that have a sunset view.
        std::vector<int> findBuildingsWithSunsetView(const std::vector<int>& buildings);
};