//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int> arr, int N, int k)
    {
        // code here
        int index = 0 ; 
        
        for (int i = 0 ; i < N ; i ++)
        {
            if (arr[i] == k)
            {
                return i ;
            }
            
            else
            {
                if (arr[i] < k)
                {
                    
                    index = i + 1 ; 
                }
            }
        }
        return index ; 
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends