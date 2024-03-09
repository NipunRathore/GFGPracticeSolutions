//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        string ans = s ; 
        
        for (int i = 0 ; i < r ; i ++)
        {
            string result = "" ; 
            for (int j = 0 ; j <= n ; j ++)
            {
                if (ans[j] == '0')
                {
                    result += "01" ; 
                }
                else 
                {
                    result += "10" ; 
                }
            }
            ans = result ; 
        }
        return ans[n] ; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends