/*
* Problem Solved on: June 15, 2024 (2nd Attempt)

* Link to the problem: https://www.geeksforgeeks.org/problems/power-of-2-1587115620/1
* Problem Description:
    * Given a non-negative integer n. The task is to check if it is a power of 2. 
*/


//{ Driver Code Starts
// Initial Template for C++

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Draft logs:

/*
* Draft 1: 
    Made a simple error: Did not consider the case of n == 1. In which case should return true as 1 is 0th power.

* Draft 2:
    Successful!!
*/

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n) {

        // Your code here
        bool answer = false;
        if (n == 2 || n == 1)
        {
            answer = true;
        }
        else if (n > 2 && n % 2 == 0)
        {
            long long int half = n / 2;
            answer = isPowerofTwo(half);
        }
        return answer;

    }
};

//{ Driver Code Starts.

// Driver code
int main() {

    int t;
    cin >> t; // testcases

    for (int i = 0; i < t; i++) {
        long long n; // input a number n
        cin >> n;
        // if (n == 11) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        if (ob.isPowerofTwo(n)) // Now, if log2 produces an integer not decimal then we
            // are sure raising 2 to this value
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }

    return 0;
}

// } Driver Code Ends