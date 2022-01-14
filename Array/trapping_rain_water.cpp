/*
Trapping Rain Water 
Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
Example 1:
Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10
Explanation: 
Example 2:
Input:
N = 4
arr[] = {7,4,0,9}
Output:
10
Explanation:
Water trapped by above 
block of height 4 is 3 units and above 
block of height 0 is 7 units. So, the 
total unit of water trapped is 10 units.
Example 3:
Input:
N = 3
arr[] = {6,9,9}
Output:
0
Explanation:
No water will be trapped.
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/

#include<bits/stdc++.h>
using namespace std;
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int a[], int n)
    {
        int left_max[n],right_max[n];
        long long water=0;
        
        left_max[0]=a[0],right_max[n-1]=a[n-1];
        
        for(int i=1;i<n;i++)
            left_max[i]=max(a[i],left_max[i-1]);
        
        for(int i=n-2;i>=0;i--)
            right_max[i]=max(a[i],right_max[i+1]);
        
        for(int i=1;i<=n-2;i++)
        {
            if(min(left_max[i-1],right_max[i+1])>a[i])
            water+=min(left_max[i-1],right_max[i+1])-a[i];
        }
        return water;
    }
};
int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
		for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;       
    }
    return 0;
} 