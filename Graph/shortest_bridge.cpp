/*

Shortest Bridge

You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.

 

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 1
Example 2:

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
Example 3:

Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
 

Constraints:

n == grid.length == grid[i].length
2 <= n <= 100
grid[i][j] is either 0 or 1.
There are exactly two islands in grid.

*/


    int row,col;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    
    void paint(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>> &q) 
    {
        if (i>=0 && i<row && j>=0 && j<col && grid[i][j] == 1) 
        { 
            grid[i][j] = 2;
            q.push({i, j});
            for (int d = 0; d < 4; ++d)
                paint(grid, i + dx[d], j + dy[d], q);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) 
    {
        queue<pair<int, int>> q;
        row= grid.size();
        col=grid[0].size();
        for (int i = 0; q.empty() && i <row; ++i)
            for (int j = 0; q.empty() && j < col; ++j)
                paint(grid, i, j, q);
        while (!q.empty()) 
        {
            queue<pair<int, int>> q1;
            while(!q.empty()){
            int i=q.front().first,j=q.front().second;
            q.pop();
                for (int d = 0; d < 4; ++d) 
                {
                    int x = i + dx[d], y = j + dy[d];
                    if (x>=0 && x<row && y>=0 && y<col) 
                    {
                        if (grid[x][y] == 1)
                            return grid[i][j] - 2;
                        if (grid[x][y] == 0) 
                        {
                            grid[x][y] = grid[i][j] + 1;
                            q1.push({x, y});
                        }
                    }
                }
            }
            swap(q, q1);
        }
        return 0;
    }