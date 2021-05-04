#include<iostream>
using namespace std;
#define SIZE 10
void selectionSORT(int A[], int n)
{
    int t,small, loc;
    for(int k=1;k<=n-1;k++)
    {
        small=A[k-1];
        loc=k-1;
        for(int j=k;j<=n-1;j++)
            if(A[j]<small)
            {
                small=A[j];
                loc=j;
            }
            if(loc!=(k-1))
            {
                t=A[k-1];
                A[k-1]=A[loc];
                A[loc]=t;
            }
    }
}
int main()
{
    int A[SIZE];
    for(int i=0;i<SIZE;i++)
        cin>>A[i];
    selectionSORT(A,SIZE);
    for(int i=0;i<SIZE;i++)
        cout<<A[i]<<" ";
    return 0;
}