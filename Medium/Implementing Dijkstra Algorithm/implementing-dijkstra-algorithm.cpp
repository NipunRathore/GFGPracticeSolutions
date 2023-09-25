//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> distance (V, INT_MAX) ; 
        
        // pq to find the minimum distance node 
        // stores pairs (distance, node) so that sorted based on distance
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq ; 
        
        // initialise the data structures with source
        distance[S] = 0 ; 
        pq.push(make_pair(0, S)) ; 
        
        while (!pq.empty())
        {
            auto top = pq.top() ; 
            pq.pop() ;
            
            int topNode = top.second ; 
            int nodeDist = top.first ; 
            
            for (auto nbr : adj[topNode])
            {
                // here adj is vector<vector<int> > and not unordered_map<int, list<pair<int, int> > > 
                // nbr is a vector itself 
                int adjNode = nbr[0] ; 
                int edgeWeight = nbr[1] ; 
                // perform relaxation 
                if (nodeDist + edgeWeight < distance[adjNode])
                {
                    // update distance of nbr node
                    distance[adjNode] = nodeDist + edgeWeight ; 
                    
                    // store record for the newly updated distance, node in the priority queue
                    pq.push({distance[adjNode], adjNode}) ;
                }
            }
        }
        return distance ; 
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends