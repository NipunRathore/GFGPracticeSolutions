//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <bits/stdc++.h>

// Kosaraju Algorithm for STRONGLY CONNECTED COMPONENTS
// A graph is Strongly Connected is there is a path between all pair of vertices
// A Strongly Connected Component is a MAXIMAL STRONGLY CONNECTED SUBGRAPH

// Strongly Connected Component is the component of a graph in which all nodes are reachable from all other nodes 

// 3 steps 
// STEP 1 : Find Topological Sort Linear Ordering
// STEP 2 : Create Transpose Graph 
// STEP 3 : Apply DFS on the Topological Sort Linear Ordering & Transpose Graph
class Solution
{
    private:
    // Topological Sort
    void dfsTopoSortUtil (int node, stack<int>& st, unordered_map<int, bool>& visited, 
                        vector<vector<int> >& adj)
    {
        visited[node] = true ; 
        
        for (auto nbr : adj[node])
        {
            if (!visited[nbr])
            {
                dfsTopoSortUtil (nbr, st, visited, adj) ;
            }
        }
        st.push(node) ; 
    }
    
    // Normal DFS
    void dfsUtil (int node, unordered_map<int, bool> &visited, 
                unordered_map<int, list<int> > &adj)
    {
        visited[node] = true ; 
        
        for (auto nbr : adj[node])
        {
            if (!visited[nbr])
            {
                dfsUtil(nbr, visited, adj) ;
            }
        }
    }
    
    public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        unordered_map<int, bool> visited ; 
        stack<int> st ; 
        
        for (int i = 0 ; i < V ; i ++)
        {
            if (!visited[i])
            {
                dfsTopoSortUtil (i, st, visited, adj) ;
            }
        }
        
        // transpose graph adjacency list 
        // 2 ways 
        // either use edges array to create edges from vertex v to u 
        // or use adjacency list of original graph to create edge from neighbour to vertex
        unordered_map<int, list<int> > transposeAdj ; 
        for (int i = 0 ; i < V ; i ++)
        {
            visited[i] = false ;
            for (auto nbr : adj[i])
            {
                transposeAdj[nbr].push_back(i) ;
            }
        }
        
        // Perform DFS on Topo Sort Linear Ordering (stored in stack) & Transpose Graph
        int cnt = 0 ; 
        while (!st.empty()) 
        {
            int top = st.top() ; 
            st.pop() ;
            
            if (!visited[top])
            {
                cnt ++ ; 
                // DFS call terminates after one strongly connected component has been explored, 
                // so increase cnt  
                dfsUtil(top, visited, transposeAdj) ;
            }
        }
        
        return cnt ;
    }
};
// T.C. = O (N + E)
// S.C. = O (N + E)


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