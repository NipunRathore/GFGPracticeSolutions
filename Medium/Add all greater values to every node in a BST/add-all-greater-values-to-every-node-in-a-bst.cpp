//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



Node* modify(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
   
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

       //getline(cin, s);
        // int k = stoi(s);
        // getline(cin, s);

        root = modify(root);
        vector<int> v;
        inorder(root, v);
        for(auto i:v)
            cout << i << " ";
        cout << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends


/*
Node structure is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// modify the BST and return its root
    void inOrderUtil(Node *root, vector<int> &data)
    {
        if (root == NULL)
        {
            return ; 
        }
        // L
        inOrderUtil(root -> left, data) ; 
        // N
        data.push_back(root -> data) ; 
        // R
        inOrderUtil(root -> right, data) ; 
    }

    void updateUtil(Node *root, vector<int> &data, int &index)
    {
        if (root == NULL)
        {
            return ; 
        }
        // L
        updateUtil(root -> left, data, index) ; 
        // N
        root -> data = data[index] ;
        index ++ ;   
        // R
        updateUtil(root -> right, data, index) ; 
    }
    
Node* modify(Node *root)
{
    // Your code here
    vector<int> data ; 
    // store the sorted order traversal / InOrder traversal of BST
    inOrderUtil (root, data) ; 

    int n = data.size() ; 
    // convert sorted array such that each value replaced with (original value + all values greater than than value)
    // Data array in Ascending Order therefore traverse from END to START
    for (int i = n - 2 ; i >= 0 ; i --)
    {
        data[i] += data[i + 1] ; 
    }

    int index = 0 ; 
    // update the values of nodes of BST
    updateUtil(root, data, index) ; 

    return root ;
}