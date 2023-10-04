//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        
        // store mapping of roman to integer
        unordered_map <char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
                                       {'C', 100}, {'D', 500}, {'M', 1000}} ;
        
        int result = 0 ; 

        for (int i = 0 ; i < str.length() ; i++)
        {
            // eg -: IV then subtract I 
            if (m[str[i]] < m[str[i+1]])
            {
                result -= m[str[i]] ;
            }

            // else add
            else 
            {
                result += m[str[i]] ;
            }
        }
        return result ; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends