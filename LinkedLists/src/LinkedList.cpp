#include "../header/LinkedList.h"

Node::Node(int value) : data(value), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList()
{
    Node* current = head;
    while (current)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }    
};

Node* LinkedList::get_head() const 
{
    return head;
}

void LinkedList::append(int value)
{
    if(!head)
    {
        head = new Node(value);
        return;
    }

    Node* current = head;
    while (current->next)
    {
        current = current->next;
    }

    current->next = new Node(value);
}

void LinkedList::remove_duplicates()
{
    if (!head)
    {
        return;
    }

    std::unordered_set<int> seen;
    Node* current = head;
    Node* prev = nullptr;

    while (current)
    {
        if (seen.find(current->data) != seen.end())
        {
            prev->next = current->next;
            delete current;
        }
        else
        {
            seen.insert(current->data);
            prev = current;
        }
        current = prev->next;
        
    }
}

void LinkedList::print_list() const
{
    Node* current = head;
    while (current)
    {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr\n";
}

int LinkedList::find_to_kth_last(int k)
{
    if (!head)
    {
        throw std::invalid_argument("List is empty");
    }

    Node* first = head;
    Node* second = head;

    // Move 'first' pointer k steps ahead
    for (int i = 0; i < k; i++)
    {
        if (!first)
        {
            throw std::invalid_argument("k is larger than the list size");
        }
        first = first->next;
    }

    // Move both pointers until 'first' reaches the end
    while (first)
    {
        first = first->next;
        second = second->next;
    }

    // 'second' now points to the k-th to last element
    return second->data;
}

void LinkedList::delete_middle_node()
{
    if(!head || !head->next ||!head->next)
    {
        std::cout << "List is too short to have a middle node." << std::endl;
        return;
    }
    
    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;

    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev)
    {
        prev->next =slow->next;
        delete slow;
    }
}

void LinkedList::partition(int x)
{
    if (!head || !head->next)
    {
        return;
    }
    
    Node* less_head = new Node(0); // Dummy head for less partition.
    Node* greater_head = new Node(0); // Dummy head for greater partition.
    Node* less = less_head;
    Node* greater = greater_head;
    
    // Traverse the list
    Node* current = head;
    while (current)
    {
        if (current->data < x)
        {
            less->next = current;
            less = less->next;
        }
        else 
        {
            greater->next = current;
            greater = greater->next;
        }
        current = current->next;
    }

    // Connect the two partitions.
    less->next = greater_head->next;
    greater->next = nullptr;
    
    // Update head to the start of the less partition.
    head = less_head->next;

    // Free dummy nodes.
    delete less_head;
    delete greater_head;
}
