//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool isPrime (int n)
{
    if (n == 1 || n == 0)
    {
        return false ; 
    }
    
    for (int i = 2; i <= sqrt(n); i++) 
    {
        if (n % i == 0)
        {
            return false ;
        }
    }
    return true ; 
}
    vector<int> primeDivision(int N){
        // code here
        vector<int> v ; 
        for (int i = 2 ; i < N ; i ++)
        {
            if (isPrime(i))
            {
                v.push_back(i) ;
            }
        }
        
        vector<int> ans ; 
        int start = 0 ;
        int end = v.size() - 1 ; 
        
        while (start <= end)
        {
            int sum = v[start] + v[end] ;
            
            if (sum == N)
            {
                ans.push_back(v[start]) ;
                ans.push_back(v[end]) ;
                
                return ans ; 
            }
            
            else if (sum < N)
            {
                start ++ ; 
            }
            
            else
            {
                end -- ; 
            }
        }
        return ans ; 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}
// } Driver Code Ends