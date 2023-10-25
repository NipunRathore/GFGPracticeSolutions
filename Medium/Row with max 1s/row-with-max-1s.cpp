//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    
	   // create a vector of size equal to number of rows and store the one counts of all rows 
	    vector<int> oneRowCnt ; 
	    for (auto i : arr)
	    {
	        int cnt = 0 ; 
	        for (auto j : i)
	        {
	            if (j == 1)
	            {
	                cnt ++ ; 
	            }
	        }
	        oneRowCnt.push_back(cnt) ; 
	    }
	    
	   // find the row with maximum ones from the oneRowCnt array 
	    int maxRow = 0 ; 
	    int maxi = INT_MIN ; 
	    for (int i = 0 ; i < oneRowCnt.size() ; i ++)
	    {
	        
	        if (maxi < oneRowCnt[i])
	        {
	            maxi = oneRowCnt[i] ; 
	            maxRow = i ; 
	        }
	    }
	    if (maxi == 0)
	    {
	        return -1 ;
	    }
	    return maxRow ;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends