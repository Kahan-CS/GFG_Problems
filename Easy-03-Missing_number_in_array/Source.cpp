/*
* Problem Solved on: June 15, 2024 (1st Attempt)

* Link to the problem: https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1
* Problem Description:
    * Given an array of size n-1 such that it only contains distinct integers in the range of 1 to n. Return the missing element.

*/



//{ Driver Code Starts
// Initial template for C++

#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;

// Draft logs:

/*
* Draft 1:
    Successful!! (Yay in the first try haha, easy!)
*/

// } Driver Code Ends
// User function template for C++
class Solution {
public:

    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {

        // Your code goes here
        int sum = 0;

        for (int i = 0; i < n - 1; i++)
        {
            sum += arr[i];
        }
        int expected_sum = n * (n + 1) / 2;
        int missing_number = expected_sum - sum;

        return missing_number;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n - 1);
        for (int i = 0; i < n - 1; ++i)
            cin >> arr[i];
        Solution obj;
        cout << obj.missingNumber(n, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends