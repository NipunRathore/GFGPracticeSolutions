//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        int n = s.length() ; 
        int sum = 0 ;
        for (int i = 0 ; i < n ; i ++)
        {
            sum = ((sum * 10) % 8 + s[i] - '0') % 8 ; 
        }
        
        if (sum % 8 == 0)
        {
            return 1 ; 
        }
        return -1 ; 
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends