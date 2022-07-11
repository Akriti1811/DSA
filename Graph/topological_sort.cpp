/*

Topological sort 
  
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.


Example 1:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 3, 2, 1, 0.
Example 2:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 5, 4, 2, 1, 3, 0.

Your Task:
You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of a the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then console output will be 1 else 0.


Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).


Constraints:
2 ≤ V ≤ 104
1 ≤ E ≤ (N*(N-1))/2

*/


//BFS Based Algorithm (Kahn's ALgorithm)

	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    vector<int>indeg(v,0);
	    for(int i=0;i<v;i++)
	    {
	        for(auto x: adj[i])
	        {
	            indeg[x]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i=0;i<v;i++)
	    {
	        if(indeg[i]==0)
	        q.push(i);
	    }
	    vector<int>ans;
	    
	    while(!q.empty())
	    {
	       int top=q.front();
	       ans.push_back(top);
	       q.pop();
	       
	       for(auto x: adj[top])
	       {
	           indeg[x]--;
	           if(indeg[x]==0)
	           q.push(x);
	       }
	    }
	    
	    return ans;
	}




//DFS Based Algorithm

	void dfs(vector<int> adj[],vector<bool>& visited,stack<int>&s,int curr)
	{
	    visited[curr]=true;
        for(auto x:adj[curr])
        {
            if(visited[x]==false)
                dfs(adj,visited,s,x);
        }
        s.push(curr);
	}
	
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    stack<int>s;
	    vector<int>ans;
	    vector<bool>visited(v,false);
        for(int i=0;i<v;i++)
        {
            if(visited[i]==false)
            dfs(adj,visited,s,i);
        }
        
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
	    return ans;
	}