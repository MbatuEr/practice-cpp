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
    if(!head || !head->next ||!head->next->next)
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

LinkedList LinkedList::add_reverse_order(Node* l1, Node* l2)
{
    LinkedList result;
    int carry = 0;

    while (l1 || l2 || carry) 
    {
        int sum = carry;
        if (l1) 
        {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2) 
        {
            sum += l2->data;
            l2 = l2->next;
        }
        result.append(sum % 10);
        carry = sum / 10;
    }

    return result;   
}

Node* LinkedList::reverse(Node* head)
{
    Node* prev = nullptr;
    Node* current = head;

    while (current)
    {
        Node* next = current->next; 
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
} 

LinkedList LinkedList::add_numbers_forward(Node* l1, Node* l2) 
{
    // Reverse both input lists
    l1 = reverse(l1);
    l2 = reverse(l2);

    // Add the reversed lists
    LinkedList reversed_result = add_reverse_order(l1, l2);

    // Reverse the result back to forward order
    reversed_result.head = reversed_result.reverse(reversed_result.head);

    return reversed_result;
}

bool LinkedList::is_palindrome() const 
{
    if(!head || !head->next)
    {
        return true;    // a single-node or an empty list is a palindrome
    }

    Node* slow = head;
    Node* fast = head;
    
    // use to pointers to find the middle of the list
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    Node* second_half = reverse(slow);
    Node* first_half = head;
    
    bool is_palindrome = true;
    // Compare the two half of the list
    while (second_half)
    {
        if (first_half->data != second_half->data)
        {
            is_palindrome =false;
            break;
        }
        first_half = first_half->next;
        second_half = second_half->next;
        
    }
    return is_palindrome;
}

int LinkedList::get_length(Node* head)
{
    int length = 0;
    while (head)
    {
        head = head->next;
        length++;
    }
    return length;
}

Node* LinkedList::first_intersection(Node* head1, Node* head2)
{
    if(!head1 || !head2) return nullptr;

    // Get the lengths of both lists
    int len1 = get_length(head1);
    int len2 = get_length(head2);

    // Align both lists by skipping nodes in the longer list
    Node* longer = len1 > len2 ? head1 : head2;
    Node* shorter = len1 > len2 ? head2 : head1;

    int length_diff = abs(len1 - len2);

    for (int i = 0; i < length_diff; i++)
    {
        longer = longer->next;
    }

     // Traverse both lists together to find the intersection point
    while (longer && shorter)
    {
       if (longer == shorter) return longer; // interaction found
       longer = longer->next;
       shorter = shorter->next;
    }

    return nullptr; // no interaction
}

Node* LinkedList::detect_loop_start(Node* head)
{
    if(!head || !head->next) return nullptr;

    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow)
        {
            break;
        }
    }
    if(!fast || !fast->next) return nullptr;

    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}