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
        
    public:
        bool hasAllUniqueCharacters(std::string& str);
        bool arePermutations(const std::string& str1, const std::string& str2);
        bool isPalindromePermutation(const std::string& str);
        bool isOneAwayChecker(const std::string& str1, const std::string& str2);
        bool isOneAway(const std::string& str1, const std::string& str2);
        std::unordered_map<char, int> mostFrequentWord(const std::string& str);
        std::unordered_map<int, std::string> nearestRepetition(const std::vector<std::string>& str);
        std::pair<int, int> findShortestSubarray(const std::vector<std::string>& text, const std::unordered_set<std::string>& keywords);
};
