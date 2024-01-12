//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        stack<int> s ;
        // Step 1 : pop first k elements from Q and push into stakc 
        for (int i = 0 ; i < k ; i ++)
        {
            int front = q.front() ; 
            s.push(front) ; 
            q.pop() ; 
        }
        
        // Step 2 : fetch from stack and push into queue
        while (!s.empty())
        {
            int top = s.top() ;
            q.push(top) ; 
            s.pop() ; 
        }
        
        // fetch first n - k elements from queue and push back into queue itself 
        int t = q.size() -  k ; 
        while (t --)
        {
            int front = q.front() ; 
            q.pop() ; 
            q.push(front) ; 
        }
        
        return q ;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends