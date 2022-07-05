/*

Number of Islands

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

*/




    int numIslands(vector<vector<char>>& grid) 
    {
        int row=grid.size(),col=grid[0].size();
        vector<vector<bool>> visited (row,vector<bool>(col,false));
        int c=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==false)
                {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j]=true;
                    while(!q.empty())
                    {
                        int r=q.front().first,c=q.front().second;
                        cout<<grid[r][c]<<" ";
                        q.pop();
                        
                        if((r-1)>=0 && grid[r-1][c]=='1' && visited[r-1][c]==false)
                        {
                            q.push({r-1,c});
                            visited[r-1][c]=true;
                        }
                        if((c-1)>=0 && grid[r][c-1]=='1' && visited[r][c-1]==false)
                        {
                            q.push({r,c-1});
                            visited[r][c-1]=true;
                        }
                        if((r+1)<row && grid[r+1][c]=='1' && visited[r+1][c]==false)
                        {
                            q.push({r+1,c});
                            visited[r+1][c]=true;
                        }
                        if((c+1)<col && grid[r][c+1]=='1' && visited[r][c+1]==false)
                        {
                            q.push({r,c+1});
                            visited[r][c+1]=true;
                        }
                    }
                    c++;
                }
            }
        }
        return c;
        
    }





    int row,col;
    vector<vector<char>> grid;
    vector<vector<bool>> visited;
    
    bool valid(int i,int j)
    {
        if(i>=0 && i<row && j>=0 && j<col && grid[i][j]=='1' && visited[i][j]==false)
            return true;
        return false;
    }
    
    int numIslands(vector<vector<char>>& gridd) 
    {
        row=gridd.size(),col=gridd[0].size();
        grid.resize(row,vector<char>(col));
        visited.resize(row,vector<bool>(col,false));
        
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                grid[i][j]=gridd[i][j];
        
        int count=0;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,+1};
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==false)
                {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j]=true;
                    while(!q.empty())
                    {
                        int r=q.front().first,c=q.front().second;   
                        q.pop();   
                        for(int i=0;i<4;i++)
                        {
                            int x=r+dx[i];
                            int y=c+dy[i];
                            if(valid(x,y))
                            {
                                q.push({x,y});
                                visited[x][y]=true;
                            }
                        }
                        
                    }
                    count++;
                }
            }
        }
        return count;
        
    }