//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
// RECURSION -> when a function calls itself directly or indirectly it is called Recursion
// Used when solution to a bigger complex problem depends on smaller problem of same kind 
    long long int factorial(int N){
        //code here
        
        // 2 mandatory components
        // Base Case -> condition to stop recursion
                        // return statement mandatory
                        // solution to the base case is known
        // Recursive Relation/Recurrence Relation -> where the recursive calls are made 
        if (N == 0)
        {
            return 1 ; 
        }
        
        // solution to bigger problem expressed in terms of smaller problems 
        long long int smallerProblem = factorial (N - 1) ; 
        long long int biggerProblem = N * smallerProblem ; 
        
        return biggerProblem ; 
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
        cin>>N;
        Solution ob;
        cout << ob.factorial(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends