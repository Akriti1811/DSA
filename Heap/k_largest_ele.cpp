/*

K largest elements 

Given an array of N positive integers, print k largest elements from the array. 

Example 1:

Input:
N = 5, k = 2
arr[] = {12,5,787,1,23}
Output: 787 23
Explanation: First largest element in
the array is 787 and the second largest
is 23.
Example 2:

Input:
N = 7, k = 3
arr[] = {1,23,12,9,30,2,50}
Output: 50 30 23
Explanation: Three Largest element in
the array are 50, 30 and 23.
Your Task:
Complete the function kLargest() that takes the array, N and K as input parameters and returns a list of k largest element in descending order. 

Expected Time Complexity: O(N log K)
Expected Auxiliary Space: O(K)

Constraints:
1 ≤ N ≤ 104
K ≤ N
1 ≤ array[i] ≤ 105


*/


	vector<int> kLargest(int arr[], int n, int k)
    {
       priority_queue<int,vector<int>,greater<int>>minh;
        
        for(int i=0;i<n;i++)
        {
            minh.push(arr[i]);
            if(minh.size()>k)
                minh.pop();
        }
        
        vector<int>ans;
        while(!minh.empty())
        {
            ans.push_back(minh.top());
            minh.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }