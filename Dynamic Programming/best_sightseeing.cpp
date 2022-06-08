/*

Best Sightseeing Pair

You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.

 

Example 1:

Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
Example 2:

Input: values = [1,2]
Output: 2
 

Constraints:

2 <= values.length <= 5 * 104
1 <= values[i] <= 1000

*/



//Time Complexity:O(n)  Auxiliary Space:O(n)

	int maxScoreSightseeingPair(vector<int>& values) 
    {
        int ans=INT_MIN;int n=values.size();
        int maxEndRight[n];
        maxEndRight[n-1]=INT_MIN;
        for(int i=n-2;i>=0;i--)
        {
            maxEndRight[i]=max( maxEndRight[i+1], values[i+1]-(i+1) );
            ans=max(ans,values[i]+i+maxEndRight[i]);
        }
        return ans;
    }




//Time Complexity:O(n)  Auxiliary Space:O(1)

    int maxScoreSightseeingPair(vector<int>& values) 
    {
        int ans=INT_MIN;int n=values.size();
        
        int maxEndRight=INT_MIN;
        for(int i=n-2;i>=0;i--)
        {
            maxEndRight=max( maxEndRight, values[i+1]-(i+1) );
            ans=max(ans,values[i]+i+maxEndRight);
        }
        return ans;
    }