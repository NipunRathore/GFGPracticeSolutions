//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long height[], int len)
{
    // Your code goes here
    int n = len ;  
    int start = 0 ; 
    int end = n - 1 ; 
    long long maxWater = 0 ; 
    
    // Two-Pointer Approach 
    while (start < end)
    {
        // at each position check the area of rectangle formed & update answer 
        // Horizaontal Length 
        int currWidth = end - start ; 
        // Vertical Length -> minimum of 2 vertical lines because water above that point is overflown 
        long long currHeight = min (height[start], height[end]) ; 
        // Area = Horizontal & Vertical Length
        long long  currWater = currWidth * currHeight ; 
        // update the maximum area if possible 
        maxWater = max(maxWater, currWater) ; 
        
        // Greedy Approach -> try to maximize the height of Vertical line to get Max area 
        // move such that one having greater value stays still & other pointer moves 
        if (height[start] > height[end])
        {
            end -- ; 
        }
        else
        {
            start ++ ; 
        }
    }
    return maxWater ;
}
// T.C. = O(N)
// S.C. = O(1)

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends