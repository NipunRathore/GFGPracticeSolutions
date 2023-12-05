//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    // sumular to Permutations
    void solve(vector<vector<string> > &list, vector<vector<string> >&ans, int index, vector<string> output)
    {
        if (index == list.size())
        {
            ans.push_back(output) ;
            return ;
        }
        
        
        for (auto it : list[index])
        {
            output.push_back(it) ; 
            solve(list, ans, index + 1, output) ; 
            // BACKTRACKING
            output.pop_back() ;
        }
    }
    
    vector<vector<string>> sentences(vector<vector<string>>&list){
        //Write your code here
        vector<vector<string> > ans ; 
        vector<string> output ; 
        int index = 0 ; 
        solve(list, ans, index, output) ;
        
        return ans ; 
    }
};


//{ Driver Code Starts.
int main()
{
	int t = 1;
	//cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<vector<string>>list(m, vector<string>(n));
	    for(int i = 0 ; i < m; i++){
	        for(int j = 0; j < n; j++){
	            cin >> list[i][j];
	        }
	    }
	    Solution ob;
	    vector<vector<string>>ans = ob.sentences(list);
	    for(auto it : ans){
	        for(auto it1 : it){
	            cout << it1 << " ";
	        }
	        cout << endl;
	    }
	}
	return 0;
}

// } Driver Code Ends