# ifndef DYNAMICPROGRAMMING_H
# define DYNAMICPROGRAMMING_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_set>
#include <limits>

class Dp
{
    private:
        int computeXChooseY(int x, int y, std::vector<std::vector<int>>& x_choose_y);

        int computeMaximumRevenueForRange(const std::vector<int>& coins, int a, int b, 
                            std::vector<std::vector<int>>& max_revenue_for_range);

    public:
        // Computes the number of different combinations to reach the final score with the given scores.
        int numberOfScoreCombinations(int final_score, const std::vector<int>& scores);

        // Computes min number of edits to transform one string to another.
        int levenshteinDistance(const std::string& s1, const std::string& s2);
        
        // Computes number of ways to reach last index of the matrix by just going right and down.
        int traversing2DArray(int n);
        
        // Wrapper function for x choose y.
        int binomialCoefficient(int n, int k);

        // Looks for the given pattern in the given grid.
        bool findPattern(const std::vector<std::vector<int>>& grid, 
                                    const std::vector<int>& pattern);

        // Computes the best way to fill a knapsack with a capacity.
        int knapsack(int cap, const std::vector<int>& weights, const std::vector<int>& values);

        // Finds the decomposed words in a given dictionary.
        std::vector<std::string> decomposeIntoDictionaryWords(const std::string& domain, 
                                        const std::unordered_set<std::string>& dictionary);
        
        // Finds the minimum weighted path top to bottom in a triangle.
        int minimumPathWeight(const std::vector<std::vector<int>>& triangle);
        
        // Wrapper function for computing maximum revenue for range.
        int maximumRevenue(const std::vector<int>& coins);
        
        // Arranges words in the fixed size line to get min size of blanks.
        int minimumMessiness(const std::vector<std::string>& words, int line_length);
        
        int longestNondecreasingSubsequenceLength(const std::vector<int>& A);

};

# endif // DYNAMICPROGRAMMING_H