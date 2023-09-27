//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    
	    // size of array = n as nodes from 0 to n - 1 and not 1 to n 
	    vector<int> distance(n, 1e8) ;
	    // take arbitrary source 
	    distance[0] = 0 ; 
	    
	    // STEP 1 : apply Relaxation/Distance Minimization formula on all edges n - 1 times
	    //outer loop -> n - 1 
	    for (int i = 0 ; i < n ; i ++)
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
                return 1 ; 
            }
        }
        
        // if no updation occurs then cycle absent
        return 0 ; 
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends