//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    // STEP 1 : Store startingNode in queue
    // STEP 2 : Mark visited 
    // STEP 3 : Iterate till queue not empty
    // STEP 4 : fetch frontNode from queue
    // STEP 5 : Pop queue 
    // STEP 6 : Store frontNode in answer vector storing VFS
    // STEP 7 : Fetch neighbours of frontNode from adjacency list
    // STEP 8 : if a neighbour is unvisited, push it in queue and mark visited
    void bfsUtil(int node, vector<int> adj[], vector<bool> &visited, vector<int>& ans)
    {
        queue<int> q ; 
        q.push(node) ; 
        visited[node] = true ; 
        
        while (!q.empty())
        {
            int front = q.front() ; 
            q.pop() ;
            
            ans.push_back(front) ; 
            
            for (int nbr : adj[front])
            {
                if (!visited[nbr])
                {
                    q.push(nbr) ;
                    visited[nbr] = true ;
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        // Visited Array -> to ensure all nodes are processed only once and 
        // we dont get stuck in infinite loop between two positions 
        vector<bool> visited (V, false) ; 
        
        // ans vector stores bfs traversal 
        vector<int> ans ; 
        
        // connected graph so no need of for loop to ensure all nodes get visited and none left unvisited
        int start = 0 ; 
        bfsUtil(start, adj, visited, ans) ;
        
        return ans ; 
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends