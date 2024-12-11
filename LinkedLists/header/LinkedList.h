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

        // Adds values ​​in two lists in reverse order 
        static LinkedList add_numbers_reverse(Node* l1, Node* l2);

        // Adds values ​​in two lists in forward order
        static LinkedList add_numbers_forward(Node* l1, Node* l2); 
        
        // Checks the lists if it's palindrome
        bool is_palindrome() const;
        
        // Gets the lenght of a list
        int get_length(Node* head);

        // Finds if there is an interaction between two lists.
        Node* first_intersection(Node* head1, Node* head2);

        // Detecs if there is a loop in the list
        Node* detect_loop_start(Node* head);
};