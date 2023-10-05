//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        if (s == 0)
        {
            return {-1} ; 
        }
        
        bool flag = true ; 
        int i = 0 ; 
        int j = 0 ; 
        int sum = arr[0] ; 
        
        while (j < n)
        {
            if (sum == s)
            {
                return {i + 1, j + 1} ; 
            }
            
            else if (sum < s)
            {
                j ++ ; 
                if (j < n)
                {
                    sum = sum + arr[j] ; 
                }
            }
            
            else
            {
                sum = sum - arr[i] ; 
                i ++ ; 
            }
        }
        return {-1} ;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends