#ifndef HASHTABLES_H
#define HASHTABLES_H

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <unordered_set>

class HashTables 
{
    private:
        std::unordered_map<char, bool> uniq_char;
        std::unordered_map<char, int> char_count;
        std::unordered_map<std::string, int> word_index;
        std::unordered_map<int, int> length_index;
        std::unordered_map<std::string, int> notes;
        std::unordered_map<long long, bool> cache;
        
    public:
        bool hasAllUniqueCharacters(std::string& str);

        bool arePermutations(const std::string& str1, const std::string& str2);

        bool isPalindromePermutation(const std::string& str);

        // Checks if two strings are one edit away from each other.
        bool isOneAway(const std::string& str1, const std::string& str2);

        std::unordered_map<char, int> mostFrequentWord(const std::string& str);

        std::unordered_map<int, std::string> nearestRepetition(const std::vector<std::string>& str);

        std::pair<int, int> findShortestSequentialSubarray(const std::vector<std::string>& paragraph, const std::unordered_set<std::string>& keywords);

        std::pair<int,int> longestSubarrayWithDistinctEntries(const std::vector<std::string>& arr);

        int lengthOfLongestContainedInterval(const std::vector<int>& arr);

        std::unordered_map<std::string, double> averageOfTopThreeScores( std::vector<std::pair<std::string, int>>& scores);

        int allStringDecompositions(const std::string& sentence, const std::vector<std::string>& words);

        // Tests the conjecture for the first billion integers.
        bool testCollatz(int n);

        // Recursive function to compute Collatz sequence.
        bool collatzSequence(long long n);
};
 
 #endif // HASHTABLES_H