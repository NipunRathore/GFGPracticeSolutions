//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	void solve(vector<string> &ans, string temp, string s, int index)
	{
	    if (index >= s.length())
	    {
	        if (temp.length() > 0)
	            ans.push_back(temp) ;
	        return ;
	    }
	    
	    solve(ans, temp, s, index + 1) ;
	    
	    temp.push_back(s[index]) ;
	    index ++ ; 
	    solve(ans, temp, s, index) ;
	}
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans ; 
		    string temp = "" ;
		    
		    solve(ans, temp, s, 0) ;
		    
		    sort(ans.begin(), ans.end()) ;
		    return ans ;
		}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends