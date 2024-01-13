//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int minManipulation (int n, string s1, string s2);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << minManipulation (n, s1, s2) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minManipulation (int N, string s, string t)
{
    // your code here
    // storing difference of frequencies of characters in 's' & 't' 
    vector<int> arr (26, 0) ; 
    for (auto ch : s)
    {
        // increment frequencies for string 's'
        arr[ch - 'a'] ++ ;
    }
    for (auto ch : t)
    {
        // decrement frequencies for string 't' 
        arr[ch - 'a'] -- ; 
    }

    int ans = 0 ; 
    for (auto i : arr)
    {
        // adding the difference stored where 't' has more instances than 's' 
        if (i > 0)
        {
            ans += i ; 
        }
    }

    return ans ; 
}