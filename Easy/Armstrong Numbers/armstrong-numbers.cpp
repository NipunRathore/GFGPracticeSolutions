//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n) {
        // code here
        if (n < 100 || n >= 1000) 
        {
            return "false" ;
        }
        
        int hundreds = n / 100 ;
        int tens = (n / 10) % 10 ;
        int units = n % 10 ;
        int sum_of_cubes = pow(hundreds, 3) + pow(tens, 3) + pow(units, 3) ;
        
        if (sum_of_cubes == n)
        {
              return "true" ;
        }

        return "false" ;
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
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends