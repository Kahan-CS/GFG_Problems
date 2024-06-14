/*
* Date of the problem: June 13, 2024
* Problem Solved on: June 13, 2024 (1st Attempt)

* Link to the problem: https://www.geeksforgeeks.org/problems/padovan-sequence2855/1
* Problem Description:
    * Given a number n, find the nth number in the Padovan Sequence.

    A Padovan Sequence is a sequence which is represented by the following recurrence relation
    P(n) = P(n-2) + P(n-3)
    P(0) = P(1) = P(2) = 1

    Note: Since the output may be too large, compute the answer modulo 10^9+7.
*/

//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


// Draft logs:

/*
Draft 1: Successful (hurray! Just in the first try!)
*/

// } Driver Code Ends

class Solution
{
public:
    int padovanSequence(int n)
    {
        //code here

        vector<unsigned long long int> PadovanSeqArr{ 1,1,1 };
        const unsigned int M = 1000000007;
        int i = 3;
        for (i = 3; i <= n; i++)
        {
            PadovanSeqArr.push_back(((PadovanSeqArr[i - 2] % M) + (PadovanSeqArr[i - 3] % M)) % M);
        }
        return (PadovanSeqArr.at(n) % M);
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
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends