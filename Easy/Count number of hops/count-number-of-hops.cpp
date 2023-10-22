//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

long long mod = 1000000007 ;
class Solution
{
    public:
    long long solve(int n, vector<long long> &dp)
    {
        if (n == 0)
        {
            dp[n] = 1 ;
            return dp[n] ; 
        }
        
        if (n < 0)
        {
            return 0 ; 
        }
        
        if (dp[n] != -1)
        {
            return dp[n] ; 
        }
        
        dp[n] = (solve(n - 1, dp) + solve(n - 2, dp) + solve(n - 3, dp)) % mod ;
        return dp[n] ; 
    }
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        // your code here
        vector<long long> dp (n + 1, -1) ; 
        long long ans = solve(n, dp) ; 
        return ans ;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends