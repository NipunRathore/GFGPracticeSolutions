//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        
        // if draw, we need to choose Lexicographically smaller name therefore used Map and not unordered_Map
        map<string, int> vote ; 
        string candName = "" ; 
        int maxi = 0 ;
        
        for (int i = 0 ; i < n ; i ++)
        {
            vote[arr[i]] ++ ; 
        }
        
        for (auto it : vote)
        {
            if (it.second > maxi)
            {
                candName = it.first ; 
                maxi = it.second ; 
            }
        }
        
        return {candName, to_string(maxi)} ; 
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends