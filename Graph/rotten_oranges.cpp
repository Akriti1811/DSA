/*

Rotten Oranges   

Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
 

Example 1:

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and 
(2,1) in unit time.
Example 2:

Input: grid = {{2,2,0,1}}
Output: -1
Explanation: The grid is-
2 2 0 1
Oranges at (0,0) and (0,1) can't rot orange at
(0,3).
 

Your Task:
You don't need to read or print anything, Your task is to complete the function orangesRotting() which takes grid as input parameter and returns the minimum time to rot all the fresh oranges. If not possible returns -1.
 

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n)
 

Constraints:
1 ≤ n, m ≤ 500

*/


    int orangesRotting(vector<vector<int>>& grid) 
    {
        int row=grid.size(),col=grid[0].size();
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        queue<pair<int,int>>q;
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
            if(grid[i][j]==2)
                q.push({i,j});
        int time=0;
        while(!q.empty())
        {
            queue<pair<int,int>>q1;
            int flag=0;
            while(!q.empty())
            {
                int r=q.front().first,c=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int x=r+dx[i],y=c+dy[i];
                    if(x>=0 &&x<row && y>=0 && y<col && grid[x][y]==1)
                    {
                        flag=1;
                        grid[x][y]=2;
                        q1.push({x,y});
                    }
                }
            }
            if(flag)
            time++;
            swap(q,q1);
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            if(grid[i][j]==1)
            return -1;
        }
        return time;
    }