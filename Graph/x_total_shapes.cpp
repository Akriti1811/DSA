/*

 X Total Shapes 
 
Given  a grid of n*m consisting of O's and X's. The task is to find the number of 'X' total shapes.
Note: 'X' shape consists of one or more adjacent X's (diagonals not included).
 

Example 1:

Input: grid = {{X,O,X},{O,X,O},{X,X,X}}
Output: 3
Explanation: 
The grid is-
X O X
O X O
X X X
So, X with same colour are adjacent to each 
other vertically for horizontally (diagonals 
not included). So, there are 3 different groups 
in the given grid.

Example 2:

Input: grid = {{X,X},{X,X}}
Output: 1
Expanation: 
The grid is- 
X X
X X
So, X with same colour are adjacent to each
other vertically for horizontally (diagonals
not included). So, there is only 1 group
in the given grid.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function xShape() which takes grid as input parameter and returns the count of total X shapes.
 

Expected Time Compelxity: O(n*m)
Expected Space Compelxity: O(n*m)
 

Constraints:
1 ≤ n, m ≤ 100

*/



   int xShape(vector<vector<char>>& grid) 
    {
        int row=grid.size(),col=grid[0].size();
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        int count=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='X')
                {
                    count++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    grid[i][j]='O';
                    while(!q.empty())
                    {
                        int r=q.front().first,c=q.front().second;
                        q.pop();
                        for(int i=0;i<4;i++)
                        {
                            int x=r+dx[i],y=c+dy[i];
                            if(x>=0 && x<row && y>=0 && y<col && grid[x][y]=='X')
                            {
                                q.push({x,y});
                                grid[x][y]='O';
                            }
                            
                        } 
                    }
                }
            }
        }
        return count;
    }