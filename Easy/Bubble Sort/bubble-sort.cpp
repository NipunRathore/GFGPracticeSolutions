//{ Driver Code Starts
//Initial Template for C++

// C program for implementation of Bubble sort
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

// swapping the elements
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void solve(int *arr, int size)
    {
        // BASE CASE 
        if (size == 0 || size == 1)
        {
            return ; 
        }
        
        // SOLVE ONE CASE 
        // place largest element at last position 
        for (int i = 0 ; i < size - 1 ; i ++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]) ; 
            }
        }
        
        // RECURSION
        solve(arr, size - 1) ; 
    }
    //Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n)
    {
        // Your code here  
        // solution - 1 
        // sort(arr, arr + n) ; 
        //T.C. = O (N*logN)
        
        // solution - 2
        // using recursion 
        solve(arr, n) ; 
    }
};


//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
  
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      
    Solution ob;  
      
    ob.bubbleSort(arr, n);
    printArray(arr, n);
    }
    return 0;;
}
// } Driver Code Ends