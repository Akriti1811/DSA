/*

Steps by Knight 

Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position coordinates of Knight have been given according to 1-base indexing.

 

Example 1:

Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3
Explanation:

Knight takes 3 step to reach from 
(4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).
 

 

Your Task:
You don't need to read input or print anything. Your task is to complete the function minStepToReachTarget() which takes the initial position of Knight (KnightPos), the target position of Knight (TargetPos), and the size of the chessboard (N) as input parameters and returns the minimum number of steps required by the knight to reach from its current position to the given target position or return -1 if its not possible.

 

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N2).

 

Constraints:
1 <= N <= 1000
1 <= Knight_pos(X, Y), Targer_pos(X, Y) <= N

*/


	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    if(KnightPos==TargetPos)
	    return 0;
	    int dx[8]={1,2,2,1,-1,-2,-2,-1};
	    int dy[8]={2,1,-1,-2,2,1,-1,-2};
	    int steps=1;
	    queue<pair<int,int>>q;
	    vector<vector<bool>> visited(N+1,vector<bool>(N+1,false));
	    q.push({KnightPos[0],KnightPos[1]});
	    visited[KnightPos[0]][KnightPos[1]]=true;
	    while(!q.empty())
	    {
	        queue<pair<int,int>>q1;
	        int flag=0;
	        while(!q.empty())
	        {
	            int r=q.front().first,c=q.front().second;
                q.pop();
                for(int i=0;i<8;i++)
                {
                    int x=r+dx[i],y=c+dy[i];
                    if(x>0 && x<=N && y>0 && y<=N && visited[x][y]==false)
                    {
                        flag=1;
                        if(x==TargetPos[0] && y==TargetPos[1])
                        return steps;
                        q1.push({x,y});
                        visited[x][y]=true;
                    }
                }
	        }
	        if(flag)
	        steps++;
	        swap(q,q1);
	    }
	    return -1;
	}