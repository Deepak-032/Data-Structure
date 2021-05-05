#include <iostream>
using namespace std;
#define SIZE 10

void insertionSORT(int a[], int n)
{
    int k, j, temp;
    for (k = 1; k <= n - 1; k++)
    {
        temp =a[k];
        j=k-1;
        while(a[j]>temp&&j>=0)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }
}
int main()
{
    int A[SIZE];
    for(int i=0;i<SIZE;i++)
        cin>>A[i];
    insertionSORT(A,SIZE);
    for(int i=0;i<SIZE;i++)
        cout<<A[i]<<" ";
    return 0;
}