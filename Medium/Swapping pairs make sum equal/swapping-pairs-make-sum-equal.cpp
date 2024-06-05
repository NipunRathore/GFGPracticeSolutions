//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here.
        sort(a, a + n) ;
        sort(b, b + m) ;
        
        int sumA = 0 ;
        int sumB = 0 ;
        
        for(int i = 0 ; i < n ; i ++)
        {
            sumA += a[i] ;
        }
        
        for(int i = 0 ; i < m ; i ++)
        {
            sumB += b[i] ;
        }
        
        if (abs(sumA - sumB) % 2)
        {
            return -1 ;
        }
        
        int x = (sumA - sumB) / 2 ;
        
        int i = 0 ;
        int j = 0 ;
        
        while(i < n && j < m) 
        {
            if(a[i] == b[j] + x) 
            {
                return 1 ;
            }
            
            if(a[i] > b[j] + x) 
            {
                j ++ ;
            } 
            else
            {
                i ++ ;
            }
        }
        
        return -1 ;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends