#ifndef STACK_H
#define STACK_H

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
        void push(int value);

        void pop();

        int max() const;

        bool isWellFormed(const std::string& str);

        std::string simplifyPath(const std::string& path);

        void setJumpOrderRecursive(std::shared_ptr<PostingsListNode> node, int& order);

        void setJumpOrderIterative(std::shared_ptr<PostingsListNode> head);

        void printPostingsList(const std::shared_ptr<PostingsListNode>& head); 

        std::vector<int> findBuildingsWithSunsetView(const std::vector<int>& buildings);
};

#endif // STACK_H