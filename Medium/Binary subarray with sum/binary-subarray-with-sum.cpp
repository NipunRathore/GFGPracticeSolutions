//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int numberOfSubarrays(vector<int>& nums, int N, int goal){
        // code here
        unordered_map<int, int> mp ; 
        mp[0] = 1 ; 
        int cnt = 0 ; 
        int currSum = 0 ; 

        for (int i = 0 ; i < nums.size() ; i ++)
        {
            currSum += nums[i] ; 

            // if (mp.find(currSum - goal) != mp.end())
            // {
            //     cnt += mp[currSum - goal] ; 
            // }
            cnt += mp[currSum - goal] ;
            mp[currSum] ++ ; 
        }
        return cnt ;
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
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends