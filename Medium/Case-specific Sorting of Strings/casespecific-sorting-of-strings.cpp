//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string ans = "" ; 
        string upper = "" ; 
        string lower = "" ; 
        
        for (int i = 0 ; i < n ; i ++)
        {
            char ch = str[i] ;
            if (isupper(ch))
            {
                upper += ch ; 
            }
            else
            {
                lower += ch ;
            }
        }
        
        sort(upper.begin(), upper.end()) ; 
        sort(begin(lower), end(lower)) ; 
        
        int i = 0 ; 
        int j = 0 ; 
        int k = 0 ; 
        
        while (k < n)
        {
            char ch = str[k] ; 
            if (isupper(ch))
            {
                ans += upper[i] ; 
                i ++ ;
            }
            else
            {
                ans += lower[j] ; 
                j ++ ;
            }
            k ++ ;
        }
        return ans ; 
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends