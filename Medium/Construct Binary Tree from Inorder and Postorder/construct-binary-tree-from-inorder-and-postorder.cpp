//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:
    int findPosition (int in[], int start, int end, int element)
    {
        for (int i = start ; i <= end ; i++)
        {
            if (in[i] == element)
            {
                return i ; 
            }
        }
        return -1 ;
    }

Node *solve(int in[], int post[], int &index, int inOrderStart, int inOrderEnd, int n)
{
    if (index < 0 || inOrderStart > inOrderEnd)
    {
        return NULL ; 
    }
    // use post increment or increase index later on
    int element = post[index];
    index -- ;
    
    // find elements index in inorder
    int position = findPosition(in, inOrderStart, inOrderEnd, element);
    Node *root = new Node(element) ;
    
    // recursive calls for left and right 
    root -> right = solve(in, post, index, position + 1 , inOrderEnd, n) ;
    root -> left = solve(in, post, index, inOrderStart, position - 1, n);

    return root ; 
}

    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        // Your code here
        int postOrderIndex = n - 1 ;
        Node *ans = solve(in, post, postOrderIndex, 0, n - 1, n);
        return ans ; 

    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends