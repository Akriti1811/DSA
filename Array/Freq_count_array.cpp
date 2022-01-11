/*
Frequencies of Limited Range Array Elements 
Given an array A[] of N positive integers which can contain integers from 1 to P where elements can be repeated or can be absent from the array. Your task is to count the frequency of all elements from 1 to N.
Note: The elements greater than N in the array can be ignored for counting.

Example 1:

Input:
N = 5
arr[] = {2, 3, 2, 3, 5}
P = 5
Output:
0 2 2 0 1
Explanation: 
Counting frequencies of each array element
We have:
1 occurring 0 times.
2 occurring 2 times.
3 occurring 2 times.
4 occurring 0 times.
5 occurring 1 time.
*/

#include<bits/stdc++.h>
using namespace std; 
class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& a,int n, int p)
    { 
        int f[n]={0};
        for(int i=0;i<n;i++)
        {
            if(a[i]>n)
            continue;
            f[a[i]-1]++;
        }
        for(int i=0;i<n;i++)
        {
            a[i]=f[i];
        }
        
        /*Using  O(1) extra space and O(n) time
        This is possible only for the case when elements range from 1 to N*/
        
        
        // for(int i=0;i<n;i++)
        //     a[i]--;
        // for(int i=0;i<n;i++)
        //     a[a[i]%n]+=n;
        // for(int i=0;i<n;i++)
        //     a[i]/=n;
            
    }
};


int main() 
{ 
	long long t;
	
	//testcases
	cin >> t;
	
	while(t--){
	    
	    int N, P;
	    cin >> N; 
	    
	    vector<int> arr(N);
	    for(int i = 0; i < N ; i++){
	        cin >> arr[i]; 
	    }
        cin >> P;
        Solution ob;
		ob.frequencyCount(arr, N, P); 
	    for (int i = 0; i < N ; i++) 
			cout << arr[i] << " ";
	    cout << endl;
	}	
	return 0; 
}