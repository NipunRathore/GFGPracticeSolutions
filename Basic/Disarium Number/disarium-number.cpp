//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isDisarium(int N) {
        // code here
        int cnt = 0 ;
        int num = N ;
        while(num)
        {
            cnt ++ ;
            num /= 10 ;
        }
        int sum = 0 ;
        int num1 = N ;
        while(N)
        {
            int last = N % 10 ;
            sum += pow(last, cnt) ;
            cnt -- ;
            N = N / 10 ;
        }
        if(num1 == sum)
        {
            return 1 ;
        }
        return 0;
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
        cout << ob.isDisarium(N) << endl;
    }
    return 0;
}
// } Driver Code Ends