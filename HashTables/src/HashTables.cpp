#include "../header/HashTables.h"
#include <algorithm>

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

std::unordered_map<char, int> HashTables::mostFrequentWord(const std::string& str)
{
    charcount.clear();
    for (char c : str)
    {
        charcount[c]++;
    }

    int maxCount = 0;
    char maxChar = ' ';
    for (auto& it : charcount)
    {
        if (it.second > maxCount)
        {
            maxCount = it.second;
            maxChar = it.first;
        }
    }
    return {{maxChar, maxCount}};
}    

std::unordered_map<int, std::string> HashTables::nearestRepetition(const std::vector<std::string>& str)
{
    wordIndex.clear();
    int minDist = __INT_MAX__;
    int dist = 0;
    std::string word;
    for (int i = 0; i < str.size(); i++)
    {
        if (wordIndex.find(str[i]) != wordIndex.end())
        {
            dist = i - wordIndex[str[i]];
            if (dist < minDist)
            {
                minDist = dist;
                word = str[i];
            }
        }
        wordIndex[str[i]] = i;
    }
    
    return {{minDist, word}};
}    

std::pair<int, int> HashTables::findShortestSequentialSubarray(const std::vector<std::string>& paragraph, const std::unordered_set<std::string>& keywords) 
{ 
    int start = 0; 
    int matched_keywords = 0; 
    std::pair<int, int> result = {-1, -1}; 
    int min_length = __INT_MAX__; 

    for (int end = 0; end < paragraph.size(); ++end) 
    {
        const std::string& word = paragraph[end]; 
        if (keywords.count(word)) 
        { 
            wordIndex[word]++;
            if (wordIndex[word] == 1) 
            { 
                ++matched_keywords;
            }
        }

        while (matched_keywords == keywords.size()) 
        {
            int window_length = end - start + 1;
            if (window_length < min_length) {
                min_length = window_length;
                result = {start, end};
            }

            const std::string& start_word = paragraph[start]; 
            if (keywords.count(start_word)) 
            { 
                wordIndex[start_word]--;
                if (wordIndex[start_word] == 0) 
                { 
                    --matched_keywords;
                }
            }
            ++start; 
        }
    }
    return result;
}

std::pair<int,int> HashTables::longestSubarrayWithDistinctEntries(const std::vector<std::string>& arr)
{
    wordIndex.clear();
    int start = 0;
    std::pair<int, int> result = {-1, -1};
    for (int end = 0; end < arr.size(); end++)
    {
        if (wordIndex.find(arr[end]) == wordIndex.end())
        {
            wordIndex[arr[end]]++; 
        }
        else
        {
            while (wordIndex.find(arr[end]) != wordIndex.end())
            {
                wordIndex.erase(arr[start]);
                start++;
            }
            wordIndex[arr[end]]++;
        }
        if (end - start > result.second - result.first)
        {
            result = {start, end};
        }
    }
    return result;
}

int HashTables::longestContainedInterval(const std::vector<int>& arr)
{
    lengthIndex.clear();
    int max_length = 0;
    for (int num : arr)
    {
        if (lengthIndex.find(num) == lengthIndex.end())
        {
            int left = lengthIndex.find(num - 1) != lengthIndex.end() ? lengthIndex[num - 1] : 0;
            int right = lengthIndex.find(num + 1) != lengthIndex.end() ? lengthIndex[num + 1] : 0;
            int length = left + right + 1;
            lengthIndex[num] = length;
            lengthIndex[num - left] = length;
            lengthIndex[num + right] = length;
            max_length = std::max(max_length, length);
        }
    }
    return max_length;
}

std::unordered_map<std::string, double> HashTables::averageOfTopThreeScores( std::vector<std::pair<std::string, int>>& scores)
{
    std::unordered_map<std::string, double> result;
    std::unordered_map<std::string, int> notes;
    int maxScore = 0;

    for (auto& score : scores)
    {
        notes[score.first]++;
    }

    for (auto& score : scores)
    {
        wordIndex[score.first] += score.second;
    }
    
    for (auto& it : wordIndex)
    {
        if(notes.find(it.first) != notes.end() && notes[it.first] >= 3)
        {
            if (wordIndex[it.first] > maxScore)
            {
                result.clear();
                maxScore = it.second;
                result[it.first] = it.second / 3.0;
            }    
        }
    }
    return result;
}