//{ Driver Code Starts
// Initial Template for C++
#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

using namespace std;

// Draft logs:

/*
* Draft 1:
    Does not produce the desired output. Provides "No" for the basic input. Seems to be perfectly accurate but probably has some logical bug. Hence need to debug.
    Issue: Haha! I forgot that '^' is just a bitwise operator and not an arithmatic operator, hence it can not be used for exponents. Need to use the <cmath> library for pow()

* Draft 2:
    Successful!
*/

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    string armstrongNumber(int n) {
        // code here

        // a,b,c supposed to represent each digit of the code. 
        /* Logic to use for finding the digit : 
        When dividing the number by 'place value needed' (eg.hundreth place i.e. 5 for 8972548), we get the integer eliminating 'lesser place values' (which means that the required place value becomes the last place.), and then finally doing the modulus by 10 (essentially remainder on dividing the number by 10.) we get the last place of that which is our required place value number
        * Eg: hundreth place i.e. 5 for 8972548... 
        * In the given eg.: `8972548 / 100 = 89725.48` which when declared as integer would only count for 89725. Here 5 is in the last place. Now finally doing the modulus with 10, we will be left with the last digit of that number (89725) which is '5'.
        */
        int a = (n / 100) % 10;
        int b = (n / 10) % 10;
        int c = n % 10;

        int SumOfCubes = pow(a, 3) + pow(b, 3) + pow(c, 3);
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