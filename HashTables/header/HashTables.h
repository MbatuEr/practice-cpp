#include <iostream>
#include <unordered_map>
#include <string>

class HashTables 
{
    private:
        std::unordered_map<char, bool> uniqchar;
        std::unordered_map<char, int> charcount;
    public:
        //HashTables(std::unordered_map<char, bool> table);
        bool hasAllUniqueCharacters(std::string& str);
        bool arePermutations(const std::string& str1, const std::string& str2);
        bool isPalindromePermutation(const std::string& str);
        bool isOneAwayChecker(const std::string& str1, const std::string& str2);
        bool isOneAway(const std::string& str1, const std::string& str2);
        
};
