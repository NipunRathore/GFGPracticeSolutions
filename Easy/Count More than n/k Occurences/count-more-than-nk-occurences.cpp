//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        // Your code here
        unordered_map<int, int> m ; 
        
        for (int i = 0 ; i < n ; i ++)
        {
            m[arr[i]] ++ ; 
        }
        
        int cnt = 0 ; 
        
        for (int i = 0 ; i < n ; i ++)
        {
            if (m[arr[i]] > (n / k))
            {
                cnt ++ ; 
                // if same number appears again in the array later on 
                // or use a range based for loop instead
                m[arr[i]] = 0 ;
            }
        }
        return cnt ; 
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends