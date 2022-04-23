/*
Smallest Positive missing number 
You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.
Example 1:
Input:
N = 5
arr[] = {1,2,3,4,5}
Output: 6
Explanation: Smallest positive missing 
number is 6.
Example 2:
Input:
N = 5
arr[] = {0,-10,1,3,-20}
Output: 2
Explanation: Smallest positive missing 
number is 2.
Your Task:
The task is to complete the function missingNumber() which returns the smallest positive missing number in the array.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
Constraints:
1 <= N <= 106
-106 <= arr[i] <= 106
*/

#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int a[], int n) 
    { 
        int i=0;
        for(int i=0;i<n;i++)
        {
            while(a[i]>=1&&a[i]<n&&a[i]!=a[a[i]-1])
            swap(a[i],a[a[i]-1]);
        }
        for(i=0;i<n;i++)
        {
            if(a[i]!=i+1)
            return i+1;
        }
        if(i==n)
        return n+1;
    } 
};
int missingNumber(int arr[], int n);
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        cin>>arr[i];
        Solution ob;
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 