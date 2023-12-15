//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int mod = 1000000007 ; 
	    int solve(int start, int end, vector<int> &dp)
	    {
	        if (start == end)
	        {
	            return 1 ; 
	        }
	        
	        if (start > end)
	        {
	            return 0 ;
	        }
	        
	        if (dp[start] != -1)
	        {
	            return dp[start] ; 
	        }
	        
	        dp[start] = (solve(start + 1, end, dp) % mod + solve(start + 2, end, dp) % mod) % mod ; 
	        return dp[start] ; 
	    }
	    
		int nthPoint(int n){
		    // Code here
		    vector<int> dp(n + 1, -1) ; 
		    return solve(0, n, dp) ; 
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends