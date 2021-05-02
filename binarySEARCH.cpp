#include<iostream>
using namespace std;

void Bsearch(int L[],int n,int data)
{
    int l=0, u=n-1, m;
    while(u>=l)
    {
        m=(l+u)/2;
        if(data==L[m])
        {
            cout<<"successful, item found at index: "<<m<<endl;
            return;
        }
        else if(data>L[m])
            l=m+1;
        else
            u=m-1;
    }
    cout<<"unsuccessful, item not found"<<endl;
}
int main()
{
    int L[10],data;
    cout<<"enter 10 sorted elements in ascending order"<<endl;
    for(int i=0;i<10;i++)
        cin>>L[i];
    cout<<"enter data to found in the search"<<endl;
    cin>>data;
    Bsearch(L,10,data);
    return 0;
}