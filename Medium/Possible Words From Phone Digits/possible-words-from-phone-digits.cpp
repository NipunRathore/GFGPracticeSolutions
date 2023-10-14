//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void solve(int digits[], int index, int n, string output, vector<string>& ans, vector<string>& digitToString)
    {
        // base case - when index goes beyond string digits then store current combination & return 
        if (index >= n)
        {
            ans.push_back(output) ; 
            return ; 
        }

        // process current digit of digit string 
        int num = digits[index] ; 
        // fetch corresponding string from mapping
        string val = digitToString[num] ; 

        // iterate through each letter of string 
        for (int i = 0 ; i < val.length() ; i ++)
        {
            // add to combination string 
            output.push_back(val[i]) ; 
            // make next recursive call 
            solve(digits, index + 1, n, output, ans, digitToString) ; 
            // backtracking to explore all combinations 
            output.pop_back() ; 
        }
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string> ans ; 
        if (N == 0)
        {
            return ans ; 
        }
        // combination string 
        string output = "" ; 
        int index = 0 ; 
        // mapping of digit to letters on phone keypad
        vector<string> digitToString = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"} ;
        solve(a, index, N, output, ans, digitToString) ;

        return ans ; 
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends