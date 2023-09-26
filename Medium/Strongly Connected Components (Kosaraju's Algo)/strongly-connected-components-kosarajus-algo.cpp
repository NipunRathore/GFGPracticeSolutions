//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
void dfs (int node, unordered_map<int, bool>& visited, stack<int>& st,
            vector<vector<int>>& adj)

{
    visited[node] = true ; 

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, visited, st, adj) ; 
        }
    }
    st.push(node) ;    
}
void revDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> & adj)
{
    visited[node] = true ; 

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            revDFS(neighbour, visited, adj ) ; 
        }
    }
}

	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        int v = V ; 
    //     unordered_map<int, list<int>> adj ; 

    // for (int i = 0 ; i < edges.size() ; i ++)
    // {
    //     int u = edges[i][0] ; 
    //     int v = edges[i][1] ; 

    //     adj[u].push_back(v) ; 
    // }

    // topological sort 
    // using DFS 
    stack<int> st ; 
    unordered_map<int, bool> visited ; 
    
    for (int i = 0 ; i < v ; i++)
    {
        // in order to make all node unvisited again 
        if (!visited[i])
        {
            dfs(i, visited, st, adj) ; 
        }
    }

    // transpose graph 
    unordered_map<int, list<int>> transpose ; 
    for (int i = 0 ; i < v ; i ++)
    {
        visited[i] = 0 ; 
        for (auto neighbour : adj[i])
        {
            transpose[neighbour].push_back(i) ; 
        }
    }

    // now perform dfs on the topological sort ordering 
    int cnt = 0 ; 
    while (!st.empty())
    {
        int top = st.top() ; 
        st.pop() ; 
        if (!visited[top])
        {
            cnt ++ ; 
            revDFS(top, visited, transpose) ; 
        }
    }
    return cnt ; 
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends