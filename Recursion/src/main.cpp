#include "../header/Recursion.h"

int main() 
{
    // Tower of Hanoi.
    Recursion rec;
    int numDisks = 4;

    if (numDisks <= 0) 
    {
        std::cout << "Number of disks must be positive." << std::endl;
        return 1;
    }

    rec.towerOfHanoi(numDisks, 'A', 'C', 'B'); // A is source, C is destination, B is auxiliary
    std::cout << "----------------------------------------------------------------------" << std::endl;

    // N-queens problem.
    int n = 4;
    std::vector<std::vector<std::string>> solutions = rec.solveNQueens(n);

    if (solutions.empty()) 
    {
        std::cout << "No solutions found for N = " << n << std::endl;
    } 
    else {
        std::cout << "Solutions for N = " << n << ":" << std::endl;
        for (const auto& solution : solutions) 
        {
            for (const std::string& row : solution) 
            {
                std::cout << row << std::endl;
            }
            std::cout << std::endl;
        }
    }
    std::cout << "----------------------------------------------------------------------" << std::endl;

    // All permutations.
    std::vector<int> arr = {2,3,5};
    int num;

    std::vector<std::vector<int>> permutations = rec.generatePermutations(arr);

    std::cout << "Permutations of the array:" << std::endl;
    for (const auto& perm : permutations) 
    {
        for (int val : perm) 
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "----------------------------------------------------------------------" << std::endl;
    
    // The power set.
    std::vector<int> set = {0, 1, 2};

    std::vector<std::vector<int>> powerSet = rec.generatePowerSet(set);

    std::cout << "Power set of the given set:" << std::endl;
    for (const auto& subset : powerSet) 
    {
        std::cout << "{";
        for (size_t i = 0; i < subset.size(); ++i) 
        {
            std::cout << subset[i];
            if (i < subset.size() - 1) 
            {
                std::cout << ", ";
            }
        }
        std::cout << "} ";
    }
    std::cout << "\n----------------------------------------------------------------------" << std::endl;
    
    // All subset of size k.
    int s = 5, k = 2;

    std::vector<std::vector<int>> subsets = rec.generateSubsetsOfSizeK(s, k);
    std::cout << "Subsets of size " << k << " from {1 to " << s << "}:" << std::endl;
    for (const auto& subset : subsets) 
    {
        std::cout << "{";
        for (size_t i = 0; i < subset.size(); ++i) 
        {
            std::cout << subset[i];
            if (i < subset.size() - 1) 
            {
                std::cout << ", ";
            }
        }
        std::cout << "} ";
    }
    std::cout << "\n----------------------------------------------------------------------" << std::endl;

    // String of matched parents.
    int a = 3;

    std::vector<std::string> parentheses = rec.generateParentheses(a);

    std::cout << "Parentheses strings with " << a << " pairs:" << std::endl;
    for (const auto& str : parentheses) 
    {
        std::cout << str << std::endl;
    }
    std::cout << "----------------------------------------------------------------------" << std::endl;
    
    // Palindromic decompositions.
    std::string str = {"0204451881"};
    std::vector<std::vector<std::string>> decompositions = rec.generatePalindromicDecompositions(str);

    std::cout << "Palindromic decompositions of \"" << str << "\":" << std::endl;
    for (const auto& decomposition : decompositions) 
    {
        std::cout << "\"";
        for (size_t i = 0; i < decomposition.size(); ++i) 
        {
            std::cout << decomposition[i];
            if (i < decomposition.size() - 1) 
            {
                std::cout << "\", \"";
            }
        }
        std::cout << "\"" << std::endl;
    }
    std::cout << "----------------------------------------------------------------------" << std::endl;

    // All distinct binary trees.
    int tree_number = 3;
    std::vector<Tree*> trees = rec.generateTrees(tree_number);

    std::cout << "Number of distinct trees: " << trees.size() << std::endl;
    for (Tree* tree : trees) 
    {
        std::cout << "--------------------------" << std::endl;
        rec.printTree(tree);
    }

    for (Tree* tree : trees) 
    {
        delete tree;
    }
    std::cout << "----------------------------------------------------------------------" << std::endl;
    return 0;
}

/*

*/
/*

*/
/*

*/