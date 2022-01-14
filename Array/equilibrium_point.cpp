/*
Equilibrium Point 
Given an array A of n positive numbers. The task is to find the first Equilibium Point in the array. 
Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.
Example 1:
Input: 
n = 5 
A[] = {1,3,5,2,2} 
Output: 3 
Explanation: For second test case 
equilibrium point is at position 3 
as elements before it (1+3) = 
elements after it (2+2). 
*/

#include <iostream>
using namespace std;
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) 
    {
        if (n==1)
        return 1;
        for(int i=1;i<n;i++)
        {
            a[i]=a[i]+a[i-1];
        }
        long long sum=a[n-1];
        for(int i=1;i<n-1;i++)
        {
            if(a[i-1]==(sum-a[i]))
            return i+1;
        }
        return -1;
    }

};
int main() 
{
    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        long long a[n];
        for (long long i = 0; i < n; i++) 
        {
            cin >> a[i];
        }       
        Solution ob;
        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}