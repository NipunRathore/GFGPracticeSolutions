//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(int arr[],int n)
    {
        //Your code here
        // store array elements in map 
        unordered_map<int, int> mp ;
        for(int i = 0 ; i < n ; i ++)
        {
            // if freq of two elements same we want to consider smaller element first therefore need to use negative sign 
            // 2 < 5
            // -2 > -5
            mp[-arr[i]] ++ ;
        }
            
        // create a Max-Heap Priority Queue & insert {freq, element} pairs in it
        // so that element at top of max freq 
        priority_queue<pair<int, int> > pq ;
        for (auto it : mp)
        {
            pq.push({it.second, it.first}) ; 
        }
        
        // fetch elements from pq & store in resultant array 
        vector<int> ans ;
        while(!pq.empty())
        {
            int freq = pq.top().first ;
            int element = pq.top().second ;
            for(int i = 0 ; i < freq ; i ++)
            {
                // using -ve sign to neutralise the -ve used earlier
                ans.push_back(-element) ;
            }
            pq.pop() ;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}


// } Driver Code Ends