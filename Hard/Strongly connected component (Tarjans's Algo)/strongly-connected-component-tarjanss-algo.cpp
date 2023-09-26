//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

// solved using Kosaraju's Algorithm
class Solution
{
	public:
void dfsTopoSortUtil (int node, stack<int>& st, unordered_map<int, bool>& visited, 
                        vector<int> adj[])
{
    visited[node] = true ; 

    for (auto nbr : adj[node])
    {
        if(!visited[nbr])
        {
            dfsTopoSortUtil(nbr, st, visited, adj) ; 
        }
    }
    st.push(node) ; 
}

void dfsUtil (int node, unordered_map<int, bool>& visited, unordered_map<int, list<int>> &adj, 
                vector<int>& output)
{
    visited[node] = true ; 
    output.push_back(node) ; 
    
    for (auto nbr : adj[node])
    {
        if(!visited[nbr])
        {
            dfsUtil(nbr, visited, adj, output) ; 
        }
    }
}
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code here
        stack<int> st ;
        unordered_map<int, bool> visited ; 
    
        for (int i = 0 ; i < V ; i ++)
        {
            if (!visited[i])
            {
                dfsTopoSortUtil (i, st, visited, adj) ; 
            }
        }
    
        unordered_map<int, list<int>> transposeAdj ; 
        for (int i = 0 ; i < V ; i ++)
        {
            visited[i] = false ;
            
            for (auto nbr : adj[i])
            {
                transposeAdj[nbr].push_back(i) ; 
            }
        }
    
        vector<vector<int>> result ; 
        while (!st.empty())
        {
            int top = st.top() ; 
            st.pop() ; 
            
            if (!visited[top])
            {
                vector<int> output ;
                
                dfsUtil(top, visited, transposeAdj, output) ; 
                
                sort(output.begin(), output.end()) ; 
                result.push_back(output) ;  
            }
        }
        
        sort(result.begin(), result.end()) ; 
        return result ; 
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends