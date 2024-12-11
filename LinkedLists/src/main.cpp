#include "../header/LinkedList.h"

int main()
{
    LinkedList list, list1, list2, list3, list4, list5, list6;
    
    list.append(3);
    list.append(5);
    list.append(8);
    list.append(5);
    list.append(8);
    list.append(5);
    list.append(3);

    list1.append(7);
    list1.append(1);
    list1.append(6);

    list2.append(5);
    list2.append(9);
    list2.append(2);

    list3.append(6);
    list3.append(1);
    list3.append(7);

    list4.append(2);
    list4.append(9);
    list4.append(5);

    list5.append(4);

    list6.append(3);
    list6.append(5);
    list6.append(8);
    list6.append(7);
    list6.append(6);
    list6.append(4);
    list6.append(1);

    std::cout << "\nOriginal List : \n";
    list.print_list();

    int k;
    std::cout << "\nInsert the k-th element : ";
    std::cin >> k;
    
    try
    {
        int result = list.find_to_kth_last(k);
        std::cout << "The " << k << "-th to last element is : " << result << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\nDeleting the middle node... " << std::endl;
    list.delete_middle_node();

    std::cout << "List after deleting the middle node : ";

    list.print_list();

    int partition_value = 6;
    std::cout << "\nPartitioning around value : " << partition_value << std::endl;
    list.partition(partition_value);

    std::cout << "List after partition : ";
    list.print_list();

    std::cout << "\nList 1: ";
    list1.print_list();

    std::cout << "List 2: ";
    list2.print_list();

    LinkedList result = LinkedList::add_numbers_reverse(list1.get_head(), list2.get_head());

    std::cout << "Sum of list1 and list2 (reverse order): ";
    result.print_list();

    std::cout << "\nList 3: ";
    list3.print_list();

    std::cout << "List 4: ";
    list4.print_list();

    LinkedList result_forward = LinkedList::add_numbers_forward(list3.get_head(), list4.get_head());

    std::cout << "Sum of list3 and list4 (Forward Order): ";
    result_forward.print_list();

    list.remove_duplicates();
    std::cout << "\nList After Removing Duplicates : ";

    list.print_list();

    list.append(5);
    list.append(3);

    std::cout << "\nIs 'list' a Palindrome? " << (list.is_palindrome() ? "Yes" : "No") << std::endl;

    std::cout << "Is 'list1' a Palindrome? " << (list1.is_palindrome() ? "Yes" : "No") << std::endl;

    Node* intersecting_node = new Node(15);
    list2.get_head()->next->next->next = intersecting_node;
    list5.get_head()->next = intersecting_node;
    intersecting_node->next = new Node(20);

    Node* intersection = list.first_intersection(list2.get_head(), list5.get_head());

    if (intersection)
    {
        std::cout << "\nThe lists intersect at node with value: " << intersection->data << std::endl;
    }
    else {
        std::cout << "\nThe lists do not intersect." << std::endl;
    }

    list6.get_head()->next->next->next->next->next->next->next = list6.get_head()->next;

    Node* loop_start = list6.detect_loop_start(list6.get_head());

    if (loop_start)
    {
        std::cout << "\nThe loop starts at the node : " << loop_start->next->data << std::endl;
    }
    else {
        std::cout << "\nThe list does not loop " << std::endl;
    }

    loop_start->next = nullptr; // Breaks the loop

    return 0;
}