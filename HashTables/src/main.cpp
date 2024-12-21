#include "../header/HashTables.h"

int main()
{
    // check for unique characters
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
    std::cout << "--------------------------------------------------------" <<std::endl;

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
    std::cout << "--------------------------------------------------------" <<std::endl;

    // check for palindrome permutation
    std::string str = "teco cat";
    bool isPalindrome = hashTable.isPalindromePermutation(str);
    std::cout << "Input: " << str << std::endl;
    std::cout << "Is palindrome permutation: " << (isPalindrome ? "Yes" : "No") << std::endl;
    std::cout << "--------------------------------------------------------" <<std::endl;

    // check for one away
    std::string str3 = "pale";
    std::string str4 = "bale";
    bool isOneAway = hashTable.isOneAwayChecker(str3, str4);
    std::cout << "Input: " << str3 << ", " << str4 << std::endl;
    std::cout << "Is one away: " << (isOneAway ? "Yes" : "No") << std::endl;

    return 0;
}