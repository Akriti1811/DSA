/*

01 Matrix

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.

*/



    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) 
    {
        int row=grid.size(),col=grid[0].size();
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        
        vector<vector<int>> dist (row,vector<int>(col,INT_MAX));
        queue<pair<int,int>>q;
        for(int  i=0;i<row;i++)
        {
            for (int j=0;j<col;j++)
            {
                if(grid[i][j]==0)
                {
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty())
        {
            int r=q.front().first,c=q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                int x=r+dx[k];
                int y=c+dy[k];
                
                if(x>=0 && x<row && y>=0 && y<col)
                {
                    if(dist[x][y]>dist[r][c]+1)
                    {
                        dist[x][y]=dist[r][c]+1;
                        q.push({x,y});
                    }
                }
            }
            
        }
        return dist;
    }