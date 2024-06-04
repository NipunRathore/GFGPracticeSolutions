//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here
        char ch = 'A' ;
        
        for(int i = 1 ; i <= n ; i ++)
        {
            for(int j = 1 ; j <= i ; j ++)
            {
                cout << ch ;
            }
            cout << endl ;
            ch = ch + 1 ;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends