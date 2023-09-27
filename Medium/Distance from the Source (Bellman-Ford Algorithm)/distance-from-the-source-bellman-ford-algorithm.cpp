//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        // size of array = n as nodes from 0 to n - 1 and not 1 to n 
	    vector<int> distance(V, 1e8) ;
	    // initialise distance of source 0
	    distance[S] = 0 ; 
	    
	    // STEP 1 : apply Relaxation/Distance Minimization formula on all edges n - 1 times
	    //outer loop -> V - 1 
	    for (int i = 0 ; i < V ; i ++)
	    {
	        // inner loop for edges
	        for (int j = 0 ; j < edges.size() ; j ++)
	        {
	            // no need of adjacency list as u, v -> wt can directly be accessed from edges array
	            int u = edges[j][0] ;
	            int v = edges[j][1] ;
	            int wt = edges[j][2] ;

                // if ditance of node is equal to maximum value then relaxation formula wont work
	            if (distance[u] != 1e8)
	            {
	                // perform RELAXATION / DISTANCE MINIMIZATION
	                if (distance[u] + wt < distance[v])
	                {
	                    distance[v] = distance[u] + wt ; 
	                }
	            }
	        }
	    }
	    
    	// STEP 2 : apply the formula on all edges 1 more time 
    	//if any updation occurs then cycle is present 
        for (int j = 0 ; j < edges.size() ; j ++)
        {
            int u = edges[j][0] ;
            int v = edges[j][1] ;
            int wt = edges[j][2] ;
    
            // check if relaxation condition true then cycle is present
            if (distance[u] + wt < distance[v])
            {
                return {-1} ; 
            }
        }
        
        // if no updation occurs then cycle absent and SHORTEST PATH FOUND ARE CORRECT
        return distance ; 
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
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

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends