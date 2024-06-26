//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> duplicates(vector<long long> arr) {
        // code here
        int n = arr.size() ; 
        unordered_map<int,int> m ; 
        for (int i = 0 ; i < n ; i ++)
        {
            m[arr[i]] ++ ; 
        }
        vector<int> v ;
        bool flag = 0 ; 
        for (auto i : m)
        {
            if (i.second > 1)
            {
                v.push_back(i.first) ;
                flag = 1 ; 
            }
        }
        sort(v.begin(), v.end()) ; 
        if (!flag)
        {
            return {-1} ; 
        }
        else return v ; 
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        vector<int> ans = obj.duplicates(arr);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends