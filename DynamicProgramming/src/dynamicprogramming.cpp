#include "../header/dynamicprogramming.h"

int Dp::numberOfScoreCombinations(int final_score, const std::vector<int>& scores)
{
    std::vector<int> combinations(final_score + 1, 0);
    combinations[0] = 1;

    for (int score : scores)
    {
        for (int i = score; i <= final_score; i++)
        {
            combinations[i] += combinations[i - score];
        }
    }
    return combinations[final_score];
}

int Dp::levenshteinDistance(const std::string& s1, const std::string& s2)
{
    int len1 = s1.size(), len2 = s2.size();
    std::vector<int> prev_row(len2 + 1, 0);
    
    for (int j = 0; j <= len2; ++j) 
    {
        prev_row[j] = j;  
    }

    for (int i = 1; i <= len1; ++i) 
    {
        std::vector<int> current_row(len2 + 1, 0);
        current_row[0] = i;  

        for (int j = 1; j <= len2; ++j) 
        {
            if (s1[i - 1] == s2[j - 1]) 
            {
                current_row[j] = prev_row[j - 1];
            } 
            else {
                current_row[j] = 1 + std::min({prev_row[j],      // Deletion
                                              current_row[j - 1], // Insertion
                                              prev_row[j - 1]});  // Substitution
            }
        }
        prev_row = current_row;
    }

    return prev_row[len2];
}