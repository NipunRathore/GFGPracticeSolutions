//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int getAngle(int hour , int minutes) {
        // code here
        int minuteHand = minutes * 6 ; 
        double hourHand = hour * 30 + minutes * 0.5 ;
        return min (abs(hourHand - minuteHand), 360 - abs(hourHand - minuteHand)) ; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int H,M;
        
        cin>>H>>M;

        Solution ob;
        cout << ob.getAngle(H,M) << endl;
    }
    return 0;
}
// } Driver Code Ends