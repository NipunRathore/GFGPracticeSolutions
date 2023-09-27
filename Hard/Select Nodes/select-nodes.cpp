//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

// lighting up leaf nodes will not give the -> minimum answer
// we get minimum answer by lighting up the parent of leafs so that all nodes below 
// it and all nodes above it can get lit up 
class Solution{
  public:
    bool dfsUtil (int node, int &cnt, unordered_map<int, list<int> >& adj
                , unordered_map<int, bool> &visited)
    {
        visited[node] = true ; 
        bool select = false ;
        
        for (auto nbr : adj[node])
        {
            if (!visited[nbr])
            {
                // make dfs call for nbr/child
                bool isChildSelected = dfsUtil (nbr, cnt, adj, visited) ;
                
                // if child not selected then select the parent 
                if (!isChildSelected)
                {
                    select = true ; 
                }
            }
        }
        
        // increment cnt if current node is selected
        if (select)
        {
            cnt ++ ; 
        }
        
        return select ;
    }
    int countVertex(int N, vector<vector<int>>edges){
        // code here
        unordered_map<int, list<int> > adj ; 
        
        for (int i = 0 ; i < edges.size() ; i ++)
        {
            int u = edges[i][0] ; 
            int v = edges[i][1] ; 
            
            adj[u].push_back(v) ; 
            adj[v].push_back(u) ;
        }
        int cnt = 0 ; 
        unordered_map<int, bool> visited ; 
        dfsUtil(1, cnt, adj, visited) ; 
        
        return cnt ; 
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends