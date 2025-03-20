#include "../header/HashTables.h"
#include <algorithm>

bool HashTables::hasAllUniqueCharacters(std::string& str)
{
    uniq_char.clear();
    for (char c : str)
    {
        if (uniq_char.find(c) != uniq_char.end())
        {
            return false;
        }
        uniq_char[c] = true;
    }
    return true;
}

bool HashTables::arePermutations(const std::string& str1, const std::string& str2)
{
    if (str1.size() != str2.size())
    {
        return false; // Different lengths cannot be permutations
    }

    char_count.clear();
    
    for (char c : str1)
    {
        char_count[c]++;
    }

    for (char c : str2)
    {
        if (char_count.find(c) == char_count.end() || char_count[c] == 0)
        {
            return false;
        }
        char_count[c]--;
    }

    return true;
}

bool HashTables::isPalindromePermutation(const std::string& str)
{
    char_count.clear();
    int odd_count = 0;
    for (char c : str)
    {
        if (c == ' ')
        {
            continue;
        }
        char_count[c]++;
        if (char_count[c] % 2 == 0)
        {
            odd_count--;
        }
        else
        {
            odd_count++;
        }
    }
    return odd_count <= 1;
} 

bool HashTables::isOneAway(const std::string& str1, const std::string& str2)
{
    if (abs(str1.size() - str2.size()) >= 2)
    {
        return false;   
    }

    char_count.clear();
    int diff_count = 0;

    const std::string& shorter = str1.size() <= str2.size() ? str1 : str2;
    const std::string& longer = str1.size() <= str2.size() ? str2 : str1;

    for (char c : shorter)
    {
        char_count[c]++;
    }

    for (char c : longer)
    {
        if (char_count.find(c) != char_count.end() && char_count[c] > 0)
        {
            char_count[c]--;
        }
        else
        {
            diff_count++;
        }
    }
    return diff_count <= 1;
}

std::unordered_map<char, int> HashTables::mostFrequentWord(const std::string& str)
{
    char_count.clear();
    for (char c : str)
    {
        char_count[c]++;
    }

    int max_count = 0;
    char max_char = ' ';
    for (auto& it : char_count)
    {
        if (it.second > max_count)
        {
            max_count = it.second;
            max_char = it.first;
        }
    }
    return {{max_char, max_count}};
}    

std::unordered_map<int, std::string> HashTables::nearestRepetition(const std::vector<std::string>& str)
{
    word_index.clear();
    int min_dist = __INT_MAX__;
    int dist = 0;
    std::string word;
    for (int i = 0; i < str.size(); i++)
    {
        if (word_index.find(str[i]) != word_index.end())
        {
            dist = i - word_index[str[i]];
            if (dist < min_dist)
            {
                min_dist = dist;
                word = str[i];
            }
        }
        word_index[str[i]] = i;
    }
    
    return {{min_dist, word}};
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
            word_index[word]++;
            if (word_index[word] == 1) 
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
                word_index[start_word]--;
                if (word_index[start_word] == 0) 
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
    word_index.clear();
    int start = 0;
    std::pair<int, int> result = {-1, -1};
    for (int end = 0; end < arr.size(); end++)
    {
        if (word_index.find(arr[end]) == word_index.end())
        {
            word_index[arr[end]]++; 
        }
        else
        {
            while (word_index.find(arr[end]) != word_index.end())
            {
                word_index.erase(arr[start]);
                start++;
            }
            word_index[arr[end]]++;
        }
        if (end - start > result.second - result.first)
        {
            result = {start, end};
        }
    }
    return result;
}

int HashTables::lengthOfLongestContainedInterval(const std::vector<int>& arr)
{
    length_index.clear();
    int max_length = 0;
    for (int num : arr)
    {
        if (length_index.find(num) == length_index.end())
        {
            int left = length_index.find(num - 1) != length_index.end() ? length_index[num - 1] : 0;
            int right = length_index.find(num + 1) != length_index.end() ? length_index[num + 1] : 0;
            int length = left + right + 1;
            length_index[num] = length;
            length_index[num - left] = length;
            length_index[num + right] = length;
            max_length = std::max(max_length, length);
        }
    }
    return max_length;
}

std::unordered_map<std::string, double> HashTables::averageOfTopThreeScores( std::vector<std::pair<std::string, int>>& scores)
{
    std::unordered_map<std::string, double> result;
    int max_score = 0;

    for (auto& score : scores)
    {
        word_index[score.first] += score.second;
        notes[score.first]++;
    }
    
    for (auto& it : word_index)
    {
        if(notes[it.first] >= 3 && word_index[it.first] > max_score)
        {
            result.clear();
            max_score = it.second;
            result[it.first] = max_score / 3.0;
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

    int word_length = words[0].size();              
    int word_count = words.size();                  
    int total_length = word_length * word_count;      
    
    for (const std::string& word : words) {
        word_index[word]++;
    }

    for (int i = 0; i <= (int)sentence.size() - total_length; ++i) 
    {
        std::unordered_map<std::string, int> seen_words;
        int j = 0;

        while (j < word_count) 
        {
            std::string current_word = sentence.substr(i + j * word_length, word_length);

            if (word_index.find(current_word) == word_index.end()) 
            {
                break;
            }

            seen_words[current_word]++;
            if (seen_words[current_word] > word_index[current_word]) 
            {
                break;
            }

            j++;
        }

        if (j == word_count) 
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
        return true;
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
