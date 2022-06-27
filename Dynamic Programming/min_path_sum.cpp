/*

Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100

*/

    int minPathSum(vector<vector<int>>& grid) 
    {
        int row=grid.size(),col=grid[0].size();
        vector<vector<int>> sum(row,vector<int>(col,grid[0][0]));
        for(int i=1;i<row;i++)
            sum[i][0]=sum[i-1][0]+grid[i][0];
        for(int j=1;j<col;j++)
            sum[0][j]=sum[0][j-1]+grid[0][j];
        
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                sum[i][j]=min(sum[i-1][j],sum[i][j-1])+grid[i][j];
            }
        }
        return sum[row-1][col-1];
    }



    int minPathSum(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();
        vector<int> pre(m, grid[0][0]);
        vector<int> cur(m, 0);
        for (int i = 1; i < m; i++)
            pre[i] = pre[i - 1] + grid[i][0];
        for (int j = 1; j < n; j++) 
        { 
            cur[0] = pre[0] + grid[0][j]; 
            for (int i = 1; i < m; i++)
                cur[i] = min(cur[i - 1], pre[i]) + grid[i][j];
            swap(pre, cur); 
        }
        return pre[m - 1];
    }



    int minPathSum(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();
        vector<int> curr(m, grid[0][0]);
        
        for (int i = 1; i < m; i++)
            curr[i] = curr[i - 1] + grid[i][0];
        for (int j = 1; j < n; j++) 
        { 
            curr[0] = curr[0] + grid[0][j]; 
            for (int i = 1; i < m; i++)
                curr[i] = min(curr[i - 1], curr[i]) + grid[i][j];
             
        }
        return curr[m - 1];
    }