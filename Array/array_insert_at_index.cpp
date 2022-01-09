/*
You are given an array arr(0-based index). The size of the array is given by sizeOfArray. You need to insert an element at given index and print the modified array.

Example 1:

Input:
sizeOfArray = 6
arr[] = {1, 2, 3, 4, 5}
index = 5, element = 90
Output: 1 2 3 4 5 90
Explanation: 90 is inserted at index
5(0-based indexing). After inserting,
array elements are like
1, 2, 3, 4, 5, 90.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    void insertAtIndex(int a[], int n, int ind, int e)
    {
        for(int i=n-1;i>ind;i--)
        a[i]=a[i-1];
        a[ind]=e;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--)
    {      
        int sizeOfArray; 
        cin>>sizeOfArray;       
        int arr[sizeOfArray];
        for(int i = 0; i < sizeOfArray-1; i++)
        cin>>arr[i];       
        int index;
        cin>>index;
        int element;
        cin>>element;
        Solution obj;
        obj.insertAtIndex(arr, sizeOfArray, index, element);   
        for(int i = 0; i < sizeOfArray; i++)
        cout<<arr[i]<<" ";
        cout<<endl;   
    }   
	return 0;
} 