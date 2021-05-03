#include<iostream>
using namespace std;
#define SIZE 10

void bubbleSORT(int A[], int n)
{
    int t;
    for(int round=1;round<=n-1;round++)
        for(int j=0;j<=n-1-round;j++)
            if(A[j]>A[j+1])
            {
                t=A[j];
                A[j]=A[j+1];
                A[j+1]=t;
            }
}
int main()
{
    int A[SIZE];
    for(int i=0;i<SIZE;i++)
        cin>>A[i];
    bubbleSORT(A,SIZE);
    for(int i=0;i<SIZE;i++)
        cout<<A[i]<<" ";
    return 0;
}