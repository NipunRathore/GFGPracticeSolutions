//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findExtra(int n, int a[], int b[]) {
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
        int arr1[n], arr2[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> arr2[i];
        }
        Solution obj;
        cout << obj.findExtra(n, arr1, arr2) << endl;
    }
}
// } Driver Code Ends