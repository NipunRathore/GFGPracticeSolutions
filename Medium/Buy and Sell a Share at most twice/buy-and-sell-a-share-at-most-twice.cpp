//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
    int solve(vector<int> &prices, int index, int buy, int limit, vector<vector<vector<int>>>& dp)
    {
        if (index == prices.size())
        {
            return 0 ; 
        }
    
        if (limit == 0)
        {
            return 0 ;
        }
    
        if (dp[index][buy][limit] != -1)
        {
            return dp[index][buy][limit] ; 
        }
    
        int profit = 0 ; 
        if (buy)
        {
            // when allowe to buy -> you can either buy on current day/index OR skip to next day 
            int buy = -prices[index] + solve(prices, index + 1, 0, limit, dp) ; 
            int ignore = 0 + solve(prices, index + 1, 1, limit, dp) ; 
    
            profit = max (buy, ignore) ; 
        }
    
        else 
        {
            // when allowed to sell -> either sell on current index or skip to next index 
            int buy = +prices[index] + solve(prices, index + 1, 1, limit - 1, dp) ; 
            int ignore = 0 + solve(prices, index + 1, 0, limit, dp) ; 
            // answer is max of generated by both options 
            profit = max (buy, ignore) ; 
        }
        dp[index][buy][limit] = profit ; 
        return dp[index][buy][limit] ; 
    }
    
    int solveTab(vector<int> &prices)
    {
        int n = prices.size() ; 
    // using n + 1 because while computing we access index + 1, whe index = n - 1 it will become n
    // so to access nth index we need array of size n+ 1
        vector<vector<vector<int>>> dp (n + 1, vector<vector<int>> (2, vector<int> (3, 0))) ;
    
        // use base cases 
        // array already 0 nothing to be done 
    
        // 
        for (int index = n - 1 ; index >= 0 ; index --)
        {
            for (int buy = 0 ; buy < 2 ; buy ++)
            {
                for (int limit = 1 ; limit <= 2 ; limit ++)
                {
                    int profit = 0 ; 
                    if (buy)
                    {
                        // when allowe to buy -> you can either buy on current day/index OR skip to next day 
                        int buy = -prices[index] + dp[index + 1][0][limit] ; 
                        int ignore = 0 + dp[index + 1][1][limit] ; 
    
                        profit = max (buy, ignore) ; 
                    }
    
                    else 
                    {
                        // when allowed to sell -> either sell on current index or skip to next index 
    
                        // LIMIT updated/reduced only when 1 Transaction COmpleted
                        // Transaction => BUY + SELL 
                        // Therefore, after Selling reduce the limit by 1 
                        int buy = +prices[index] + dp[index + 1][1][limit - 1] ; 
                        int ignore = 0 + dp[index + 1][0][limit] ; 
                        // answer is max    of generated by both options 
                        profit = max (buy, ignore) ; 
                    }
                    dp[index][buy][limit] = profit ; 
                }
            }
        }
        return dp[0][1][2] ; 
    }

        int maxProfit(vector<int>&price){
            //Write your code here..
            // int n = price.size() ; 
            // 3 NON CONSTANT PARAMETERS IN RECURSIVE FUNCTION 
            // Thereforem 3-D DP 
            // vector<vector<vector<int>>> dp (n, vector<vector<int>>(2, vector<int>(3, -1))) ; 
            // return solve(price, 0, 1, 2, dp) ; 
            return solveTab(price) ; 
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends