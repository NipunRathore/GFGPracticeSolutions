//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    // 2 STEPS 
    // Find the Topological Sort Ordering
    // Utilize the linear ordering to update the Distance array 
  public:
// Why need Topo Sort Ordering ?
// It tells us edgewise which node comes first
// Tells us which node to start from and which node to move towards
    void dfsTopoUtil (int node, unordered_map<int, list<pair<int, int> > >& adj,
                        vector<bool>& visited, stack<int> &st)
    {
        visited[node] = true ; 
        
        for (auto nbr : adj[node])
        {
            if (!visited[nbr.first])
            {
                dfsTopoUtil(nbr.first, adj, visited, st) ;
            }
        }
        
        st.push(node) ;
    }
    
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        unordered_map<int, list<pair<int, int> > > adj ; 
        for (int i = 0 ; i < M ; i ++)
        {
            int u = edges[i][0] ; 
            int v = edges[i][1] ; 
            int wt = edges[i][2] ; 
            
            pair<int, int> p = make_pair(v, wt) ; 
            adj[u].push_back(p) ; 
        }
        
        stack<int> st ; 
        vector<bool> visited (N, false) ; 
        
        for (int i = 0 ; i < N ; i ++)
        {
            if (!visited[i])
            {
                dfsTopoUtil (i, adj, visited, st) ; 
            }
        }
        
        // initialise distance array with INT_MAX
        int src = 0 ; 
        vector<int> distance (N, INT_MAX) ; 
        // assign distance of source as 0 
        distance[src] = 0 ;
        while (!st.empty())
        {
            int top = st.top() ; 
            st.pop() ; 
            // only process (perform relaxation) on the nodes whose distance is not INT_MAX
            if (distance[top] != INT_MAX)
            {
                // fetch neighbours 
                for (auto nbr : adj[top])
                {
                    // perform RELAXATION
                    // if distanceOfTop + edgeWeightOfTop,Nbr < distanceOfNbr then UPDATE
                    if (distance[top] + nbr.second < distance[nbr.first])
                    {
                        distance[nbr.first] = distance[top] + nbr.second ; 
                    }
                }
            }
        }
        
        for (int i = 0 ; i < N ; i ++)
        {
            if (distance[i] == INT_MAX)
            {
                distance[i] = -1 ; 
            }
        }
        
        return distance ;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends