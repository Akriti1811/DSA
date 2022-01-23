/*
Kadane's Algorithm 
Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.
Example 1:
Input:
N = 5
Arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which 
is a contiguous subarray.
Example 2:
Input:
N = 4
Arr[] = {-1,-2,-3,-4}
Output:
-1
Explanation:
Max subarray sum is -1 
of element (-1)
Your Task:
You don't need to read input or print anything. The task is to complete the function maxSubarraySum() which takes Arr[] and N as input parameters and returns the sum of subarray with maximum sum.
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
Constraints:
1 ≤ N ≤ 106
-107 ≤ A[i] ≤ 107
*/

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n)
    {
        
        long long s=0,m1=INT_MIN,m2=INT_MIN;
        for(int i=0;i<n;i++)
        {
            s=max(s+arr[i],0*1LL);
            m1=max(s,m1);
            m2=max(m2,arr[i]*1LL);
        }
        if(m1==0)
        return m2;
        else
        return m1;
    }
};
int main()
{
    int t,n;   
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        cin>>n;   
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        Solution ob;
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}