#include "../header/array.h"

int main() 
{
    // Dutch National Flag problem.
    std::vector<int> nums = {3, 5, 2, 1, 7, 3};
    int i =0;
    int pivot = 3;
    Array obj;
    obj.DutchNationalFlag(pivot,nums);
    std::cout << "Sorted array: ";
    for (int num : nums) 
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    // Add binary numbers.
    std::string s, t;
    std::cout << "Enter the first binary number: ";
    std::cin >> s;
    std::cout << "Enter the second binary number: ";
    std::cin >> t;

    std::string sum = obj.AddBinary(s,t);
    std::cout << "The sum is: " << sum << std::endl; 
    std::cout << "------------------------------------------------------" << std::endl;

    // Multiply two numbers.
    std::vector<int> num1 = {1,2,3};
    std::vector<int> num2 = {9,8,7};
    std::vector<int> result = obj.Multiply(num1, num2);
    std::cout << "The result : ";
    for (int digit : result)
    {
        std::cout << digit << " ";
    }
    std::cout << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    // Check if the end is reachable.
    std::vector<int> vec = {2,1,2,0,2,0,1,3,0,1,2,2,0,1};
    bool final = obj.CanReachEnd(vec);
    std::cout << "The end is reachable?" << std::endl;
    if (final)
    {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    std::cout << "------------------------------------------------------" << std::endl;

    // Delete duplicates.
    std::vector<int> v = {3,3,2,1,5,2};
    obj.DeleteDuplicates(v);
    for (int i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    // Profit from stock.
    std::vector<int> stocklist = {310,325,275,295,260,270,290,330,355,350};
    std::cout << "Highest profit for one buy and sell: " << obj.ProfitFromStock(stocklist) << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    // Find prime values.
    int key;
    std::cout << "Enter a key value: " << std::endl;
    std::cin >> key;
    std::vector<int> prime_values = obj.FindPrimeValues(key);
    std::cout << "Prime values smaller than the key value: ";
    for(int values : prime_values)
    {
        std::cout << values << " ";
    }
    std::cout << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    // Permute elements.
    std::vector<int> original = {3,1,2,4,8,6,5,7};
    std::vector<int> order_input = {2,0,1,3,7,5,4,6};
    obj.PermutingElements(original,order_input); 
    std::cout << "Original array after permutation: ";
    for(int values : original)
    {
        std::cout << values << " ";
    }
    std::cout << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    // Next permutation.
    std::vector<int> orig = {3,4,5,2,1,0};
    obj.FindNextPermutation(orig);
    std::cout << "Next permutation of the original array: ";
    for(int values : orig)
    {
        std::cout << values << " ";
    }
    std::cout << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    // Offline random sampling.
    std::vector<int> samples = {3,4,10,21,13,38,56,89,22};
    obj.OfflineRandomSampling(6,samples);
    std::cout << "Sampled version: ";
    for(int values : samples)
    {
        std::cout << values << " ";
    }
    std::cout << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    // Update array with probabilities.
    std::vector<int> arr = {3,5,7,11};
    std::vector<double> probabilities = {9.0/18.0, 6.0/18.0, 2.0/18.0, 1.0/18.0};
    int size = 18;
    obj.UpdateArrayWithProbabilities(size, arr, probabilities);
    std::cout << "Values multiplied with probabilities: ";
    for(int values : arr)
    {
        std::cout << values << " ";
    }
    std::cout << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    // Check if the sudoku board is valid.
    std::vector<std::vector<int>> board = {
        {0, 3, 5, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    bool is_sudoku_valid = obj.IsValidSudoku(board);

    if (is_sudoku_valid)
    {
        std::cout << "The Sudoku board is valid." << std::endl;
    } else {
        std::cout << "The Sudoku board is invalid." << std::endl;
    }
    std::cout << "------------------------------------------------------" << std::endl;

    // Spiral order of array.
    std::vector<std::vector<int>> spiral_input = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    std::vector<int> spiral_output = obj.SpiralOrderOfArray(spiral_input);
    std::cout << "Array as in spiral order: ";
    for (size_t value : spiral_output)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    // Rotating 2D array.
    std::vector<std::vector<int>> not_rotated_array = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    std::vector<std::vector<int>> rotated_array = obj.Rotating2DArray(not_rotated_array);
    std::cout << "Rotated array : ";
    for (size_t i = 0; i < 4; i++)
    {
        std::cout << std::endl;
        for (size_t j = 0; j < 4; j++)
        {
            std::cout << rotated_array[i][j] << " ";
        }
    }
    std::cout << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    // Generate pascal triangle.
    int n;
    int row;
    int column;
    std::cout << std::endl;
    std::cout << "Enter the which row you wanna see of the pascal triangle: " << std::endl;
    std::cin >> n;
    std::cout << "Enter the row number of the pascal triangle: " << std::endl;
    std::cin >> row;
    std::cout << "Enter the column number of the pascal triangle: " << std::endl;
    std::cin >> column;
    std::vector<int> nth_row_of_pascal_triangle = obj.GeneratePascalTriangle(n, row, column);
    for (size_t value : nth_row_of_pascal_triangle)
    {
        if (value != 0)
        {
            std::cout << value << " ";
        }
    }
    std::cout << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    // Replace spaces.
    std::string str = "Mr John Smith    ";
    int truelength = 13;
    std::string replaced = obj.ReplaceSpaces(str, truelength);
    std::cout << "The string after replacing spaces: " << replaced << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    // String compression.
    std::string compressed = "aabcccccaaa";
    std::string compressed_string = obj.StringCompression(compressed);
    std::cout << "The compressed string is: " << compressed_string << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    // Check if a string is a substring of another string.
    std::string s1 = "waterbottle";
    std::string s2 = "erbottlewat";
    bool is_substring = obj.IsSubString(s1, s2);
    if (is_substring)
    {
        std::cout << "The string is a substring of another string." << std::endl;
    } else {
        std::cout << "The string is not a substring of another string." << std::endl;
    }

    return 0;
}