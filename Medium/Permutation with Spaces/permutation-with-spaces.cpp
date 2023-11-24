//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    
    void solve (int index, string &S, string output, vector<string> &ans)
    {
        if (index >= S.length())
        {
            ans.push_back(output) ;
            return ; 
        }
        
        // for 1st char we have to include it straightaway 
        // no permutation contains space as the first char
        if (index == 0)
        {
            solve(index + 1, S, output + S[index], ans) ; 
        }
        else
        {   
            // include space 
            solve(index + 1, S, output + ' ' + S[index], ans) ;
            // exclude space 
            solve(index + 1, S, output + S[index], ans) ; 
        }
    }

    vector<string> permutation(string S){
        // Code Here
        vector<string> ans ; 
        string output = "" ;
        int index = 0 ; 
        solve (index, S, output, ans) ;
        
        sort(ans.begin(), ans.end()) ;
        return ans ;
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends