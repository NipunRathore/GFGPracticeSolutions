//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        // weighted graph so adjacency list of type 
    unordered_map<int, list<pair<int,int> > > adj ; 
    
    for (int i = 0 ; i < edges.size() ; i ++)
    {
        int u = edges[i][0] ; 
        int v = edges[i][1] ; 
        // int w = vec[i][2] ; 
        int w = 1 ; 

        // pair<int,int> p = make_pair(v, w) ; 
        // undirected graph u, v = v, u
        adj[u].push_back(make_pair(v, w)) ; 
        adj[v].push_back(make_pair(u, w)) ; 
    }

    // creation of distance array initially infinity
    vector<int> distance(N, INT_MAX) ; 
    
    // creating set (distance, node)
    set<pair<int,int> > st ; 

    // initializing both data structures with source 
    distance[src] = 0 ; 
    st.insert(make_pair(0, src)) ; 
    

    while (!st.empty())
    {
        // fetch top node 
        // this is a set not a stack
        // auto top = st.top() ; 
        // sets dont have functions to directly access the first elements 
        // you have to return an iterator to begin and then dereference it
        auto top = *(st.begin()) ;  
        int nodeDistance = top.first ; 
        int topNode = top.second ; 

        // remove top node 
        st.erase(st.begin()) ; 

        for (auto neighbour : adj[topNode])
        {
            if (nodeDistance + neighbour.second < distance[neighbour.first])
            {
                // checking if any record present for this neighbour node in the set
                // if present then delete it 
                auto record = st.find(make_pair(distance[neighbour.first], neighbour.first)) ;
                // if record present then delete it 
                if (record != st.end())
                {
                    st.erase(record) ; 
                }
                // update distance 
                distance[neighbour.first] = nodeDistance + neighbour.second ; 

                // push record in set
                st.insert(make_pair(distance[neighbour.first], neighbour.first)) ;
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends