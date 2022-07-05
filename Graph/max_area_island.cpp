/*

Max Area of Island

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 

Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.


*/



    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int row=grid.size(),col=grid[0].size();
        vector<vector<bool>> visited (row,vector<bool>(col,false));
        int maxarea=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1 && visited[i][j]==false)
                {
                    int area=1;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j]=true;
                    
                    while(!q.empty())
                    {
                        int r=q.front().first,c=q.front().second;
                        cout<<grid[r][c]<<" ";
                        q.pop();
                        
                        if((r-1)>=0 && grid[r-1][c]==1 && visited[r-1][c]==false)
                        {
                            q.push({r-1,c});
                            visited[r-1][c]=true;
                            area++;
                        }
                        if((c-1)>=0 && grid[r][c-1]==1 && visited[r][c-1]==false)
                        {
                            q.push({r,c-1});
                            visited[r][c-1]=true;
                            area++;
                        }
                        if((r+1)<row && grid[r+1][c]==1 && visited[r+1][c]==false)
                        {
                            q.push({r+1,c});
                            visited[r+1][c]=true;
                            area++;
                        }
                        if((c+1)<col && grid[r][c+1]==1 && visited[r][c+1]==false)
                        {
                            q.push({r,c+1});
                            visited[r][c+1]=true;
                            area++;
                        }
                    }
                    maxarea=max(maxarea,area);
                }
            }
        }
        return maxarea;
        
    }