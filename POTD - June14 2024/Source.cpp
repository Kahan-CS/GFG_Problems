//{ Driver Code Starts
// Initial Template for C++
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

using namespace std;

// Draft logs:

/*
* Draft 1:
    Does not produce the desired output. Provides "No" for the basic input. Seems to be perfectly accurate but probably has some logical bug. Hence need to debug.
    
*/

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    string armstrongNumber(int n) {
        // code here
        int a = (n / 100) % 10;
        int b = (n / 10) % 10;
        int c = n % 10;

        int SumOfCubes = (a ^ 3) + (b ^ 3) + (c ^ 3);
        if (n == SumOfCubes)
        {
            return "Yes";
        }   
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends