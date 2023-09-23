//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    
    bool isCyclicBFS(int src, vector<int> adj[], unordered_map<int, bool> &visited)
    {
        // parent data structure to keep track of parent of all nodes
        unordered_map<int, int> parent ; 
        queue<int> q ; 
        
        // let, parent of src node be -1 
        parent[src] = -1 ; 
        // Normal BFS 
        visited[src] = true ; 
        q.push(src) ; 
        
        while (!q.empty())
        {
            int front = q.front() ; 
            q.pop() ;
            
            for (auto nbr : adj[front])
            {
                if (!visited[nbr])
                {
                    q.push(nbr) ;
                    visited[nbr] = true ;
                    parent[nbr] = front ;
                }
                // else if VISITED && NBR != PARENT[FRONT] -> CYCLE PRESENT 
                else
                {
                    if (nbr != parent[front])
                    {
                        return true ; 
                    }
                }
            }
        }
        return false ;
    }
    
    // TIME COMPLEXITY -> O(N + E), same as BFS just one extra data structure parent and one additional if condition used
    // Space Complexity -> O(N + E), same as Normal BFS
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int, bool> visited ; 
        
        for (int i = 0 ; i < V ; i ++)
        {
            if (!visited[i])
            {
                bool ans = isCyclicBFS(i, adj, visited) ;
                
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
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends