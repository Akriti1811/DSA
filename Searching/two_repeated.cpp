/*
Two Repeated Elements 
Easy Accuracy: 47.19% Submissions: 25711 Points: 2
You are given an array of N+2 integer elements. All elements of the array are in range 1 to N. Also, all elements occur once except two numbers which occur twice. Find the two repeating numbers.

Example 1:

Input:
N = 4
array[] = {1,2,1,3,4,3}
Output: 1 3
Explanation: In the given array, 
1 and 3 are repeated two times.
Example 2:

Input:
N = 2
array[] = {1,2,2,1}
Output: 2 1
Explanation: In the given array,
1 and 2 are repeated two times 
and second occurence of 2 comes 
before 1. So the output is 2 1.
Your Task:
The task is to complete the function repeatedElements() which takes array arr[] and an integer N as inputs (the size of the array is N + 2 and elements are in range[1, N]) and finds the two repeated element in the array and return them in a list.
Note: Return the numbers in their order of appearing twice. So, if X and Y are the repeating numbers, and X repeats twice before Y repeating twice, then the order should be (X,Y).

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1). 

Constraints:
2 ≤ N ≤ 105
1 ≤ array[i] ≤ N
*/

	vector<int> twoRepeated (int a[], int n) 
    {
        int m=n+1;
        vector<int>ans;
        for(int i=0;i<n+2;i++)
        {
            a[(a[i]%m) -1 ]+=m;
            if( a[ (a[i]%m)-1 ]/m==2)
            ans.push_back(a[i]%m);
        }
        return ans;
    }