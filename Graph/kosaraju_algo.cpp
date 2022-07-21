/*

Strongly Connected Components (Kosaraju's Algo)  

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.
 

Example 1:

Input:

Output:
3
Explanation:

We can clearly see that there are 3 Strongly
Connected Components in the Graph
Example 2:

Input:

Output:
1
Explanation:
All of the nodes are connected to each other.
So, there's only one SCC.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function kosaraju() which takes the number of vertices V and adjacency list of the graph as inputs and returns an integer denoting the number of strongly connected components in the given graph.
 

Expected Time Complexity: O(V+E).
Expected Auxiliary Space: O(V).
 

Constraints:
1 ≤ V ≤ 5000
0 ≤ E ≤ (V*(V-1))
0 ≤ u, v ≤ N-1
Sum of E over all testcases will not exceed 25*106

*/	
	void topo_dfs(vector<int> adj[],vector<bool> &visited,int curr,stack<int> &st)
	{
	    visited[curr]=true;
	    
	    for(auto x: adj[curr])
	    {
	        if(!visited[x])
	        topo_dfs(adj,visited,x,st);
	    }
	    st.push(curr);
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int v, vector<int> adj[])
    {
        stack<int>st;
        vector<bool>visited (v,false);
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            topo_dfs(adj,visited,i,st);
        }
        vector <int>topo;
        while(!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
        }
        
        vector<int> rev_adj[v];
        for(int i=0;i<v;i++)
        {
            for(auto x: adj[i])
            {
                rev_adj[x].push_back(i);
            }
        }
        
        fill(visited.begin(),visited.end(),false);
        
        int count=0;
        for(int i=0;i<v;i++)
        {
            if(!visited[topo[i]])
            {
                topo_dfs(rev_adj,visited,topo[i],st);
                count++;
            }
        }
        return count;
    }