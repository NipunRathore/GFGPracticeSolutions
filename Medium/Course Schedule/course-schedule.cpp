//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        int v = n ;
        unordered_map<int, list<int>> adj ;
        vector<int> inDegree (v, 0) ; 

        // prepare adjacency list 
        for (int i = 0 ; i < prerequisites.size() ; i++)
        {
            int u = prerequisites[i][0] ; 
            int v = prerequisites[i][1] ; 

            //  prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
            // there edge from b to a i.e., v to u 
            adj[v].push_back(u) ; 
        }

        // prepare indegree array, 
        // INDEGREE -> number of edges incident to a vertex
        // for edge from u -> v, indegree of v increases
        // so indegree of neighbour of each vertex has to be increased 
        for (auto i : adj)
        {
            for (auto j : i.second)
            {
                inDegree[j] ++ ;
            }
        }

        // insert vertices of 0 indegree into the queue 
        queue<int> q ; 
        for (int i = 0 ; i < v ; i ++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i) ; 
            }
        }

        // perform bfs
        vector<int> ans ; 

        while (!q.empty())
        {
            // store front node 
            int front = q.front() ; 
            q.pop() ; 

            ans.push_back(front) ; 

            // check neighbours 
            for (auto i : adj[front])
            {
                // on removing vertex front from graph, the indegree of its neighbours reduces by 1 
                inDegree[i] -- ; 
                // if indegree becomes 0, insert into queue 
                if (inDegree[i] == 0){
                    q.push(i) ; 
                }
            }
        }
        // if a valid topological sort -> return ans 
        if (ans.size () == v)
        {
            return ans ; 
        }
        // else return empty vector 
        return {} ; 

        // return ans.size() == n ; 
    }
};


//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends