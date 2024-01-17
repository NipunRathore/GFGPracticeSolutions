//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  void solve(vector<int> &arr, set<vector<int> >& ans, int index)
  {
      if (index >= arr.size())
      {
          ans.insert(arr) ; 
          return ; 
      }
      
      
      for (int i = index; i < arr.size() ; i ++)
      {
          swap(arr[i], arr[index]) ; 
          solve(arr, ans, index + 1) ; 
          
          swap(arr[i], arr[index]) ; 
      }
  }
  
    vector<vector<int>> uniquePerms(vector<int> arr ,int n) {
        // code here
        set<vector<int> >ans ; 
        vector<vector<int> > v ; 
        int index = 0 ; 
        
        solve(arr, ans, index) ; 
        
        for (auto i : ans)
        {
            v.push_back(i) ; 
        }
        return v ; 
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends