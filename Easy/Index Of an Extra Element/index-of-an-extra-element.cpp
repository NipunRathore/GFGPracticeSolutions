//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    int findExtra(int a[], int b[], int n) {
        // add code here.
        map<int, int> mp ;
        int n1 = 0, n2 = 0 ;
        
        for(int i = 0 ; i < n ; i ++)
        {
            mp[a[i]] ++ ;
            n1 ++ ;
        }
        
        for(int i = 0 ; i < n - 1 ; i ++)
        {
            mp[b[i]] ++ ;
            n2 ++ ;
        }
        
        for(int i = 0 ; i < n ; i ++)
        {
            if(mp[a[i]] == 1)
            {
                return i ;
            }
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
        int a[n], b[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> b[i];
        }
        Solution obj;
        cout << obj.findExtra(a, b, n) << endl;
    }
}
// } Driver Code Ends