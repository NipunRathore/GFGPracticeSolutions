//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int solve(int N, vector<int> p){
        // code here
        vector<int> cntConnections (N, 0) ; 
        
        for (int i = 0 ; i < N ; i ++)
        {
            if (p[i] != -1)
            {
                cntConnections[i] ++ ; 
                cntConnections[p[i]] ++ ;
            }
        }
        
        int internalNodes = 0 ; 
        
        for (int i = 0 ; i < N ; i ++)
        {
            if (cntConnections[i] >= 2)
            {
                internalNodes ++ ; 
            }
        }
        
        if (internalNodes == 0)
        {
            return 0 ; 
        }
        
        return internalNodes - 1 ; 
        
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends