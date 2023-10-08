//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool checkPalindrome(string str, int start, int end)
	{
	   // base case 
	    if (start >= end)
	    {
	        return true ; 
	    }
	    
	   // solve one case / processing 
	    if (str[start] != str[end])
	    {
	        return false ; 
	    }
	    start ++ ; 
	    end -- ; 
	    
	   // recursion
	    return checkPalindrome(str, start, end) ; 
	}
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    // SOLUTION - 1
	    // T.C. = O(N)
	    // S.C. = O(N)
	   // string str = S ; 
	   // reverse(str.begin(), str.end()) ;
	   // if (str == S)
	   // {
	   //     return 1 ; 
	   // }
	   // return 0 ; 
	   
	   // SOLUTION - 2
	   //TWO POINTERS 
	   //T.C. = O (N)
	   //S.C. = O (1)
	   int start = 0 ; 
	   int end = S.length() - 1 ; 
	   while (start < end)
	   {
	       if (S[start] != S[end])
	       {
	           return 0 ;
	       }
	       start ++ ; 
	       end -- ; 
	   }
	   return 1 ;
	   
	   //SOLUTION - 3
	   //RECURSION 
	   //int start = 0 ; 
	   //int end = S.length() - 1 ; 
	   //bool ans = checkPalindrome(S, start, end) ; 
	   //if (ans)
	   //{
	   //    return 1 ; 
	   //}
	   //return 0 ; 
	}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends