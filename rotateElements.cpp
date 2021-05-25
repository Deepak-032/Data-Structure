#include<iostream>
using namespace std;

void rotate(int a[], int n, int k)
{
    int i, j, t=a[0];
    for(j=0;j<k;j++)
    {
        for(i=0;i<n-1;i++)
        {
            a[i]=a[i+1];
        }
        a[n-1]=t;
        t=a[0];
    }
}
int main()
{
    int a[30],i,n,k;
    cin>>n;             // no of elements
    for(i=0;i<n;i++)
    cin>>a[i];          // adding elements into an array
    cin>>k;             // position through which every element has to be moved
    rotate(a,n,k);
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";    // printing the resulted array
    return 0;
}