//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
// we want height of second building to be as maximum as possible 
// and height of first building to be as small as possible 
	bool recreationalSpot(int arr[], int n){
		// Your code goes here 
		if (n < 3)
		{
		    return false ; 
		}
		
		int maxi = arr[1] ; 
		int mini = arr[0] ; 
		
		for (int i = 2 ; i < n ; i ++)
		{
		  //  if found 
		    if (arr[i] < maxi && arr[i] > mini)
		    {
		        return true ;
		    }
		    
		  //  update maxi 
		    maxi = max(arr[i], maxi) ; 
		    
		  //  update mini
		    if (arr[i - 1] != maxi)
		    {
		        mini = min(mini, arr[i - 1]) ; 
		    }
		}
		return false ; 
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
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution ob;
		if(ob.recreationalSpot(arr, n))
		    cout<<"True"<<endl;
		else
		    cout<<"False"<<endl;
	}
	return 0;
}
// } Driver Code Ends