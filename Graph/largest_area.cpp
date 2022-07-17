/*

 Unit Area of largest region of 1's 
 
Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).
 

Example 1:

Input: grid = {{1,1,1,0},{0,0,1,0},{0,0,0,1}}
Output: 5
Explanation: The grid is-
1 1 1 0
0 0 1 0
0 0 0 1
The largest region of 1's is colored
in orange.
Example 2:

Input: grid = {{0,1}}
Output: 1
Explanation: The grid is-
0 1
The largest region of 1's is colored in 
orange.

Your Task:
You don't need to read or print anyhting. Your task is to complete the function findMaxArea() which takes grid as input parameter and returns the area of the largest region of 1's.


Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)
 

Constraints:
1 ≤ n, m ≤ 500

*/


    int findMaxArea(vector<vector<int>>& grid) 
    {
        int row=grid.size(),col=grid[0].size();
        int dx[8]={1,1,1,-1,-1,-1,0,0};
        int dy[8]={1,-1,0,1,-1,0,1,-1};
        int area=0,maxarea=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    area=1;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    grid[i][j]=0;
                    while(!q.empty())
                    {
                        int r=q.front().first,c=q.front().second;
                        q.pop();
                        for(int i=0;i<8;i++)
                        {
                            int x=r+dx[i],y=c+dy[i];
                            if(x>=0 && x<row && y>=0 && y<col && grid[x][y]==1)
                            {
                                q.push({x,y});
                                area++;
                                grid[x][y]=0;
                            }
                            
                        } 
                    }
                }
                maxarea=max(area,maxarea);
            }
        }
        return maxarea;
    }