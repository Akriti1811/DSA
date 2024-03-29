/*

Pacific Atlantic Water Flow

There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

 

Example 1:


Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Example 2:

Input: heights = [[2,1],[1,2]]
Output: [[0,0],[0,1],[1,0],[1,1]]
 

Constraints:

m == heights.length
n == heights[r].length
1 <= m, n <= 200
0 <= heights[r][c] <= 105

*/

    int m,n;
    vector<vector<bool>>atlantic,pacific;
    queue<pair<int, int> > q;
    vector<vector<int> > ans;

    void bfs(vector<vector<int> >& mat, vector<vector<bool> >& visited, int i, int j)
    {        
        q.push({i, j});
        while(!q.empty())
        {
            tie(i, j) = q.front();
            q.pop();
            if(visited[i][j]) continue;
            
            visited[i][j] = true;
            
            if(atlantic[i][j] && pacific[i][j])
                ans.push_back(vector<int>{i, j});
            
            if(i + 1 <  m && mat[i + 1][j] >= mat[i][j]) q.push({i + 1, j});
            if(i - 1 >= 0 && mat[i - 1][j] >= mat[i][j]) q.push({i - 1, j});
            if(j + 1 <  n && mat[i][j + 1] >= mat[i][j]) q.push({i, j + 1});
            if(j - 1 >= 0 && mat[i][j - 1] >= mat[i][j]) q.push({i, j - 1});
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& height) 
    {
        m=height.size(),n=height[0].size();
        if(m==0)
            return ans;
        atlantic = pacific = vector<vector<bool> >(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++)
            bfs(height, pacific, i, 0), bfs(height, atlantic, i, n - 1);
        for(int i = 0; i < n; i++)
            bfs(height, pacific, 0, i), bfs(height, atlantic, m - 1, i);             
        return ans;
        
    }