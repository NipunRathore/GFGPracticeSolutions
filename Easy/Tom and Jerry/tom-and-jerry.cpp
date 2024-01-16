//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int numsGame(int N) {
        // code here
        return N % 2 == 0 ; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.numsGame(N) << endl;
    }
    return 0;
}
// } Driver Code Ends