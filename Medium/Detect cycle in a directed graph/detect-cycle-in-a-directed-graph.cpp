//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
// VISITED = any node that gets visited once is marked true 
// DFSVisited = any node whose dfs call is present in the function call stack is marked true 
//              once returns it is marked false

// if a node is visited && dfsVisited then cycle is PRESENT
  bool isCyclicDFS(int src, vector<bool>& visited,
                vector<bool> &dfsVisited, vector<int> adj[])
    {
        visited[src] = true ;
        dfsVisited[src] = true ;
        
        for (auto nbr : adj[src])
        {
            if (!visited[nbr])
            {
                bool ans = isCyclicDFS(nbr, visited, dfsVisited, adj) ;
                
                if (ans)
                {
                    return true ;
                }
            }
            
            if (visited[nbr] && dfsVisited[nbr])
            {
                return true ; 
            }
        }
        dfsVisited[src] = false ;
        return false ;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited (V, false) ; 
        vector<bool> dfsVisited (V, false) ;
        
        for (int i = 0 ; i < V ; i ++)
        {
            if (!visited[i])
            {
                bool ans = isCyclicDFS(i, visited, dfsVisited, adj) ;
                
                if (ans == true)
                {
                    return true ;
                }
            }
        }
        return false ;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends