/*
sD 11/30/24
finalProgram.cpp
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using std::cin, std::cout, std::cerr, std::vector, std::sort;

int linearSearch(const vector<int>& arr, int target)
{
    int iterations = 0;
    for (size_t i = 0; i < arr.size(); ++i)
    {
        iterations++;
        if (arr[i] == target)
        {
            cout << "Linear Search: Target found after " << iterations << " iterations.\n";
            return i;
        }
    }
    cout << "Linear Search: Target not found after " << iterations << " iterations.\n";
    return -1;
}

int binarySearchRecursive(const vector<int>& arr, int left, int right, int target, int& iterations)
{
    iterations++;
    if (left > right)
    {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == target)
    {
        return mid;
    } else if (arr[mid] > target)
    {
        return binarySearchRecursive(arr, left, mid - 1, target, iterations);
    } else
    {
        return binarySearchRecursive(arr, mid + 1, right, target, iterations);
    }
}

int binarySearch(const vector<int>& arr, int target)
{
    int iterations = 0;
    int result = binarySearchRecursive(arr, 0, arr.size() - 1, target, iterations);
    if (result != -1)
    {
        cout << "Binary Search: Target found after " << iterations << " iterations.\n";
    } else
    {
        cout << "Binary Search: Target not found after " << iterations << " iterations.\n";
    }
    return result;
}

void measurePerformance(const vector<int>& arr, int target)
{
    auto start = std::chrono::high_resolution_clock::now();
    linearSearch(arr, target);
    auto end = std::chrono::high_resolution_clock::now();
    cout << "Linear Search Time: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms\n";

    start = std::chrono::high_resolution_clock::now();
    binarySearch(arr, target);
    end = std::chrono::high_resolution_clock::now();
    cout << "Binary Search Time: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms\n";
}

int main()
{
    cout << "\nHello! Welcome to my Enhanced Searching Algorithm. Please proceed!\n\n";

    vector<int> arr;
    int n;
    cout << "Enter the number of elements in the array: ";
    if (!(cin >> n) || n <= 0)
    {
        cerr << "Error: Invalid input. Please enter a positive integer.\n";
        return 1;
    }

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i)
    {
        int value;
        if (!(cin >> value))
        {
            cerr << "Error: Invalid input. Please enter integers only.\n";
            return 1;
        }
        arr.push_back(value);
    }

    sort(arr.begin(), arr.end());

    int target;
    cout << "Enter the target value to search: ";
    if (!(cin >> target))
    {
        cerr << "Error: Invalid input. Please enter an integer.\n";
        return 1;
    }

    cout << "\nPerforming searches...\n\n";
    measurePerformance(arr, target);

    cout << "Thank you for running my program! :D\n\n";

    system("pause>0");
}