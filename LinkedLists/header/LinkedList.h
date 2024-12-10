#include <iostream>
#include <unordered_set>

class Node 
{
    public:
        int data;
        Node* next;

        Node(int value);
};

class LinkedList
{
    private:
        Node* head;

        // Sorts values of a list in reverse order
        static Node* reverse(Node* head);
        static LinkedList add_reverse_order(Node* l1, Node* l2);

    public:
        LinkedList();

        ~LinkedList();

        //LinkedList(const LinkedList& other);

        // Getter for head
        Node* get_head() const;

        // Adds a new node to the end of the list.
        void append(int value);

        // Removes duplicates from the list.
        void remove_duplicates();

        // Displays the list
        void print_list() const ;

        // Finds the kth to last element of the list.
        int find_to_kth_last(int k);

        // Delete the nth node of the list.
        void delete_middle_node();

        // Seperate values that greater than x from the values that less than x  
        void partition(int x);
};