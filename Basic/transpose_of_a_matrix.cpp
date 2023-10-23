#include<iostream>
using namespace std;
void reverseArray(int ar[][4],int j,int row){
    for(int i=0; i<row/2; i++){
        int temp=ar[i][j];
        ar[i][j]=ar[row-1-i][j];
         ar[row-1-i][j]=temp;     
    }
}
int main(){
    int ar[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}},i,j;
     printf("BEFORE TRANSPOSE\n");
    for(i=0; i<4; i++){
        for(j=0; j<4; j++)
        printf("%d ",ar[i][j]);
        printf("\n");
    }
    //transpose loops
    for(i=0; i<4; i++){
        for(j=i; j<4; j++){
            int temp=ar[i][j];
            ar[i][j]=ar[j][i];
            ar[j][i]=temp;
        }
    }
    printf("AFTER TRANSPOSE\n");
    for(i=0; i<4; i++){
        for(j=0; j<4; j++)
        printf("%d ",ar[i][j]);
        printf("\n");
    }
    for(j=0; j<4; j++){
        reverseArray(ar,j,4);
    }
     printf("AFTER 90 ROTATE\n");
    for(i=0; i<4; i++){
        for(j=0; j<4; j++)
        printf("%d ",ar[i][j]);
        printf("\n");
    }
    return 0;
}
