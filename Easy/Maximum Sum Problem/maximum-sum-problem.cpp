//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int maxSum(int n)
        {
            // code here.
            if (n <= 0)
            {
                return 0 ;
            }
            
            int ans1 = maxSum(n / 2) ;
            int ans2 = maxSum(n / 3) ;
            int ans3 = maxSum(n / 4) ;
            
            return max(n, ans1 + ans2 + ans3) ;
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
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends