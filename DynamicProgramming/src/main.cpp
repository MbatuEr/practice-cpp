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

    // Traversing in a 2D array
    int matrix_size = 5;
    int number_of_ways = dp.traversing2DArray(matrix_size);
    std::cout << "The number of different ways: " << number_of_ways << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    // Binomial coefficient
    int num1 = 5, num2 = 2;
    int binomial = dp.binomial_coefficient(num1, num2);
    std::cout << num1 << " choose " << num2 << " = " << binomial << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    // Sequence in a 2D array
    std::vector<std::vector<int>> grid = {
        {1, 2, 3},
        {3, 4, 5},
        {5, 6, 7}
    };

    std::vector<int> pattern1 = {1, 3, 4, 6};
    std::vector<int> pattern2 = {1, 2, 3, 4};

    std::cout << "Pattern 1 found: " << (dp.findPattern(grid, pattern1) ? "true" : "false") << std::endl;
    std::cout << "Pattern 2 found: " << (dp.findPattern(grid, pattern2) ? "true" : "false") << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    // Knapsack problem
    int cap = 7;
    std::vector<int> weights = {5, 3, 4, 1};
    std::vector<int> values = {70, 50, 40, 10};
    int max_profit = dp.knapsack(cap, weights, values);
    std::cout << "The max profit that can fill in the knapsaack is: " << max_profit << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    // THE BEDBATHANDBEYOND.com problem.
    std::unordered_set<std::string> dictionary = {"bed", "bath", "beyond", "and", "a", "man", "plan", "canal"};
    std::string name1 = "bedbathandbeyond";
    std::string name2 = "amanaplanacanal";

    std::vector<std::string> result1 = dp.decomposeIntoDictionaryWords(name1, dictionary);
    std::cout << "Word breaks for '" << name1 << "':\n";
    for (const std::string& sequence : result1) 
    {
        std::cout << sequence << std::endl;
    }

    std::vector<std::string> result2 = dp.decomposeIntoDictionaryWords(name2, dictionary);
    std::cout << "\nWord breaks for '" << name2 << "':\n";
    for (const std::string& sequence : result2) 
    {
        std::cout << sequence << std::endl;
    }
    std::cout << "--------------------------------------------------------" << std::endl;

    // Min path weight
    std::vector<std::vector<int>> triangle = {
        {2},
        {4, 4},
        {8, 5, 6},
        {4, 2, 6, 2},
        {1, 5, 2, 3, 4}
    };

    int result = dp.minimumPathWeight(triangle);
    std::cout << "Minimum path sum: " << result << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    return 0;
}