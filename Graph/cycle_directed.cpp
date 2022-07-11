/*

Detect cycle in a directed graph 

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


Example 1:

Input:



Output: 1
Explanation: 3 -> 3 is a cycle

Example 2:

Input:


Output: 0
Explanation: no cycle in the graph

Your task:
You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)


Constraints:
1 ≤ V, E ≤ 105

*/

//DFS Based Algorithm

   bool dfs(vector<int> adj[],vector<bool>& visited,vector<bool>&recStack,int curr)
    {
        visited[curr]=true;
        recStack[curr]=true;
        for(auto x:adj[curr])
        {
            if(visited[x]==false)
            {
                if(dfs(adj,visited,recStack,x)==true)
                return true;
            }
            else if(recStack[x]==true)
            return true;
        }
        recStack[curr]=false;
        return false;
    }
    
    bool isCyclic(int v, vector<int> adj[]) 
    {
        vector<bool>visited(v,false);
        vector<bool>recStack(v,false);
        for(int i=0;i<v;i++)
        {
            if(visited[i]==false)
            {
                if(dfs(adj,visited,recStack,i)==true)
                return true;
            }
        }
        return false;
    }



//BFS Based Algorithm (Kahn's ALgorithm)

    bool isCyclic(int v, vector<int> adj[]) 
    {
        vector<int>indeg(v,0);
        for(int i=0;i<v;i++)
        {
            for(auto x: adj[i])
                indeg[x]++;
        }
        
        queue<int>q;
        for(int i=0;i<v;i++)
        {
            if(indeg[i]==0)
            q.push(i);
        }
        int count=0;
        while(!q.empty())
        {
           int top=q.front();
           count++;
           q.pop();
           
           for(auto x: adj[top])
           {
               indeg[x]--;
               if(indeg[x]==0)
               q.push(x);
           }
        }
        
        return count!=v;
    }