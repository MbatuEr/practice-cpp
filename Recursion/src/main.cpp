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
    return 0;
}
