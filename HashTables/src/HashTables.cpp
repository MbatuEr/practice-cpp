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