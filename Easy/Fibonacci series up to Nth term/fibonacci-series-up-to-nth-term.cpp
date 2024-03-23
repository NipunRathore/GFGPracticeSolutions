//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Series(int n) {
        // Code here
        vector<int> ans ;
        int a = 0 ; 
        int b = 1 ; 
        
        ans.push_back(a) ;
        ans.push_back(b) ;
        
        for (int i = 2 ; i <= n ; i ++)
        {
            int c = (a + b) % 1000000007 ;
            a = b % 1000000007 ; 
            b = c % 1000000007 ; 
            
            ans.push_back(b) ;
        }
        
        return ans ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends