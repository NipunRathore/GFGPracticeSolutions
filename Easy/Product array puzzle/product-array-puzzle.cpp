//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here       
        // initialise with 1's so that multiplication can be done 
        vector<long long int> ans (n, 1) ; 

        long long int prefixProd = 1 ; 
        long long int suffixProd = 1 ; 

        for (int i = 0 ; i < n ; i ++)
        {
            // multiply with prefix prod first and then update i.e., multiply current index element to it 
            // multiply by product of all elements to the left of current index
            ans[i] *= prefixProd ;
            prefixProd *= nums[i] ;
        }

        for (int i = n - 1 ; i >= 0 ; i --)
        {
            // multiplt with current value first and then update for next iteration
            // multiply by product of all elements to the right of current index
            ans[i] *= suffixProd ;
            suffixProd *= nums[i] ; 
        }

        return ans ; 
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends