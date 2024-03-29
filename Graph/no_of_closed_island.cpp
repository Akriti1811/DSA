/*

Number of Closed Islands

Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

 

Example 1:



Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).
Example 2:



Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1
Example 3:

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2
 

Constraints:

1 <= grid.length, grid[0].length <= 100
0 <= grid[i][j] <=1

*/



class Solution {
public:
    
    int row,col;
    vector<vector<int>> grid;
    
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,+1};
    
    bool valid(int i,int j)
    {
        if(i>=0 && i<row && j>=0 && j<col && grid[i][j]==0 )
            return true;
        return false;
    }
    
    void bfs(int i,int j)
    {
        queue<pair<int,int>> q;
        q.push({i,j});
            while(!q.empty())
            {
                int r=q.front().first,c=q.front().second;
                grid[r][c]=1;
                q.pop();
                        
                for(int i=0;i<4;i++)
                {
                    int x=r+dx[i];
                    int y=c+dy[i];
                            
                    if(valid(x,y))
                    {
                        q.push({x,y});
                        grid[x][y]=1;
                    }
                }
                        
            }
        
    }
    
    int closedIsland(vector<vector<int>>& gridd) 
    {
        row=gridd.size(),col=gridd[0].size();
        grid.resize(row,vector<int>(col));
        
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                grid[i][j]=gridd[i][j];
        
        int count=0;
        
        for(int i=0;i<row;i++)
        {
            if(grid[i][0]==0)
                bfs(i,0);
            if(grid[i][col-1]==0)
                bfs(i,col-1);
        }
        
        for(int j=0;j<col;j++)
        {
            if(grid[0][j]==0)
                bfs(0,j);
            if(grid[row-1][j]==0)
                bfs(row-1,j);
        }
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==0)
                {   
                    bfs(i,j);
                    count++;
                }
            }
        }
        return count;
        
    }
    
     
};