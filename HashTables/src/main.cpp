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
    std::cout << "--------------------------------------------------------" <<std::endl;

    // check for most frequent word
    std::string str5 = "hello world";
    std::unordered_map<char, int> freqWord = hashTable.mostFrequentWord(str5);
    std::cout << "Input: " << str5 << std::endl;    
    std::cout << "Most frequent word is " << freqWord.begin()->first << " with " <<freqWord.begin()->second << " times" << std::endl;
    std::cout << "--------------------------------------------------------" <<std::endl;

    // check for nearest repetition
    std::vector<std::string> vec = {{"hello"}, {"world"}, {"look"}, {"at"}, {"what"}, {"hello"}, {"what"}};
    std::unordered_map<int, std::string> nearestRep = hashTable.nearestRepetition(vec);
    std::cout << "Input: ";
    for (auto& word : vec)
    {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    std::cout << "Nearest repetition is between two '" << nearestRep.begin()->second << "' words and the distance is " << nearestRep.begin()->first << std::endl;
    std::cout << "--------------------------------------------------------" <<std::endl;

    // check for shortest subarray  
    std::vector<std::string> text = {
        "Given", "a", "string,", "write", "a", "function", "to", "check", "if", "it", "is", "a", 
        "permutation", "of", "a", "palindrome", "A", "palindrome", "is", "a", "word", "or", 
        "phrase", "that", "is", "the", "same", "forwards", "and", "backwards.", "A", "permutation", 
        "is", "a", "rearrangement", "of", "letters.", "The", "palindrome", "does", "not", 
        "need", "to", "be", "limited", "to", "just", "dictionary", "words"
    };

    std::unordered_set<std::string> keywords = {"permutation", "palindrome"};
    std::pair<int, int> result = hashTable.findShortestSubarray(text, keywords);

    if (result.first != -1 && result.second != -1) 
    {
        std::cout << "Shortest subarray: ";
        for (int i = result.first; i <= result.second; ++i) 
        {
            std::cout << text[i] << " ";
        }
        std::cout << std::endl;
    } else 
    {
        std::cout << "No subarray contains all the keywords." << std::endl;
    }

    return 0;
}