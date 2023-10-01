//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
void dfsTarjanUtil (int node, int parent, vector<int>& discovery, vector<int>& lowest, unordered_map<int, bool>& visited,
vector<int> adj[], set<int>& ans, int& timer)
{
    // mark visited
    visited[node] = true ; 
    // assign current timer as low and discovery time of ndoe 
    discovery[node] = timer ;
    lowest[node] = timer ; 
    // increment timer 
    timer ++ ;
    
    // to maintain child count needed for the separate handling of starting node 
    int child = 0 ; 
    // fetch nbr from adj 
    for (auto nbr : adj[node])
    {
        // if nbr is parent then ignore 
        if (nbr == parent)
        {
            continue ;
        }
        
        // if nbr is not visited & not parent 
        // then make dfs call with node = nbr & parent = node 
        if (!visited[nbr])
        {
            dfsTarjanUtil(nbr, node, discovery, lowest, visited, adj, ans, timer) ; 
            
            // while returning 
            // 1 -> update low of node 
            // 2 -> check if node is an articulation point 
            
            // when returning update low time of node as in case child node creates a back edge and it's low time gets updated
            // when low of child updated, we have another way to reach current node through its child node 
            // so need to update low of node
            lowest[node] = min (lowest[node], lowest[nbr]) ; 
            // check articulation point or not 
            if (lowest[nbr] >= discovery[node] && parent != -1)
            {
                ans.insert(node) ; 
            }
            // maintain child count 
            // child -> not all neighbours from adj 
            // only the unvisited neighbours for whom dfs call made
            child ++ ; 
        }
        else{
            // if visited & not parent 
            // back edge -> reaching a visited node / nbr already visited
            // therefore, there exists another path to reach the node
            // so need to update low time 
            lowest[node] = min(lowest[node], discovery[nbr]) ; 
        }
    }
    // separatelyy handle the case of starting node i.e., the node with parent = - 1
    if (parent == -1 && child > 1)
    {
        ans.insert(node) ; 
    }
}
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        // variables needed {timer, parent}
        // data structures needed {discovery, lowest, visited}
        int timer = 0 ;
        
        // Discovery -> store the time at which you reach a node
        vector<int> discovery (V, -1) ; 
        // Low -> earliest possible time to reach a node 
        vector<int> lowest(V, -1) ; 
        // visited -> to track nodes that have been visited
        unordered_map<int, bool> visited ;
        // DFS based algorithm so no need of entire data structure to track parent, just maintain a variable 
        int parent = -1 ; 
        
        // need answers in sorted order therefore use set
        set<int> ans ; 
        for (int i = 0 ; i < V ; i ++)
        {
            if (!visited[i])
            {
                dfsTarjanUtil (i, parent, discovery, lowest, visited, adj, ans, timer) ; 
            }
        }
        
        if (ans.size() == 0)
        {
            return {-1} ; 
        }
        vector<int> result ; 
        for (auto i : ans)
        {
            result.push_back(i) ; 
        }
        return result ; 
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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends