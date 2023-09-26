//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        stack<int> st ; 
        // initialize by inserting -1
        st.push(-1) ; 
        
        int maxLen = 0 ; 
        
        for (int i = 0 ; i < s.length() ; i ++)
        {
            char ch = s[i] ; 
            
            // if opening bracket push "index"
            if (ch == '(')
            {
                st.push(i) ; 
            }
            
            else
            {
                // if closing 
                // pop 
                st.pop() ; 
                
                // if stack empty (-1 popped) push "index"
                if (st.empty())
                {
                    st.push(i) ; 
                }
                
                // if stack not empty 
                else
                {
                    // find len & update maxLen 
                    int len = i - st.top() ; 
                    maxLen = max(len, maxLen) ;
                }
            }
        }
        return maxLen ; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends