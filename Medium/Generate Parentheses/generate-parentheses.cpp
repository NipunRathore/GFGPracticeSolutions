//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void solve(string output, int open, int close, vector<string> &ans)
    {
        // BASE CASE 
        // when both count become 0, store the current combination of parentheses
        if (open == 0 && close == 0)
        {
            ans.push_back(output) ;
            return ;
        }
    
        // count of opening parentheses equal to closing,
        // then use opening becuase all brackets so far have been balanced 
        // and new sequence cannot start with closing 
        if (open == close)
        {
            string temp = output ; 
            temp.push_back('(') ; 
            solve(temp, open - 1, close, ans) ; 
        }
    
        // when count of opening is 0, use closing 
        else if (open == 0)
        {
            string temp = output ; 
            temp.push_back(')') ; 
            solve(temp, open, close - 1, ans) ; 
        }
    
        // when count of closing is 0, use opening
        else if (close == 0)
        {
            string temp = output ; 
            temp.push_back('(') ; 
            solve(temp, open - 1, close, ans) ; 
        }
    
        // for remaining cases we have both choices 
        else
        {
            string temp1 = output ; 
            string temp2 = output ;
            temp1.push_back('(') ; 
            temp2.push_back(')') ;
            solve(temp1, open - 1, close, ans) ; 
            solve(temp2, open, close - 1, ans) ; 
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        int open = n ;
        int close = n ; 
        vector<string> ans ; 
        string output = "" ; 
        solve(output, open, close, ans) ; 
        return ans ;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends