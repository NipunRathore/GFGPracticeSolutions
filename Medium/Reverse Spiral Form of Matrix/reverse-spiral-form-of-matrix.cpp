//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&matrix)  {
        // code here
        vector<int> ans ;
        
        int col = matrix[0].size() ;
        int row = matrix.size() ;

        int startingRow = 0 ;
        int endingRow = row - 1 ;
        int startingCol = 0 ;
        int endingCol = col - 1 ; 
        
        int count = 0 ;
        int total = row * col ;
        
        while(count < total)
        {
            for (int i = startingCol ; count < total && i <= endingCol ; i ++)
            {
                ans.push_back(matrix[startingRow][i]) ;
                    count ++ ;
            }
            startingRow ++ ;
            
            for (int i = startingRow ; count < total && i <= endingRow ; i++)
            {
                ans.push_back(matrix[i][endingCol]) ;
                    count++ ;
            }
            endingCol -- ;
            
            for (int i = endingCol ; count < total && i >= startingCol ; i --)
            {
                ans.push_back(matrix[endingRow][i]) ;
                    count ++ ;
            }
            endingRow -- ;
            
            for (int i = endingRow ; count < total && i >= startingRow ; i --)
            {
                ans.push_back(matrix[i][startingCol]) ;
                    count ++ ;
            }
            startingCol ++ ;
        }
        // just reverse the spiral matrix traversal 
        reverse(ans.begin(), ans.end()) ;
        return ans ; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends