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

bool HashTables::isOneAway(const std::string& str1, const std::string& str2)
{
    if (abs(str1.size() - str2.size()) >= 2)
    {
        return false;   
    }

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
    int maxScore = 0;

    for (auto& score : scores)
    {
        wordIndex[score.first] += score.second;
        notes[score.first]++;
    }
    
    for (auto& it : wordIndex)
    {
        if(notes[it.first] >= 3 && wordIndex[it.first] > maxScore)
        {
            result.clear();
            maxScore = it.second;
            result[it.first] = maxScore / 3.0;
        }
    }
    return result;
}

int HashTables::allStringDecompositions(const std::string& sentence, const std::vector<std::string>& words)
{
    int result;
    if (words.empty() || sentence.empty()) 
    {
        return result;
    }

    int wordLength = words[0].size();              
    int wordCount = words.size();                  
    int totalLength = wordLength * wordCount;      
    
    for (const std::string& word : words) {
        wordIndex[word]++;
    }

    for (int i = 0; i <= (int)sentence.size() - totalLength; ++i) 
    {
        std::unordered_map<std::string, int> seenWords;
        int j = 0;

        while (j < wordCount) 
        {
            std::string currentWord = sentence.substr(i + j * wordLength, wordLength);

            if (wordIndex.find(currentWord) == wordIndex.end()) 
            {
                break;
            }

            seenWords[currentWord]++;
            if (seenWords[currentWord] > wordIndex[currentWord]) 
            {
                break;
            }

            j++;
        }

        if (j == wordCount) 
        {
            result = i;
        }
    }

    return result;
}

bool HashTables::testCollatz(int n)
{
    for(int i = 1; i <= n; i++)
    {
        if (!collatzSequence(i))
        {
            return false;
        }
    }
    return true;
}

bool HashTables::collatzSequence(long long n)
{
    if (n == 1) 
    {
        return true; // Reached 1
    }
    if (cache.find(n) != cache.end()) 
    {
        return cache[n]; 
    }
    if (n % 2 == 0) 
    {
        cache[n] = collatzSequence(n / 2);
    } 
    else 
    {
        cache[n] = collatzSequence(3 * n + 1);
    }
    return cache[n];
}
