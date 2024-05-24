//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int sumOfTheSeries(long long int n){
        // code here
        long long int num = 0 ;
        long long int sum = 0 ;
        for(int i = 1 ; i <= n ; i ++)
        {
            num = num + i ;
            sum = sum + num ;
        }
        return sum ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.sumOfTheSeries(n) << endl;
    }
    return 0;
}

// } Driver Code Ends