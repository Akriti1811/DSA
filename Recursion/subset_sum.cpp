/*

Subset Sums 
Basic Accuracy: 56.36% Submissions: 20316 Points: 1
Given a list arr of N integers, print sums of all subsets in it.

 

Example 1:

Input:
N = 2
arr[] = {2, 3}
Output:
0 2 3 5
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then 
Sum = 2+3 = 5.
Example 2:

Input:
N = 3
arr = {5, 2, 1}
Output:
0 1 2 3 5 6 7 8
Your Task:  
You don't need to read input or print anything. Your task is to complete the function subsetSums() which takes a list/vector and an integer N as an input parameter and return the list/vector of all the subset sums.

Expected Time Complexity: O(2N)
Expected Auxiliary Space: O(2N)

Constraints:
1 <= N <= 15
0 <= arr[i] <= 104
*/

void sum(vector<int>a,vector<int> &ans,int s,int ind,int n)
    {
        if(ind==n)
        {
            ans.push_back(s);
            return;
        }
        sum(a,ans,s,ind+1,n);
        sum(a,ans,s+a[ind],ind+1,n);
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector <int>ans;
        sum(arr,ans,0,0,n);
        return ans;
    }