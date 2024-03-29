/*

Implementing Dijkstra Algorithm 
   
Given a weighted, undirected and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
Note: The Graph doesn't contain any negative weight cycle.

 

Example 1:

Input:
V = 2, E = 1
u = 0, v = 1, w = 9
adj [] = {{{1, 9}}, {{0, 9}}}
S = 0
Output:
0 9
Explanation:

The source vertex is 0. Hence, the shortest 
distance of node 0 is 0 and the shortest 
distance from node 9 is 9 - 0 = 9.
 

Example 2:

Input:
V = 3, E = 3
u = 0, v = 1, w = 1
u = 1, v = 2, w = 3
u = 0, v = 2, w = 6
adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}
S = 2
Output:
4 3 0
Explanation:

For nodes 2 to 0, we can follow the path-
2-1-0. This has a distance of 1+3 = 4,
whereas the path 2-0 has a distance of 6. So,
the Shortest path from 2 to 0 is 4.
The other distances are pretty straight-forward.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function dijkstra()  which takes the number of vertices V and an adjacency list adj as input parameters and returns a list of integers, where ith integer denotes the shortest distance of the ith node from the Source node. Here adj[i] contains a list of lists containing two integers where the first integer j denotes that there is an edge between i and j and the second integer w denotes that the weight between edge i and j is w.

 

Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V2).

 

Constraints:
1 ≤ V ≤ 1000
0 ≤ adj[i][j] ≤ 1000
1 ≤ adj.size() ≤ [ (V*(V - 1)) / 2 ]
0 ≤ S < V

*/



   vector <int> dijkstra(int v, vector<vector<int>> adj[], int S)
    {
        vector<bool>fin(v,false);
        vector<int>dist(v,INT_MAX);
        dist[S]=0;
        for(int count=0;count<v;count++)
        {
            int u=-1;
            for(int i=0;i<v;i++)
            {
                if(!fin[i] && (u==-1 || dist[i]<dist[u]))
                    u=i;
            }
            fin[u]=true;
            for(int j=0;j<adj[u].size();j++)
            {
                if(adj[u][j][1]!=0 && !fin[adj[u][j][0]])
                    dist[adj[u][j][0]]=min(dist[adj[u][j][0]],dist[u]+adj[u][j][1]);
            }
        }
        return dist;
    }