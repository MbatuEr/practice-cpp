#include "../header/Recursion.h"

void Recursion::towerOfHanoi(int n, char source, char destination, char auxiliary) 
{
    if (n == 1)
    {
        std::cout << "Move disk 1 from " << source << "to " << destination << std::endl;
        return;
    }

    towerOfHanoi(n - 1, source, auxiliary, destination);
    std::cout << "Move disk " << n << " from " << source << " to " << destination << std::endl;
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

bool Recursion::isSafe(const std::vector<int>& placement, int row, int col) 
{
    for (int i = 0; i < row; i++)
    {
        if (placement[i] == col)
        {
            return false;
        }
        if (abs(placement[i] - col) == abs(i - row))
        {
            return false;
        }
    }
    return true;
}

void Recursion::solveNQueensUtil(int n, int row, std::vector<int>& placement, std::vector<std::vector<std::string>>& solutions) 
{
    if (row == n)
    {
        std::vector<std::string> board(n, std::string(n, '.'));
        for (int i = 0; i < n; i++)
        {
            board[i][placement[i]] = 'Q';
        }
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(placement, row, col))
        {
            placement[row] = col;
            solveNQueensUtil(n, row + 1, placement, solutions);
        }
    } 
}

std::vector<std::vector<std::string>> Recursion::solveNQueens(int n) 
{
    std::vector<std::vector<std::string>> solutions;
    std::vector<int> placement(n);
    solveNQueensUtil(n, 0, placement, solutions);
    return solutions;
}

void Recursion::generatePermutationsRecursive(std::vector<int> arr, int n, std::vector<std::vector<int>>& result) 
{
    if (n == 1)
    {
        result.push_back(arr);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        std::swap(arr[i], arr[n - 1]);

        generatePermutationsRecursive(arr, n - 1, result);

        std::swap(arr[i], arr[n - 1]);
    }
}

std::vector<std::vector<int>> Recursion::generatePermutations(std::vector<int> arr) 
{
    std::vector<std::vector<int>> result;

    generatePermutationsRecursive(arr, arr.size(), result);

    std::sort(result.begin(), result.end());

    return result;
}