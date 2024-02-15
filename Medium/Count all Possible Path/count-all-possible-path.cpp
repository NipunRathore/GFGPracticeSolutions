//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int isPossible(vector<vector<int>>paths){
	    // Code here
	    // each node should have even degree
	    for (int i = 0 ; i < paths.size() ; i ++)
	    {
	        // check degree of eah vertex
	        int degree = 0 ; 
	        
	        for (int j = 0 ; j < paths[i].size() ; j ++)
	        {
	            degree += paths[i][j] ;
	        }
	        
	        if (degree % 2 != 0)
	        {
	            // if any vertex has an odd degree
	            return 0 ; 
	        }
	    }
	    return 1 ; 
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>paths(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> paths[i][j];
		}
		Solution obj;
		int ans = obj.isPossible(paths);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends