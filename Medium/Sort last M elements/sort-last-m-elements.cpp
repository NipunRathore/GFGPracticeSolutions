//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void sortLastMelements(vector<int>&nums, int n, int m) {
    	// Code here
    	if (m < n)
    	{
    	    sort(nums.begin() + (n - m), nums.end()) ;
    	}
    	else 
    	{
    	    sort(nums.begin(), nums.end()) ; 
    	}
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<int>nums(n+m);
		for(auto &i: nums)
			cin >> i;
		Solution obj;
		obj.sortLastMelements(nums, n, m);
		for(auto i: nums)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends