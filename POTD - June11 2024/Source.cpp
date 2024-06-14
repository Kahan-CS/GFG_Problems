/*
* Date of the problem: June 11, 2024
* Problem Solved on: June 12, 2024 (3rd attempt)

* Link to the problem: https://www.geeksforgeeks.org/problems/maximum-tip-calculator2631/1
* Problem Description:
    * In a restaurant, two waiters, A and B, receive n orders per day, earning tips as per arrays arr[i] and brr[i] respectively. If A takes the ith order, the tip is arr[i] rupees; if B takes it, the tip is brr[i] rupees.

    To maximize total tips, they must distribute the orders such that:

    A can handle at most x orders
    B can handle at most y orders
    Given that x + y ≥ n, all orders can be managed by either A or B. Return the maximum possible total tip after processing all the orders.
*/

//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

using namespace std;


// Draft logs:

/*
Draft 1:
    Works for the sample test case, but not for other test cases. Particular test case failed on gfg:
        Test case:
        9
        4
        7
        4 7 10 8 7 3 2 8 7
        3 9 5 5 5 6 8 6 7
        Code output:
        67
        Correct output:
        66

        Issue: This is happening whenever value of x is being exceeded because The replacements required (ReplacementNumber are only for the positive portion, which does not gaurantee that value of x will not be exceeded. So need to check on that.

        Solution: In the line: `while (ReplacementNumber <= y && DifferenceArr[i].first >= 0)` , the condition for checking if the differnce is positive does not fit, and this is where we can add the condition for checking for x.
        What I ended up doing is that I changed some conditions in a logical sense, such that the loop will not violate the limits of x, while still replacing the values with positive differences. Hopefully the submission works this time.


Draft 2:
    Solved the previous test case, but other test cases failed. Particular one from gfg:
        Test case:
        10
        8
        2
        1 7 6 6 6 1 3 4 8 10
        10 7 7 9 1 3 2 9 3 4
        Code output:
        69
        Correct output:
        66

        Issue: The issue seems to be that the code is not following the correct logic for the replacement. It does not respect the limit of y. So need to check on that.

        Solution: Simple solution was that ReplacementNumber should be checked for less than y, and not less than or equal to y. This will ensure that the limit of y is not exceeded, if it was including '=' then it would run the loop for one more time causing the replacement number to exceed the limit of y. So, I changed the condition in the while loop to `while (ReplacementNumber < y)`. This should work now.

 Draft 3: Problem Solved!!
*/

class Array {
public:
    template <class T>
    static void input(vector<T>& a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T>& a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
public:
    long long maxTip(int n, int x, int y, vector<int>& arr, vector<int>& brr) {
        // code here
        vector<pair<int, int>> DifferenceArr;

        for (int i = 0; i < n; i++)
        {
            DifferenceArr.push_back(make_pair(brr.at(i) - arr.at(i), i));
        }

        vector<int> FinalArrayOfTips;
        FinalArrayOfTips = arr;

        sort(DifferenceArr.begin(), DifferenceArr.end());

        int ReplacementNumber = 0;

        int i = n - 1;

        while (ReplacementNumber < y)
        {
            if (DifferenceArr[i].first >= 0)
            {
                FinalArrayOfTips[DifferenceArr[i].second] = brr.at(DifferenceArr[i].second);
                ReplacementNumber++;
            }

            else
            {
                if (n - ReplacementNumber > x)
                {
                    FinalArrayOfTips[DifferenceArr[i].second] = brr.at(DifferenceArr[i].second);
                    ReplacementNumber++;
                }
                else
                {
                    break;
                }
            }
            i--;

        }

        long long sum = 0;
        for (auto& i : FinalArrayOfTips)
        {
            sum += i;
        }

        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends