//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> arrayForm(int a, int b, int c) {
        // code here
        vector<int> arr ; 
        arr.push_back(a) ; 
        arr.push_back(b) ; 
        arr.push_back(c) ; 
        
        return arr ; 
    }

    string stringForm(int a, int b, int c) {
        // code here
        string str = to_string(a) + to_string(b) + to_string(c) ; 
        return str ; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        Solution obj;
        vector<int> res = obj.arrayForm(a, b, c);
        for (auto x : res) cout << x << " ";
        cout << "\n";
        cout << obj.stringForm(a, b, c) << "\n";
    }
    return 0;
}
// } Driver Code Ends