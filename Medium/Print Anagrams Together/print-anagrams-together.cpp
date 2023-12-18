//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& strs) {
        //code here
        // {sortedWord, ListOfCorrespondingAnagrams}
        unordered_map<string,vector<string> > mp ;
        for (auto it : strs)
        {
            string word = it ;
            // after sorting all anagrams become same string so they are tore against the same key in map 
            sort(word.begin(), word.end()) ;
            mp[word].push_back(it) ;
        }

        vector<vector<string> > ans ;
        for (auto it : mp)
        {
            // map stores {sortedWord, ListOfCorrespondingAnagrams}
            // store all the ListOfCorrespondingAnagrams in the 'ans' array
            ans.push_back(it.second) ;
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
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends