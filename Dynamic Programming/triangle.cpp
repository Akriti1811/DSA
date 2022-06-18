/*

Triangle


Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104

*/


int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n=triangle.size();
        int path[n][n];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                path[i][j]=INT_MAX;
            }
        }
        
        for(int i=0;i<n;i++)
            path[n-1][i]=triangle[n-1][i];
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                int val=triangle[i][j];
                path[i][j]=min(path[i][j],min(val+path[i+1][j],val+path[i+1][j+1]));
            }
        }
        return path[0][0];
        
    }