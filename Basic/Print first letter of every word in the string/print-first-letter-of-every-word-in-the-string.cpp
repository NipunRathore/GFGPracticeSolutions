//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	string firstAlphabet(string S)
	{
	    // Your code goes here
	    string s = "" ;
        s += S[0] ;
        bool flag = false ;
        
        for(int i = 0 ; i < S.length() ; i ++)
        {
            if(S[i] == ' ') 
            {
                flag = true ;
            }
            if(S[i] != ' ' && flag == true) 
            {
                s += S[i] ;
                flag = false ;
            }
        }
        return s ;
	}
};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	string tc;
   	getline(cin, tc);
   	t = stoi(tc);
   	while(t--)
   	{
   		string s;
   		getline(cin, s);

   	
        Solution ob;
   		cout << ob.firstAlphabet(s) << "\n";
   	}

    return 0;
} 

// } Driver Code Ends