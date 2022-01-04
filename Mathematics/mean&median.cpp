/*
Given an array a[ ] of size N. The task is to find the median and mean of the array elements. Mean is average of the numbers and median is the element which is smaller than half of the elements and greater than remaining half.  If there are odd elements, the median is simply the middle element in the sorted array. If there are even elements, then the median is floor of average of two middle numbers in the sorted array. If mean is floating point number, then we need to print floor of it.

Note: To find the median, you might need to sort the array. Since sorting is covered in later tracks, we have already provided the sort function to you in the code.

Example 1:

Input:
N = 5
a[] = {1, 2, 19, 28, 5}
Output: 11 5
Explanation: For array of 5 elements,
mean is (1 + 2 + 19  + 28  + 5)/5 = 11.
Median is 5 (middle element after 
sorting)
*/


#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int median(int A[],int N)
    {
        sort(A,A+N);
        if(N%2==0)
        return (A[N/2]+A[(N/2) - 1])/2;
        else
        return A[N/2];
    }
    
    int mean(int A[],int N)
    {
        int s=0;
        for(int i=0;i<N;i++)
            s+=A[i];
        return s/N;
    }
};

int main()
{
    //testcase
    int T;
    cin>>T;
    while(T--)
    {
        //number of elements in array
        int N;
        cin>>N;
        int a[N];
        
        //inseting elements in the array
        for(int i=0;i<N;i++){
            cin>>a[i];
        }
        Solution ob;
        //calling mean() and median() functions
        cout<<ob.mean(a,N)<<" "<<ob.median(a,N)<<endl;
    }
    return 0;
}