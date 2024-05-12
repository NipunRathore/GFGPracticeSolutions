//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minSteps(int d) {
        // code here
        int cnt = 0 ;
        long sum = 0 ;
        
        while(sum < d || (sum - d) % 2 != 0)
        {
            cnt ++ ;
            sum += cnt ;
        }
        return cnt ;
    }
};\

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;

        Solution ob;
        cout << ob.minSteps(d) << "\n";
    }
    return 0;
}
// } Driver Code Ends