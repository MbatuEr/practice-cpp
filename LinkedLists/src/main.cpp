#include "../header/LinkedList.h"

int main()
{
    LinkedList list;
    
    list.append(3);
    list.append(5);
    list.append(8);
    list.append(5);
    list.append(8);
    list.append(5);
    list.append(3);

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

    return 0;
}