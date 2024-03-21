//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        // code here
        // {number, freq}
        unordered_map<int, int> mp ; 
        // {freq, number} to sort by frequency 
        set<pair<int, int> > st ; 
        
        // to store ans 
        vector<vector<int> > ans ; 
        
        for (int i = 0 ; i < N ; i ++)
        {
            // 1-D array to store top K numbers of current iteration 
            vector<int> res ; 
            
            // if freq greater than 0 means already stored in map and set 
            // and if we directly increase frequency in map and make another entry in set 
            // then we will have to frequencies corresponding to same number in set 
            // therefore, remove previous entry from set 
            if (mp[arr[i]] > 0)
            {
                st.erase({-mp[arr[i]], arr[i]}) ; 
            }
            
            // increase frequency 
            mp[arr[i]] ++ ; 
            // store {freq, element} in set 
            st.insert({-mp[arr[i]], arr[i]}) ; 
            
            int temp = K ; 
            // store top K elements of set in res vector 
            for (auto it : st)
            {
                if (temp == 0)
                {
                    break ;
                }
                
                res.push_back(it.second) ; 
                temp -- ; 
            }
            // store 1D array res in the ans 2D array 
            ans.push_back(res) ; 
        }
        return ans ; 
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> a(N);
        Array::input(a,N);
        
        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);
        
        for(auto it:res)
            Array::print(it);
        
    }
}

// } Driver Code Ends