/*
Maximum Index 
Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] < A[j] and i < j.
Example 1:
Input:
N = 9
A[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
Output:
6
Explanation:
In the given array A[1] < A[7]
satisfying the required 
condition(A[i] < A[j]) thus giving 
the maximum difference of j - i 
which is 6(7-1).
Your Task:
The task is to complete the function maxIndexDiff() which finds and returns maximum index difference. Printing the output will be handled by driver code. Return -1 in case no such index is found.
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
Constraints:
1 ≤ N ≤ 107
0 ≤ A[i] ≤ 109
*/

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        int lmin[n],rmax[n];
        lmin[0]=a[0];
        rmax[n-1]=a[n-1];
        for(int i=1;i<n;i++)
        lmin[i]=min(a[i],lmin[i-1]);
        for(int i=n-2;i>=0;i--)
        rmax[i]=max(a[i],rmax[i+1]);
        int i=0,j=0,m=-1;
        while(i<n && j<n)
        {
            if(lmin[i]<=rmax[j])
            {
                m=max(m,j-i);
                j++;
            }
            else 
            i++;
        }
        return m;
    }
};
int main() 
{
    int T;
    cin>>T;
    while(T--)
    {
        int num;
        cin>>num;
        int arr[num];
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.maxIndexDiff(arr, num)<<endl;           
    }
    return 0;
}  