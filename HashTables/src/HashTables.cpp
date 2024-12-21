#include "../header/HashTables.h"


bool HashTables::hasAllUniqueCharacters(std::string& str)
{
    uniqchar.clear();
    for (char c : str)
    {
        if (uniqchar.find(c) != uniqchar.end())
        {
            return false;
        }
        uniqchar[c] = true;
    }
    return true;
}

bool HashTables::arePermutations(const std::string& str1, const std::string& str2)
{
    if (str1.size() != str2.size())
    {
        return false; // Different lengths cannot be permutations
    }

    charcount.clear();
    
    for (char c : str1)
    {
        charcount[c]++;
    }

    for (char c : str2)
    {
        if (charcount.find(c) == charcount.end() || charcount[c] == 0)
        {
            return false;
        }
        charcount[c]--;
    }

    return true;
}

bool HashTables::isPalindromePermutation(const std::string& str)
{
    charcount.clear();
    int oddCount = 0;
    for (char c : str)
    {
        if (c == ' ')
        {
            continue;
        }
        charcount[c]++;
        if (charcount[c] % 2 == 0)
        {
            oddCount--;
        }
        else
        {
            oddCount++;
        }
    }
    return oddCount <= 1;
}

bool HashTables::isOneAwayChecker(const std::string& str1, const std::string& str2)
{
    if (abs(str1.size() - str2.size()) >= 2)
    {
        return false;   
    }
    else
    {
        return isOneAway(str1, str2);
    }
}    

bool HashTables::isOneAway(const std::string& str1, const std::string& str2)
{
    charcount.clear();
    int diffCount = 0;

    const std::string& shorter = str1.size() <= str2.size() ? str1 : str2;
    const std::string& longer = str1.size() <= str2.size() ? str2 : str1;

    for (char c : shorter)
    {
        charcount[c]++;
    }

    for (char c : longer)
    {
        if (charcount.find(c) != charcount.end() && charcount[c] > 0)
        {
            charcount[c]--;
        }
        else
        {
            diffCount++;
        }
    }
    return diffCount <= 1;
}

    