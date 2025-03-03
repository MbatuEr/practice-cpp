# ifndef DYNAMICPROGRAMMING_H
# define DYNAMICPROGRAMMING_H

#include <iostream>
#include <vector>
#include <algorithm> 

class Dp
{
    public:
        // Computes the number of different combinations to reach the final score with the given scores.
        int numberOfScoreCombinations(int final_score, const std::vector<int>& scores);

        // Computes min number of edits to transform one string to another.
        int levenshteinDistance(const std::string& s1, const std::string& s2);
};

# endif // DYNAMICPROGRAMMING_H