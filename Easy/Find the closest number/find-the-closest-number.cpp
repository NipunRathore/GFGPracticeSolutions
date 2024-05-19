//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int a[]) 
    {
        // Complete the function.
        int diff = INT_MAX, result ;
        for(int i = 0 ; i < n ; i ++)
        {
            if(abs(a[i] - k) <= diff)
            {
                diff = abs(a[i] - k) ;
                result = a[i] ;
            }
        }
        return result ;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends