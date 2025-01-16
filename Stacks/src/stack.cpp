#include "../header/stack.h"

void Stacks::push(int value)
{
    mainstack.push(value);

    if(maxstack.empty() || value >= maxstack.top())
    {
        maxstack.push(value);
    }
    else
    {
        maxstack.push(maxstack.top());
    }
}

void Stacks::pop() 
{
    if (mainstack.empty())
    {
        throw std::underflow_error("Stack is empty.");
    }
    mainstack.pop();
    maxstack.pop();
}

int Stacks::max() const
{
    if (maxstack.empty())
    {
        throw std::underflow_error("Stack is empty.");
    }
    return maxstack.top();
} 

bool Stacks::isWellFormed(const std::string& str)
{
    std::unordered_map<char, char> bracked_pairs = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for (char ch : str) 
    {
        if (ch == '(' || ch == '{' || ch == '[') 
        {
            wellformed.push(ch);
        } 
        else if (ch == ')' || ch == '}' || ch == ']') 
        {    
            if (wellformed.empty() || wellformed.top() != bracked_pairs[ch]) 
            {
                return false;
            }
            wellformed.pop();
        }
    }

    return wellformed.empty();
}

std::string Stacks::simplifyPath(const std::string& path)
{
    std::stringstream ss(path);
    std::string token;

    while(std::getline(ss, token, '/'))
    {
        if(token == "." || token.empty())
        {
            continue;
        }
        else if(token == "..")
        {
            if(!stackpath.empty())
            {
                stackpath.pop();
            }
        }
        else
        {
            stackpath.push(token);
        }
    }
    std::string simplified_path;

    while (!stackpath.empty())
    {
        simplified_path = "/" + stackpath.top() + simplified_path;
        stackpath.pop();
    }

    return simplified_path.empty() ? "/" : simplified_path;
}

void Stacks::setJumpOrderRecursive(std::shared_ptr<PostingsListNode> node, int& order)
{
    if (!node || node->order != -1) 
    {
        return;  
    }
    node->order = order++;  
    
    setJumpOrderRecursive(node->jump, order);  
    setJumpOrderRecursive(node->next, order);  
}

void Stacks::setJumpOrderIterative(std::shared_ptr<PostingsListNode> head) 
{
    if (!head) return;

    stack_order.push(head);
    int order = 0;

    while (!stack_order.empty()) 
    {
        auto node = stack_order.top();
        stack_order.pop();

        if (node && node->order == -1) 
        {
            node->order = order++;  
            if (node->next) stack_order.push(node->next);  
            if (node->jump) stack_order.push(node->jump);  
        }
    }
}

void Stacks::printPostingsList(const std::shared_ptr<PostingsListNode>& head) 
{
    auto node = head;
    while (node) 
    {
        std::cout << "Node Order: " << node->order << "\n";
        node = node->next;
    }
}

std::vector<int> Stacks::findBuildingsWithSunsetView(const std::vector<int>& buildings)
{
    for (int i = buildings.size() - 1; i >= 0; --i) 
    { 
        while (!sunsetView.empty() && buildings[sunsetView.top()] <= buildings[i]) 
        {
            sunsetView.pop();
        }
        sunsetView.push(i);
    }
    std::vector<int> result;
    
    while (!sunsetView.empty()) 
    {
        result.push_back(sunsetView.top());
        sunsetView.pop();
    } 
    return result;
}