//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    bool containsDigitFour(int num)
    {
        string str = to_string(num) ;
        return str.find('4') != string::npos ;
    }
    int countNumberswith4(int n) {
        // code here
        int count = 0 ;
        for (int i = 1 ; i <= n ; i ++)
        {
            if (containsDigitFour(i))
            {
                count ++ ;
            }
        }
        return count ;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends