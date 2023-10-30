**************************************************************************************  Question  **********************************************************************************************************************************************

  Given an array of N integers, find the sum of xor of all pairs of numbers in the array arr. In other words, select all possible pairs of i and j from 0 to N-1 (i<j) and determine sum of all (arri xor arrj).

Example 1:

Input : arr[ ] = {7, 3, 5}
Output : 12
Explanation:
All possible pairs and there Xor
Value: ( 3 ^ 5 = 6 ) + (7 ^ 3 = 4)
 + ( 7 ^ 5 = 2 ) =  6 + 4 + 2 = 12
Example 2:

Input : arr[ ] = {5, 9, 7, 6} 
Output :  47
Explanation:
All possible pairs and there Xor
Value: (5 ^ 9 = 12) + (5 ^ 7 = 2)
 + (5 ^ 6 = 3) + (9 ^ 7 = 14)
 + (9 ^ 6 = 15) + (7 ^ 6 = 1)
 = 12 + 2 + 3 + 14 + 15 + 1 = 47
Your Task:
You do not have to take input or print output. You only need to complete the function sumXOR() that takes an array (arr), sizeOfArray (n), and return the sum of xor of all pairs of numbers in the array.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints
2 ≤ n ≤ 105
1 ≤ arr[i] ≤ 105




**************************************************************************************  Solution  **********************************************************************************************************************************************

//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
  long long int sumXOR(int arr[], int n)
    {
        long long int sum = 0;
        for(int j = 0;j<32;j++){
            int zero_count = 0;
            int one_count = 0;
            for(int i = 0;i<n;i++)
            {
             if(arr[i]%2 == 1) one_count++;
             else zero_count++;
             arr[i] = arr[i]/2;
            }
            sum += pow(2,j)*zero_count*one_count;
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends
