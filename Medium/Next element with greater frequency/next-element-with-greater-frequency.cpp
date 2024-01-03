//{ Driver Code Starts
#include <bits/stdc++.h>
#define N 10000
using namespace std;


// } Driver Code Ends
class Solution{
public:
    vector<int> print_next_greater_freq(int arr[],int n)
    {
        // code here
        stack<int> st ; 
        st.push(-1) ; 
        
        unordered_map<int, int> mp ;
        for (int i = 0 ; i < n ; i ++)
        {
            mp[arr[i]] ++ ; 
        }
        
        vector<int> ans (n) ; 
        
        for (int i = n - 1 ; i >= 0 ; i --)
        {
            int curr = mp[arr[i]] ;
            
            while (curr >= mp[st.top()] && st.top() != -1)
            {
                st.pop() ; 
            }
            
            ans[i] = st.top() ; 
            st.push(arr[i]) ; 
        }
        return ans ; 
    }
};


//{ Driver Code Starts.

int main()
{
    int arr[N];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans=ob.print_next_greater_freq(arr,n);
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout << endl;
    }
	return 1;
}

// } Driver Code Ends