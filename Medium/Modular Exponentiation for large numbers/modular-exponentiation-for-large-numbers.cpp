//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
#define mod 1000000007
	public:

    long long int powerSolve(long long int a,long long int b, long long int m)
    {
       //Your code here
       if (b == 0)
       {
           return 1 ; 
       }
       
       if (b == 1)
       {
           return a ;
       }
       
       long long ans = powerSolve(a, b / 2, m) ; 
       
       if (b % 2 == 0)
       {
           return (ans * ans) % m ; 
       }
       
       else
       {
           return ((ans * ans) % m * a) % m ; 
       }
    }
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    // Code here
		    return powerSolve(x, n, M) ;
		}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends