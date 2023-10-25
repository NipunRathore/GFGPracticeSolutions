//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int matrix[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		vector<int> ans ;
        
        int col = m ;
        int row = n ;

        int startingRow = 0 ;
        int endingRow = row - 1 ;
        int startingCol = 0 ;
        int endingCol = col - 1 ; 
        
        int count = 0 ;
        int total = row * col ;
        
        while(count < total)
        {
            for (int i = startingCol ; count < total && i <= endingCol ; i ++)
            {
                ans.push_back(matrix[startingRow][i]) ;
                    count ++ ;
            }
            startingRow ++ ;
            
            for (int i = startingRow ; count < total && i <= endingRow ; i++)
            {
                ans.push_back(matrix[i][endingCol]) ;
                    count++ ;
            }
            endingCol -- ;
            
            for (int i = endingCol ; count < total && i >= startingCol ; i --)
            {
                ans.push_back(matrix[endingRow][i]) ;
                    count ++ ;
            }
            endingRow -- ;
            
            for (int i = endingRow ; count < total && i >= startingRow ; i --)
            {
                ans.push_back(matrix[i][startingCol]) ;
                    count ++ ;
            }
            startingCol ++ ;
        }     
        return ans[k - 1] ;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends