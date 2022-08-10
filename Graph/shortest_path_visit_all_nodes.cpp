/*

Shortest Path Visiting All Nodes



-
You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

 

Example 1:


Input: graph = [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
Example 2:


Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]
 

Constraints:

n == graph.length
1 <= n <= 12
0 <= graph[i].length < n
graph[i] does not contain i.
If graph[a] contains b, then graph[b] contains a.
The input graph is always connected.

*/


    int shortestPathLength(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        if(n==1)
            return 0;
        queue<pair<int,pair<int,int>>>q;
        set<pair<int,int>>visited;
        int all=(1<<n) -1;
        
        for(int i=0;i<n;i++)
        {
            int mask=1<<i;
            q.push({i,{0,mask}});
            visited.insert({i,mask});
        }
        while(!q.empty())
        {
            auto node=q.front();
            int val=node.first,dist=node.second.first,mask=node.second.second;
            q.pop();
            for(auto x: graph[val])
            {
                int newmask=(mask|(1<<x));
                if(newmask==all)
                    return dist+1;
                else if (visited.count({x,newmask}))
                    continue;
                else
                {
                    visited.insert({x,newmask});
                    q.push({x,{dist+1,newmask}});
                }
            }
        }
        return 0;
    }