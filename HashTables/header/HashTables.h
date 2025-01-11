#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <unordered_set>

class HashTables 
{
    private:
        std::unordered_map<char, bool> uniqchar;
        std::unordered_map<char, int> charcount;
        std::unordered_map<std::string, int> wordIndex;
        std::unordered_map<int, int> lengthIndex;
        std::unordered_map<std::string, int> notes;
        std::unordered_map<long long, bool> cache;
        
    public:
        // Checks if a string has all unique characters.
        bool hasAllUniqueCharacters(std::string& str);

        // Checks if two strings are permutations of each other.
        bool arePermutations(const std::string& str1, const std::string& str2);

        // Checks if a string is a permutation of a palindrome.
        bool isPalindromePermutation(const std::string& str);

        // Checks if two strings size differ by one
        bool isOneAwayChecker(const std::string& str1, const std::string& str2);

        // Checks if two strings are one edit away from each other.
        bool isOneAway(const std::string& str1, const std::string& str2);

        // Finds the most frequent word in a string.
        std::unordered_map<char, int> mostFrequentWord(const std::string& str);

        // Finds the nearest repetition of a word in a string.
        std::unordered_map<int, std::string> nearestRepetition(const std::vector<std::string>& str);

        // Finds the shortest subarray that contains all keywords in a paragraph.
        std::pair<int, int> findShortestSequentialSubarray(const std::vector<std::string>& paragraph, const std::unordered_set<std::string>& keywords);

        // Finds the longest subarray with distinct entries.
        std::pair<int,int> longestSubarrayWithDistinctEntries(const std::vector<std::string>& arr);

        // Finds the length of the longest contained interval.
        int longestContainedInterval(const std::vector<int>& arr);

        // Finds the average of top three scores.
        std::unordered_map<std::string, double> averageOfTopThreeScores( std::vector<std::pair<std::string, int>>& scores);

        // Finds all string decompositions.
        int allStringDecompositions(const std::string& sentence, const std::vector<std::string>& words);

        // Tests the conjecture for the first billion integers.
        bool testCollatz(int n);

        // Recursive function to compute Collatz sequence.
        bool collatzSequence(long long n);
};
 