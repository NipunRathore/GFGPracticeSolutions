//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++
class Solution
{
    private:
    void solve(string &str, int start, int end)
    {
        // base case 
        if (start >= end)
        {
            return ; 
        }
        
        // processing
        swap(str[start], str[end]) ; 
        start ++ ; 
        end -- ; 
        
        // recursion
        solve(str, start, end) ; 
    }
    public:
    string reverseWord(string str)
    {
        // Your code goes here
        // SOLUTION - 1
        // reverse(str.begin(), str.end()) ;
        // return str ; 
        
        // SOLUTION - 2
        // int start = 0 ;
        // int end = str.length() - 1 ; 
        
        // while (start < end)
        // {
        //     swap(str[start], str[end]) ;
        //     start ++ ; 
        //     end -- ;
        // }
        // return str ;
        
        // SOLUTION - 3
        int start = 0 ; 
        int end = str.length() - 1 ; 
        solve(str, start, end) ; 
        return str ;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends