//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        // edge case 
        if (head == NULL || head -> next == NULL)
        {
            return head ; 
        }
    
        Node* temp = head ; 
        vector<int> arr ; 
        int size = 0 ; 
        while (temp != NULL)
        {
            size ++ ;
            arr.push_back(temp -> data) ; 
            temp = temp -> next ; 
        }
    
        k %= size ;
        // rotate array to the right by 'k' 
        // reverse(arr.begin(), arr.end()) ; 
        // reverse(arr.begin(), arr.begin() + k) ; 
        // reverse(arr.begin() + k, arr.begin() + size) ; 
        
        // Reverse the first k elements
        reverse(arr.begin(), arr.begin() + k) ;
        // Reverse the remaining n-k elements
        reverse(arr.begin() + k, arr.end()) ;
        // Reverse the entire array
        reverse(arr.begin(), arr.end()) ;
         
        // update values of list nodes 
        int index = 0 ; 
        temp = head ; 
        while (temp != NULL)
        {
            temp -> data = arr[index] ; 
            index ++ ; 
            temp = temp -> next ; 
        }
    
        return head ;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends