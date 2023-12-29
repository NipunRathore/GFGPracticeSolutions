//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;

class student
{
    protected :
        int roll_number;
        
    public:
        void set_number(int a)
        {
            roll_number = a;
        }
        
        void display_number()
        {
            cout<<roll_number<<endl;
        }
};


// } Driver Code Ends
//User function Template for C++
class test: public student 
{
    // Add set_marks() method here.
    public:
    float m[5] ; 
    void set_marks(float marks[])
    {
        for (int i = 0 ; i < 5 ; i ++)
        {
            m[i] = marks[i] ; 
        }
    }
};

class result: public test
{
    // Add display() method here.
    public:
    float avg ; 
    
    void display ()
    {
        int total = 0 ; 
        for (int i = 0 ; i < 5 ; i ++)
        {
            total += m[i] ; 
        }
        avg = total / 5 ; 
        cout << roll_number << " " << total << " " << avg << endl ; 
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
    	result student1;
	    int n;
	    cin>>n;
	    student1.set_number(n);
	    float temp[5];
	    int i;
	
	    for(i = 0; i < 5; i++)
	        cin>>temp[i];
	
	    student1.set_marks(temp);
	    student1.display();
	}

	return 0;    
}

// } Driver Code Ends