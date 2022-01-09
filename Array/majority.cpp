/*
Given an array arr[] of size N and two elements x and y, use counter variables to find which element appears most in the array, x or y. If both elements have the same frequency, then return the smaller element.
Note:  We need to return the element, not its count.
Example 1:

Input:
N = 11
arr[] = {1,1,2,2,3,3,4,4,4,4,5}
x = 4, y = 5
Output: 4
Explanation: 
frequency of 4 is 4.
frequency of 5 is 1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int majorityWins(int arr[], int n, int x, int y) {
        int a=0,b=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        a++;
        if(arr[i]==y)
        b++;
    }
    if(a==b)
        return min(x,y);
    else if(a>b)
        return x;
    else
        return y;

    }
};
int main() {

    int t; 
    cin >> t;
    while (t--) 
    {
        int n; 
        cin >> n; 
        int arr[n];
        for (int i = 0; i < n;i++) 
            cin >> arr[i];

        int x, y; 
        cin >> x >> y; 
        Solution obj;
        cout << obj.majorityWins(arr, n, x, y)
             << endl; 
    }

    return 0;
} 