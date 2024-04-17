//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

// CollegeCourse Class 
class CollegeCourse
{
    //your code here
    string courseID ;
    char grade ;
    int credits ;
    int gradePoints ;
    int honorPoints ;
    
    public:
        void set_CourseId(string CID)
        {
            courseID = CID ;
        }
        void set_Grade(char g)
        {
            grade = g ;
        }
        void set_Credit(int cr)
        {
            credits = cr ;
        }
        int calculateGradePoints(char g)
        {
            if(g == 'A' || g == 'a')
            {
                gradePoints = 10 ; 
            }
            else if(g == 'B' || g == 'b')
            {
                gradePoints = 9 ;
            }
            else if(g == 'C' || g == 'c')
            {
                gradePoints = 8 ;
            }
            else if(g == 'D' || g == 'd')
            {
                gradePoints = 7 ;
            }
            else if(g == 'E' || g == 'e')
            {
                gradePoints = 6 ;
            }
            else if(g == 'F' || g == 'f')
            {
                gradePoints = 5 ;
            }
            return gradePoints ;
        }
        
        float calculateHonorPoints(int gp,int cr)
        {
            honorPoints = gp * cr ;
            return honorPoints ;
        }
        
        void display()
        {
            cout << gradePoints << " " << honorPoints << endl ;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    CollegeCourse cc;
    string courseId;
    int gp;
    char grade;
    int credits;
    cin>>courseId>>grade>>credits;
    cc.set_CourseId(courseId);
    cc.set_Grade(grade);
    cc.set_Credit(credits);
    gp=cc.calculateGradePoints(grade);
    cc.calculateHonorPoints(gp,credits);
    cc.display();
    }
    return 0;
}

// } Driver Code Ends