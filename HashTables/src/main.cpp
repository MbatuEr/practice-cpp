#include "../header/HashTables.h"

int main()
{
    //std::unordered_map<char, bool> table;
    HashTables hashTable;

    std::string input = "asdfghjklip";

    if (hashTable.hasAllUniqueCharacters(input))
    {
        std::cout << "All characters are unique." << std::endl;
    }
    else
    {
        std::cout << "Not all characters are unique." << std::endl;
    }

    // check for permutations
    std::string str1 = "asdfghjkl";
    std::string str2 = "pkjhgfdas";

    if (hashTable.arePermutations(str1, str2))
    {
        std::cout << "The strings are permutations of each other." << std::endl;
    }
    else
    {
        std::cout << "The strings are not permutations of each other." << std::endl;
    }

    return 0;
}