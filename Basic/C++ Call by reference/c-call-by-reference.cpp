//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++

void reverse_dig(int &a,int &b)
{
    //Add your code here.
     //reversing a
    int reva = 0 ;
    while(a != 0)
    {
        int digita = a % 10 ;
        reva = reva * 10 + digita ;
        a = a / 10 ;
    }
    a = reva ;
    
   //reversing b
    int revb = 0 ;
    while(b != 0)
    {
        int digitb = b % 10 ;
        revb = revb * 10 + digitb ;
        b = b / 10 ;
    }
    b = revb ;
}
void swap(int &a,int &b)
{
    //Add your code here.
    int temp = a ; 
    a = b ; 
    b = temp ; 
}


//{ Driver Code Starts.

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int a, b;
	    cin>>a>>b;
	
	    reverse_dig(a,b);
	    swap(a,b);
	    cout<<a<<" "<<b<<endl;
    }
	return 0;
}
// } Driver Code Ends