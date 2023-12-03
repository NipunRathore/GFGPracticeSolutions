//{ Driver Code Starts

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution{
public:
    bool factorSum(int n, int N) 
    {
        // count of divisors
        int count = 0 ;
        
        for(int i = 1 ; i <= sqrt(n) ; i ++)
        {
            // if 'i' is divisor of 'n'
            if(n % i == 0) 
            {
                if (i != n / i)
                {
                    count += 2 ; 
                }
                else
                {
                    count += 1 ; 
                }
            }
        }

        // if number of divisors is 4 then return sum of divisors 
        // else return 0 
        return count == N ? true : false ;
    }
    int count(int A,int B,int N){ 
        // code here
        int cnt = 0 ; 
 
        for (int i = A ; i <= B ; i ++)
        {
            if (factorSum(i, N))
            {
                cnt ++ ; 
            }
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
        int A,B,N;
        cin>>A>>B>>N;
        Solution ob;
        cout << ob.count(A,B,N) << endl;
    }
    return 0; 
}
// } Driver Code Ends