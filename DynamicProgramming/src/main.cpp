#include "../header/dynamicprogramming.h"

int main()
{
    Dp dp;
    
    // Number of score combinations
    std::vector<int> scores = {2, 3, 7};
    int final_score = 12;
    int combination_of_scores = dp.numberOfScoreCombinations(final_score, scores);
    std::cout << "The number of combinations for final score is: " << combination_of_scores << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    // Levenshtein distance
    std::string s1 = "Saturday";
    std::string s2 = "Sundays";
    int min_edit = dp.levenshteinDistance(s1, s2);
    std::cout << "The min edit to make the transform is : " << min_edit << std::endl; 
    std::cout << "--------------------------------------------------------" << std::endl;
}