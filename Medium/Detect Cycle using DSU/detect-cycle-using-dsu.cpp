//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
bool isCyclicDFS(int src, int parent, unordered_map<int, bool> &visited
                ,vector<int> adj[])
{
    visited[src] = true ; 

    for (auto nbr : adj[src])
    {
        if (!visited[nbr])
        {
            bool ans = isCyclicDFS(nbr, src, visited, adj) ; 

            if (ans == true)
            {
                return true ;
            }
        }
        else
        {
            if (nbr != parent)
            {
                return true ; 
            }
        }
    }
    return false ;
}
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
        unordered_map<int, bool> visited ; 
    
        for (int i = 0 ; i < V ; i ++)
        {
            if (!visited[i])
            {
                // bool ans = isCyclicBFS(i, adj, visited) ; 
                bool ans = isCyclicDFS(i, -1, visited, adj) ;
                
                if (ans == true)
                {
                    return 1 ; 
                }
            }
        }
        return 0 ;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends