#include<iostream>
using namespace std;

void bubbleSORT(int A[], int n)
{
    int t,flag;
    for(int round=1;round<=n-1;round++)
    {
        flag=0;
        for(int j=0;j<=n-1-round;j++)
            if(A[j]>A[j+1])
            {
                flag=1;
                t=A[j];
                A[j]=A[j+1];
                A[j+1]=t;
            }
        if(flag==0)
        {
            cout<<"Rounds: "<<round<<endl;
            return ;
        }
    }
}
int main()
{
    int A[4];
    for(int i=0;i<4;i++)
        cin>>A[i];
    bubbleSORT(A,4);
    for(int i=0;i<4;i++)
        cout<<A[i]<<" ";
    return 0;
}