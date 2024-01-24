//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
    void dfs(int src, vector<int> adj[], vector<bool> &vis)
    {
        vis[src] = true ; 
        for (auto nbr : adj[src])
        {
            if (vis[nbr] == false)
            {
                dfs(nbr, adj, vis) ; 
            }
        }
    }
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        // number of vertcies should be equal to number of nodes - 1
        if ((n - m) != 1)
        {
            return 0 ; 
        }
        
        vector<bool> visited(n, false) ; 
        vector<int> adj1 [n] ;
        for (auto it : adj)
        {
            adj1[it[0]].push_back(it[1]) ; 
            adj1[it[1]].push_back(it[0]) ;
        }
        dfs(0, adj1, visited) ; 
        
        for (auto it : visited)
        {
            if (it == 0)
            {
                return 0 ; 
            }
        }
        return 1 ; 
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends