#include<iostream>
using namespace std;
#define SIZE 6

int loc;
void quick(int a[], int beg, int end)
{
    int left=beg, t, right=end;
    loc=beg;
    while(1)
    {
        while(a[loc]<=a[right]&&loc!=right)
            right=right-1;
        if(loc==right)
            return;
        if(a[loc]>a[right])
        {
            t=a[loc];
            a[loc]=a[right];
            a[right]=t;
            loc=right;
        }
        while(a[left]<=a[loc]&&loc!=left)
            left=left+1;
        if(loc==left)
            return;
        if(a[left]>a[loc])
        {
            t=a[loc];
            a[loc]=a[left];
            a[left]=t;
            loc=left;
        }
    }
}
void quickrecursive(int a[], int beg, int end)
{
    if(beg<end)
    {
        quick(a,beg,end);
        quickrecursive(a,beg,loc-1);
        quickrecursive(a,loc+1,end);
    }
}
int main()
{
    int a[SIZE];
    for(int i=0;i<SIZE;i++)
        cin>>a[i];
    quickrecursive(a,0,SIZE-1);
    for(int i=0;i<SIZE;i++)
        cout<<a[i]<<" ";
    return 0;
}