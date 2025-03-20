#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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

        static Node* reverse(Node* head);
        
    public:
        LinkedList();

        ~LinkedList();

        Node* get_head() const;

        void append(int value);

        void remove_duplicates();

        void print_list() const ;

        int find_to_kth_last(int k);

        void delete_middle_node();

        void partition(int x);

        static LinkedList add_reverse_order(Node* l1, Node* l2);

        static LinkedList add_numbers_forward(Node* l1, Node* l2); 

        bool is_palindrome() const;

        int get_length(Node* head);

        Node* first_intersection(Node* head1, Node* head2);

        Node* detect_loop_start(Node* head);
};

#endif // LINKEDLIST_H