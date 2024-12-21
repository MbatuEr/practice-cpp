#include "../header/array.h"

using namespace std;

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

string Array::AddBinary(string s1, string s2)
{
    string result;
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
    reverse(result.begin(), result.end());
    return result;
}

vector<int> Array::Multiply(const vector<int>& v1, const vector<int>& v2)
{
    int n = size(v1);
    int m = size(v2);
    const int sign = v1.front() < 0 ^ v2.front() < 0 ? -1 : 1;
    vector<int> result(n + m, 0);
    int count=0;
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = m - 1; j >= 0; --j)
        {
            int product = v1[i] * v2[j];
            int sum = product + result[i + j + 1]; // Add to current position
            result[i + j + 1] = sum % 10;         // Set the digit at this position
            result[i + j] += sum / 10;
            ++count;
        }
    }
     while (result.size() > 1 && result[0] == 0) {
            result.erase(result.begin());
        }
    result.front() *= sign;
    return result;
}

bool Array::CanReachEnd(const vector<int>& vec)
{
    int counter = 0;
    int furthest_reach = 0;
    int last_index = vec.size() - 1;
    for (int i = 0; i <= furthest_reach && furthest_reach < last_index; i++)
    {
        int temp = furthest_reach;
        furthest_reach = max(furthest_reach, vec[i] + i);
        if (temp != furthest_reach)
        {
            ++counter;
        }
    }
    if (furthest_reach >= last_index)
    {
        cout << "The minimum number of steps to reach the end : " << counter << endl;
    }
    return furthest_reach >= last_index;
}

vector <int> Array::DeleteDuplicates(vector <int>& vec)
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
    return vec;
}

int Array::ProfitFromStock(const vector<int>& stocklist)
{
    int highest_profit = 0;
    int lowest_price = numeric_limits<int>::max();
    for (int price : stocklist)
    {
        int temp = price - lowest_price;
        if (price < lowest_price)
        {
            lowest_price = price;
        }
        highest_profit = max(highest_profit, temp);
    }
    return highest_profit;
}

vector <int> Array::FindPrimeValues(int key_value)
{
    vector<int> primes;
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

void Array::PermutingElements(vector<int>& vec1, vector<int>& vec2)
{
    int s = size(vec1);
     
    for (int i = 0; i < s; i++)
    {
        swap(vec1[i],vec1[vec2[i]]);
        int temp = vec2[i];
        swap(vec2[i],vec2[temp]);
    }
}

void Array::FindNextPermutation(vector<int>& vec)
{
    int s = size(vec) - 2;
    while (s >= 0 && vec[s] >= vec[s+1])
    {
        --s;
    }
    if (s == -1)
    {
        cout << "Original is the last permutation." << endl;
    }
    swap(*find_if(vec.rbegin(), vec.rend(), [&](int a) {return a > vec[s];}), vec[s]);  
    reverse(vec.begin() + s + 1, vec.end());
}

void Array::OfflineRandomSampling(int key, vector<int>& vec)
{
    int s = size(vec) - 1;
    srand(time(0));
    random_shuffle(vec.begin(), vec.end());
    vec.erase(vec.begin() + key,vec.end());
}

void Array::UpdateArrayWithProbabilities(int size, vector<int>& input_array, vector<double>& probabilities)
{
    if (input_array.size() != probabilities.size())
    {
        cerr << "Error: The array and probabilities size do not match!" << endl;
    }

    vector<int> counts(input_array.size(),0);
    int total = 0;

    for (size_t i = 0; i < probabilities.size() ; i++)
    {
        counts[i] = round(probabilities[i] * size);
        total += counts[i];
    }
    vector<int> updated_array;
    updated_array.reserve(size);
    for (size_t i = 0; i < counts.size(); i++)
    {
        updated_array.insert(updated_array.end(),counts[i], input_array[i]);
    }
    input_array = move(updated_array);
}

bool Array::IsValidSudoku(vector<vector<int>>& board)
{
    int row = board.size();
    int column = board.size();
    int counter = 0;
    bool result = true;
    
    // Check rows
    for (size_t i = 0; i < column; i++)
    {
        unordered_set<int> checker;
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
        unordered_set<int> checker;
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

vector<int> Array::SpiralOrderOfArray(vector<vector<int>>& vec)
{
    int row = vec.size();
    if (row == 0) return {};

    int column = vec[0].size();
    vector<int> arr;

    int top = 0, bottom = row - 1;
    int left = 0, right = column - 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right across the top row
        for (int j = left; j <= right; ++j) {
            arr.push_back(vec[top][j]);
        }
        ++top;

        // Traverse from top to bottom along the right column
        for (int i = top; i <= bottom; ++i) {
            arr.push_back(vec[i][right]);
        }
        --right;

        // Traverse from right to left across the bottom row (if still valid)
        if (top <= bottom) {
            for (int j = right; j >= left; --j) {
                arr.push_back(vec[bottom][j]);
            }
            --bottom;
        }

        // Traverse from bottom to top along the left column (if still valid)
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                arr.push_back(vec[i][left]);
            }
            ++left;
        }
    }

    return arr;
}

vector<vector<int>> Array::Rotating2DArray(vector<vector<int>>& vec)
{
    int row = vec.size();
    int column = vec[0].size();

    vector<vector<int>> rotated(column, vector<int>(row));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            rotated[j][row - i -1] = vec[i][j]; 
        }
    }
    return rotated;        
}

vector<int> Array::GeneratePascalTriangle(int n, int row, int column)
{
    vector<vector<int>> pascal_triangle(row, vector<int>(column, 0));
    vector<int> result(column);
    pascal_triangle[0][row - 1] = 1;
    for (int i = 0; i < row - 1; i++)
    {
        for (int j = 0; j < column - 1; j++)
        {
            pascal_triangle[i+1][j] = pascal_triangle[i][j] + pascal_triangle[i][j+1];
        }
    }
    for (size_t i = 0; i < column; i++)
    {
        result[i] = pascal_triangle[n][i];
    }
    return result;
}

string Array::ReplaceSpaces(string& str, int truelength)
{
    int space_count = 0;
    for (int i = 0; i < truelength; i++)
    {
        if (str[i] == ' ')
        {
            space_count++;
        }
    }
    int newlength = truelength + space_count * 2;
    str.resize(newlength);
    int index = newlength - 1;
    for (int i = truelength - 1; i >= 0; i--)
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

string Array::StringCompression(string& str)
{
    string result;
    int count = 1;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == str[i+1])
        {
            count++;
        }
        else
        {
            result += str[i] + to_string(count);
            count = 1;
        }
    }
    return result.size() < str.size() ? result : str;
}

bool Array::IsSubString(string& s1, string& s2)
{
    if (s1.size() != s2.size())
    {
        return false;
    }
    string temp = s1 + s1;
    return temp.find(s2) != string::npos;
}