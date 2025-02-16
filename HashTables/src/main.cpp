#include "../header/HashTables.h"

int main()
{
    // Unique characters.
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

    // Permutation.
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

    // Palindrome permutation.
    std::string str = "tcao cat";
    bool isPalindrome = hashTable.isPalindromePermutation(str);
    std::cout << "Input: " << str << std::endl;
    std::cout << "Is palindrome permutation: " << (isPalindrome ? "Yes" : "No") << std::endl;
    std::cout << "--------------------------------------------------------" <<std::endl;

    // One edit away checker.
    std::string str3 = "pale";
    std::string str4 = "bale";
    bool isOneAway = hashTable.isOneAway(str3, str4);
    std::cout << "Input: " << str3 << ", " << str4 << std::endl;
    std::cout << "Is one away: " << (isOneAway ? "Yes" : "No") << std::endl;
    std::cout << "--------------------------------------------------------" <<std::endl;

    // Most frequent word.
    std::string str5 = "hello world";
    std::unordered_map<char, int> freqWord = hashTable.mostFrequentWord(str5);
    std::cout << "Input: " << str5 << std::endl;    
    std::cout << "Most frequent word is " << freqWord.begin()->first << " with " <<freqWord.begin()->second << " times" << std::endl;
    std::cout << "--------------------------------------------------------" <<std::endl;

    // Nearest repetition.
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

    // Shortest subarray.
    std::vector<std::string> text = {
        "Given", "permutation", "string,", "write", "a", "palindrome", "to", "check", "if", "it", "is", "a", 
        "palindrome", "of", "a", "permutation", "A", "check", "is", "a", "word", "or", 
        "phrase", "that", "is", "the", "same", "forwards", "and", "backwards.", "A", "palindrome", 
        "is", "just", "rearrangement", "of", "permutation", "The", "palindrome", "does", "not", 
        "need", "to", "be", "limited", "to", "permutation", "just", "does"
    };

    std::unordered_set<std::string> keywords = {"palindrome", "permutation"};
    std::pair<int, int> result = hashTable.findShortestSequentialSubarray(text, keywords);

    if (result.first != -1) 
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
    std::cout << "--------------------------------------------------------" <<std::endl;

    // Longest subarray.
    std::vector<std::string> arr = {"f", "s", "s", "e", "t", "w", "e", "n", "a", "e"};
    std::pair<int, int> longestSubarray = hashTable.longestSubarrayWithDistinctEntries(arr);
    std::cout << "Input: ";
    for (auto& word : arr)
    {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    std::cout << "Longest subarray with distinct entries: ";
    for (int i = longestSubarray.first; i <= longestSubarray.second; ++i) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" <<std::endl;

    // Longest contained interval.
    std::vector<int> intArr = {3, -2, 7, 9, 8, 1, 6, 0, -1, 5, 4};
    int length = hashTable.longestContainedInterval(intArr);
    std::cout << "Input: ";
    for (auto& num : intArr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "Length of longest contained interval: " << length << std::endl;
    std::cout << "--------------------------------------------------------" <<std::endl;

    // Average of top three scores.
    std::vector<std::pair<std::string, int>> scores = {{"John", 60}, {"Jane", 90}, {"John", 35}, {"Jane", 20}, {"Jane", 50}, {"jack", 80}, {"jack", 95}, {"aby", 100}, {"aby", 95}, {"aby", 80}};
    std::unordered_map<std::string, double> avgScores = hashTable.averageOfTopThreeScores(scores);
    std::cout << "Input: ";
    for (auto& score : scores)
    {
        std::cout << score.first << " " << score.second << ", ";
    }
    std::cout << std::endl;
    for (auto& avgScore : avgScores)
    {
        std::cout << avgScore.first << " " << avgScore.second << std::endl;
    }
    std::cout << "--------------------------------------------------------" <<std::endl;

    // String decompositions.
    std::string s = "amanaplanacandl";
    std::vector<std::string> words = {"nac", "ana", "pla"};
    int starting_indice = hashTable.allStringDecompositions(s, words);
    std::cout << "Input: " << s << std::endl;
    std::cout << "All string decompositions: ";
    for (int i = starting_indice; i < starting_indice + words.size() * words[0].size(); ++i)
    {
        std::cout << s[i];
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" <<std::endl;

    // Collatz conjecture.
    int n = 1000000;
    if (hashTable.testCollatz(n))
    {
        std::cout << "Collatz Conjecture is true for all numbers from 1 to " << n << std::endl;
    }
    else
    {
        std::cout << "Collatz Conjecture is false for all numbers from 1 to " << n << std::endl;
    }
    std::cout << "--------------------------------------------------------" <<std::endl;

    return 0;
}