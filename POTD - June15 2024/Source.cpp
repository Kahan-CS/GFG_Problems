/*
* Date of the problem: June 15, 2024
* Problem Solved on: Not solved yet (1 attempt failed)

* Link to the problem: https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1
* Problem Description:
    * There is a standard numeric keypad on a mobile phone. You can only press the current button or buttons that are directly up, left, right, or down from it (for ex if you press 5, then pressing 2, 4, 6 & 8 are allowed). Diagonal movements and pressing the bottom row corner buttons (* and #) are prohibited.
      Given a number n, find the number of possible unique sequences of length n that you can create by pressing buttons. You can start from any digit.
*/

//{ Driver Code Starts
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

using namespace std;

// Draft logs:

/*
* Draft 1:
    Produces correct calculations, but the complexity is too much and hence is exceeding time limits for large values of n (like 20, 21, 22 etc.) 
    Issue: As indicated by Yogi AI (on gfg)... the problem is that I am taking the approach through recursion which is fine but if I could store those results of depths, and reuse them then it would be much better. So basically I need to use dynamic programming. 
    Here is the full advice as given by Yogi AI: 
    "Hint: Instead of recursively calculating the count for each key at each depth level, consider using dynamic programming to store and reuse the counts for each key at different depths. This approach can help avoid redundant calculations and improve the overall performance of the solution."
* Draft 2:
    Pending...
*/

// } Driver Code Ends

struct Key { 
    int Mobility; 
    vector<int> AccessKeys; 
};

class Solution {
private:
    long long getCountFromFor(vector<Key>& MobileKeys, int givenKeyIndex, int depth) {
        long long count = 0;
        if (depth > 1) {
            for (int i = 0; i < MobileKeys[givenKeyIndex].AccessKeys.size(); i++) {
                count += getCountFromFor(MobileKeys, MobileKeys[givenKeyIndex].AccessKeys[i], depth - 1);
            }
        }
        else {
            count = MobileKeys[givenKeyIndex].Mobility;
        }
        return count;
    }

public:
    long long getCount(int n) {
        // Your code goes here
        // Initialize the keys with their mobility and access keys
        vector<Key> MobileKeys(10);

        // Define the mobility and access keys for each digit (including itself)
        MobileKeys[0].Mobility = 2; MobileKeys[0].AccessKeys = { 0, 8 };
        MobileKeys[1].Mobility = 3; MobileKeys[1].AccessKeys = { 1, 2, 4 }; 
        MobileKeys[2].Mobility = 4; MobileKeys[2].AccessKeys = { 2, 1, 3, 5 }; 
        MobileKeys[3].Mobility = 3; MobileKeys[3].AccessKeys = { 3, 2, 6 }; 
        MobileKeys[4].Mobility = 4; MobileKeys[4].AccessKeys = { 4, 1, 5, 7 }; 
        MobileKeys[5].Mobility = 5; MobileKeys[5].AccessKeys = { 5, 2, 4, 6, 8 }; 
        MobileKeys[6].Mobility = 4; MobileKeys[6].AccessKeys = { 6, 3, 5, 9 }; 
        MobileKeys[7].Mobility = 3; MobileKeys[7].AccessKeys = { 7, 4, 8 }; 
        MobileKeys[8].Mobility = 5; MobileKeys[8].AccessKeys = { 8, 0, 5, 7, 9 }; 
        MobileKeys[9].Mobility = 3; MobileKeys[9].AccessKeys = { 9, 6, 8 }; 

        long long count = 0; // Initial count of single digit numbers

        if (n > 1)
        {
            for (int i = 0; i < 10; i++) {
                count += getCountFromFor(MobileKeys, i, n - 1);
            }
        }
        else
            count = 10;


        return count;
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
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends