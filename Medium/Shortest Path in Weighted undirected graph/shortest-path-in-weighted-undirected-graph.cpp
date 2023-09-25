//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
//   Similar Logic to Shortest Path in Undirected Graph

// Combination of Dijkstra + shortest path in un-directed graph
// Dijksta also uses BFS therefore, shortest path guaranteed 

// Created Parent Array and utilized it to find the shortest path from src to dest 
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int, list<pair<int, int> > > adj ; 
        for (int i = 0 ; i < m ; i ++)
        {
            int u = edges[i][0] ; 
            int v = edges[i][1] ; 
            int wt = edges[i][2] ; 
            
            adj[u].push_back({v, wt}) ;
            adj[v].push_back({u, wt}) ;
        }
        
        // nodes from 1 to n therefore size = n + 1 
        vector<int> parent (n + 1) ; 
        vector<int> distance (n + 1, INT_MAX) ; 
        
        // pq to find the minimum distance node 
        // stores pairs (distance, node) so that sorted based on distance
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq ; 
        
        // initialise the data structures with source
        int S = 1 ; 
        distance[S] = 0 ; 
        pq.push(make_pair(0, S)) ; 
        parent[S] = -1 ; 
        
        while (!pq.empty())
        {
            auto top = pq.top() ; 
            pq.pop() ;
            
            int topNode = top.second ; 
            int nodeDist = top.first ; 
            
            for (auto nbr : adj[topNode])
            {
                int adjNode = nbr.first ; 
                int edgeWeight = nbr.second ; 
                // perform relaxation 
                if (nodeDist + edgeWeight < distance[adjNode])
                {
                    // update distance of nbr node
                    distance[adjNode] = nodeDist + edgeWeight ; 
                    // assign parent = TopNode
                    parent[adjNode] = topNode ; 
                    // store record for the newly updated distance, node in the priority queue
                    pq.push({distance[adjNode], adjNode}) ;
                }
            }
        }
        if (distance[n] == INT_MAX)
        {
            return {-1} ; 
        }
        
        int currNode = n ; 
        vector<int> ans ; 
        ans.push_back(n) ; 
        
        while (currNode != S)
        {
            currNode = parent[currNode] ; 
            ans.push_back(currNode) ;
        }
        
        reverse(ans.begin(), ans.end()) ; 
        return ans ; 
    }
};

// Dijksta Similar to BFS 
// Visits/updates all neighbours at once 
// also, find top -> pop -> process all neighbours -> repeat

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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