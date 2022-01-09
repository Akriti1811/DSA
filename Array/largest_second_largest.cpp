/*
Given an array arr[] of size N of positive integers which may have duplicates. The task is to find the maximum and second maximum from the array, and both of them should be distinct, so If no second max exists, then the second max will be -1.

Example 1:

Input:
N = 3
arr[] = {2,1,2}
Output: 2 1
Explanation: From the given array 
elements, 2 is the largest and 1 
is the second largest.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<int> largestAndSecondLargest(int n, int a[])
    {
        int max = INT_MIN, max2= INT_MIN;
        vector<int> large;
        for(int i=0;i<n;i++)
        {
            if(a[i]>max)
            {
                max2=max;
                max=a[i];
            }
            else if(a[i]>max2&&a[i]!=max)
            {
                max2=a[i];
            }
        }
         large.push_back(max);
         if(max2==INT_MIN)
         large.push_back(-1);
         else
         large.push_back(max2);
         return large;
    }
};

int main() {
	
	// Testcase input
	int testcases;
	cin >> testcases;
    
    // Looping through all testcases
	while(testcases--){
	    int sizeOfArray;
	    cin >> sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    // Array input
	    for(int index = 0; index < sizeOfArray; index++){
	        cin >> arr[index];
	    }
	    Solution obj;
	    vector<int> ans = obj.largestAndSecondLargest(sizeOfArray, arr);
	    cout<<ans[0]<<' '<<ans[1]<<endl;
	}
	
	return 0;
}