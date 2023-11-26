//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int NthTermOfSeries(int N)
    {
        // Write Your Code here
        queue <string> q ;
        q.push("") ;
        
        while(N --)
        {
            string s = q.front() ;
            q.pop() ;
            q.push(s + "4") ;
            q.push(s + "7") ;
        }
        return stoi(q.front()) ;   
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        int ans  = ob.NthTermOfSeries(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends