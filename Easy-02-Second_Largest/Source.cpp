/*
* Problem Solved on: June 15, 2024 (2nd Attempt)

* Link to the problem: https://www.geeksforgeeks.org/problems/second-largest3735/1
* Problem Description:
    * Given an array Arr of size N, print the second largest distinct element from an array. If the second largest element doesn't exist then return -1.


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
    Made a simple error: Did not consider the possibility of min_difference being updated to a different value when a new largest is found!. Added code: ` min_difference = largest - second_largest; `

* Draft 2:
    Successful!!
*/

// } Driver Code Ends
//User function template for C++
class Solution {
public:
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
		// code here
		int second_largest = -1;
		int largest = arr[0];

		int min_difference = 2147483647;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] > largest)
			{
				second_largest = largest;
				largest = arr[i];

				// this is very important otherwise it will neglect the logic of new second_largest having different difference from the new largest.
				min_difference = largest - second_largest;

			}
			else if (arr[i] < largest && (largest - arr[i]) < min_difference)
			{
				min_difference = (largest - arr[i]);
				second_largest = arr[i];
			}
		}
		return second_largest;
	}
};

//{ Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		// Driver code change: int arr[n] produced c++ error for having non-constant value in the array's declaration. This was the only way to prevent that error without affecting overall code.
		int* arr = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		Solution ob;
		auto ans = ob.print2largest(arr, n);
		cout << ans << "\n";

		// Driver code change: for the dynamically allocated array
		delete[] arr; // Free the allocated memory

	}
	return 0;
}

// } Driver Code Ends