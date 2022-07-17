/*

 Find whether path exist 

Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall.
Note: There are only a single source and a single destination.
 

Example 1:

Input: grid = {{3,0,3,0,0},{3,0,0,0,3}
,{3,3,3,3,3},{0,2,3,0,0},{3,0,0,1,3}}
Output: 0
Explanation: The grid is-
3 0 3 0 0 
3 0 0 0 3 
3 3 3 3 3 
0 2 3 0 0 
3 0 0 1 3 
There is no path to reach at (3,1) i,e at 
destination from (4,3) i,e source.
Example 2:

Input: grid = {{1,3},{3,2}}
Output: 1
Explanation: The grid is-
1 3
3 2
There is a path from (0,0) i,e source to (1,1) 
i,e destination.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function is_Possible() which takes the grid as input parameter and returns boolean value 1 if there is a path otherwise returns 0.
 

Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)
 

Constraints:
1 ≤ n ≤ 500

*/

    bool is_Possible(vector<vector<int>>& grid) 
    {
        int row=grid.size(),col=grid[0].size();
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        queue<pair<int,int>>q;
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
            if(grid[i][j]==1)
            {
                q.push({i,j});
                grid[i][j]=0;
                break;
            }
            
        while(!q.empty())
        {
            int r=q.front().first,c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x=r+dx[i],y=c+dy[i];
                
                if(x>=0 &&x<row && y>=0 && y<col)
                {
                    if(grid[x][y]==2)
                    return true;
                    else
                    if(grid[x][y]==3)
                    {
                        q.push({x,y});
                        grid[x][y]=0;
                    }
                }
            }
        }
        return false;
    }