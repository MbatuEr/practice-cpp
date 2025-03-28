#include "../header/array.h"

void Array::DutchNationalFlag(int pivot, std::vector<int>& nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high) 
    {
        if (nums[mid] < pivot) 
        {
            std::swap(nums[low], nums[mid]);
            low++;
            mid++;
        } 
        else if (nums[mid] == pivot) 
        {
            mid++;
        } else 
        { 
            std::swap(nums[mid], nums[high]);
            high--;
        }
    }
}

std::string Array::AddBinary(std::string s1, std::string s2)
{
    std::string result;
    int carry = 0;
    int i = s1.size() - 1;
    int j = s2.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0)
    {
        int sum = carry;
        if (i >= 0)
        {
            sum += (s1[i] - '0'); 
        }
        if (j >= 0)
        {
            sum += (s2[j] - '0'); 
        }
        result.push_back((sum % 2) + '0');
        carry = sum / 2;
        --i;
        --j; 
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::vector<int> Array::Multiply(const std::vector<int>& v1, const std::vector<int>& v2)
{
    int n = size(v1);
    int m = size(v2);
    const int sign = v1.front() < 0 ^ v2.front() < 0 ? -1 : 1;
    std::vector<int> result(n + m, 0);
   
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = m - 1; j >= 0; --j)
        {
            int product = v1[i] * v2[j];
            int sum = product + result[i + j + 1]; // Add to current position
            result[i + j + 1] = sum % 10;         // Set the digit at this position
            result[i + j] += sum / 10;
        }
    }
     while (result.size() > 1 && result[0] == 0) {
            result.erase(result.begin());
        }
    result.front() *= sign;
    return result;
}

bool Array::CanReachEnd(const std::vector<int>& vec)
{
    int counter = 0;
    int furthest_reach = 0;
    int last_index = vec.size() - 1;
    for (int i = 0; i <= furthest_reach && furthest_reach < last_index; i++)
    {
        int temp = furthest_reach;
        furthest_reach = std::max(furthest_reach, vec[i] + i);
        if (temp != furthest_reach)
        {
            ++counter;
        }
    }
    if (furthest_reach >= last_index)
    {
        std::cout << "The minimum number of steps to reach the end : " << counter << std::endl;
    }
    return furthest_reach >= last_index;
}

void Array::DeleteDuplicates(std::vector <int>& vec)
{
    int s = size(vec);
    for (int i = 0; i < s; i++)
    {
        for (int j = i + 1; j < s; j++)
        {
            if (vec[i] == vec[j])
            {
                vec.erase(vec.begin() + j);
                s--;
            }
        }
    }
}

int Array::ProfitFromStock(const std::vector<int>& stocklist)
{
    int highest_profit = 0;
    int lowest_price = std::numeric_limits<int>::max();
    for (int price : stocklist)
    {
        lowest_price = std::min(lowest_price, price);
        highest_profit = std::max(highest_profit, (price - lowest_price));
    }
    return highest_profit;
}

std::vector <int> Array::FindPrimeValues(int key_value)
{
    std::vector<int> primes;
    for (int i = key_value - 1; i > 2; --i)
    {
        bool is_prime = true;
        for (int j = 2; j*j <= i; j++)
        {
            if (i % j == 0)
            {
                is_prime = false;
                break;
            }   
        }
        if (is_prime)
        {
            primes.push_back(i);
        }
    }
    primes.push_back(2);
    return primes;
}

void Array::PermutingElements(std::vector<int>& vec1, std::vector<int>& vec2)
{
    for (int i = 0; i < vec1.size(); i++)
    {
        std::swap(vec1[i],vec1[vec2[i]]);
        int temp = vec2[i];
        std::swap(vec2[i],vec2[temp]);
    }
}

void Array::FindNextPermutation(std::vector<int>& vec)
{
    int s = size(vec) - 2;
    while (s >= 0 && vec[s] >= vec[s+1])
    {
        --s;
    }
    if (s == -1)
    {
        std::cout << "Original is the last permutation." << std::endl;
    }
    std::swap(*find_if(vec.rbegin(), vec.rend(), [&](int a) {return a > vec[s];}), vec[s]);  
    std::reverse(vec.begin() + s + 1, vec.end());
}

void Array::OfflineRandomSampling(int key, std::vector<int>& vec)
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vec.begin(), vec.end(), g);
    vec.erase(vec.begin() + key,vec.end());
}

void Array::UpdateArrayWithProbabilities(int size, std::vector<int>& input_array, std::vector<double>& probabilities)
{
    if (input_array.size() != probabilities.size())
    {
        std::cerr << "Error: The array and probabilities size do not match!" << std::endl;
    }

    std::vector<int> counts(input_array.size(),0);
    for (size_t i = 0; i < probabilities.size() ; i++)
    {
        counts[i] = round(probabilities[i] * size);
    }
    std::vector<int> updated_array;
    updated_array.reserve(size);
    for (size_t i = 0; i < counts.size(); i++)
    {
        updated_array.insert(updated_array.end(),counts[i], input_array[i]);
    }
    input_array = move(updated_array);
}

bool Array::IsValidSudoku(std::vector<std::vector<int>>& board)
{
    int row = board.size();
    int column = board.size();
    int counter = 0;
    bool result = true;
    
    // Check rows
    for (size_t i = 0; i < column; i++)
    {
        std::unordered_set<int> checker;
        for (size_t j = 0; j < row; j++)
        {
            int temp = board[i][j];
            if (temp != 0)
            {
                if(checker.count(temp)) return false; // Duplicate found
                checker.insert(temp);
            }
        }
    }

    // Check columns
    for (size_t j = 0; j < row; j++)
    {
        std::unordered_set<int> checker;
        for (size_t i = 0; i < column; i++)
        {
            int temp = board[i][j];
            if (temp != 0)
            {
                if(checker.count(temp)) return false; // Duplicate found
                checker.insert(temp);
            }
        }
    }
    return true;  
}

std::vector<int> Array::SpiralOrderOfArray(std::vector<std::vector<int>>& vec)
{
    int row = vec.size();
    if (row == 0) return {};

    int column = vec[0].size();
    std::vector<int> arr;

    int top = 0, bottom = row - 1;
    int left = 0, right = column - 1;

    while (top <= bottom && left <= right) 
    {
        for (int j = left; j <= right; ++j) 
        {
            arr.push_back(vec[top][j]);
        }
        ++top;

        for (int i = top; i <= bottom; ++i) 
        {
            arr.push_back(vec[i][right]);
        }
        --right;

        if (top <= bottom) 
        {
            for (int j = right; j >= left; --j) 
            {
                arr.push_back(vec[bottom][j]);
            }
            --bottom;
        }

        if (left <= right) 
        {
            for (int i = bottom; i >= top; --i) 
            {
                arr.push_back(vec[i][left]);
            }
            ++left;
        }
    }
    return arr;
}

std::vector<std::vector<int>> Array::Rotating2DArray(std::vector<std::vector<int>>& vec)
{
    int row = vec.size();
    int column = vec[0].size();

    std::vector<std::vector<int>> rotated(column, std::vector<int>(row));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            rotated[j][row - i -1] = vec[i][j]; 
        }
    }
    return rotated;        
}

std::vector<int> Array::GeneratePascalTriangle(int n)
{
    std::vector<int> prev_row(1, 1);
    for (int i = 1; i < n; i++)
    {
        std::vector<int> current_row(i + 1, 1);
        for (int j = 1; j < i; j++)
        {
            current_row[j] = prev_row[j - 1] + prev_row[j];
        }
        prev_row = current_row;
    }
    
    return prev_row;
}

std::string Array::ReplaceSpaces(std::string& str, int true_length)
{
    int space_count = 0;
    for (int i = 0; i < true_length; i++)
    {
        if (str[i] == ' ')
        {
            space_count++;
        }
    }
    int new_length = true_length + space_count * 2;
    str.resize(new_length);
    int index = new_length - 1;
    for (int i = true_length - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            str[index] = '0';
            str[index - 1] = '2';
            str[index - 2] = '%';
            index -= 3;
        }
        else
        {
            str[index] = str[i];
            index--;
        }
    }
    return str;
}

std::string Array::StringCompression(std::string& str)
{
    std::string result;
    int count = 1;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == str[i+1])
        {
            count++;
        }
        else
        {
            result += str[i] + std::to_string(count);
            count = 1;
        }
    }
    return result.size() < str.size() ? result : str;
}

bool Array::IsSubString(std::string& s1, std::string& s2)
{
    if (s1.size() != s2.size())
    {
        return false;
    }
    std::string temp = s1 + s1;
    return temp.find(s2) != std::string::npos;
}