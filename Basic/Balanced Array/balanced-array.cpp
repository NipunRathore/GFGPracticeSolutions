//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int minValueToBalance(int a[], int n)
    {
       //code here.
        long sum1 = 0 ;
        long sum2 = 0 ;
        int n1 = n / 2 ;
        
        for(int i = 0 ; i < n1 ; i ++)
        {
            sum1 = sum1 + a[i] ;
        }
        for(int i = n1 ; i < n ; i ++)
        {
            sum2 = sum2 + a[i] ;
        }
        int maxi = max(sum1, sum2) ;
        int mini = min(sum1,sum2) ;
        long value = maxi - mini ;
        return value ;
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
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.minValueToBalance(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends