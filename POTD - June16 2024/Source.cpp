/*
* Date of the problem: June 16, 2024
* Problem Solved on: June 28, 2024

* Link to the problem: https://www.geeksforgeeks.org/problems/sum-of-prime4751/1
* Problem Description:
    * Given a number n, find out if n can be expressed as a+b, where both a and b are prime numbers. If such a pair exists, return the values of a and b, otherwise return [-1,-1] as an array of size 2.
      Note: If [a, b] is one solution with a <= b, and [c, d] is another solution with c <= d, and a < c then  [a, b] is considered as our answer.
*/

// Draft log
/*
* Draft 1:
    Solved in one go! Thanks to sieve of eratosthenes!!
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

class Array {
public:
    template <class T>
    static void input(vector<T>& A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T>& A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
public:
    vector<int> getPrimes(int n) {
        // code here

        vector<bool> isPrime(n+1, true);
        isPrime[0] = isPrime[1] = false;

        // sieve of eratosthenes
        for (int p = 2; p * p <= n; p++) {
            if (isPrime[p]) 
            {
                for (int i = p * p; i <= n; i += p) 
                {
                    isPrime[i] = false;
                }
            }
        }
        for (int i = 0; i < isPrime.size(); i++)
        {
            if (isPrime[i] && isPrime[n-i])
            {
                return { i, n - i };
                
            }
        }

        return { -1, -1 };

    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends