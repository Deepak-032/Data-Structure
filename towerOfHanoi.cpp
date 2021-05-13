#include <bits/stdc++.h>
using namespace std;
 
void solve(int n, char S, char D, char H, int *count) 
{
    ++*count;
    if (n == 1)
    {
        cout<<"Move plate 1 from "<<S<<" to "<<D<<endl;
        return ;
    }
    solve(n - 1, S, H, D, count);
    cout<<"Move plate "<<n<<" from "<<S<<" to "<<D<<endl;
    solve(n - 1, H, D, S, count);
}

int main()
{ 
    int n,count=0; // Number of disks
    cout<<"Enter no. of plates"<<endl;
    cin>>n; 
    solve(n, 's', 'd', 'h', &count);
    cout<<"Total no. of moves are "<<count; 
    return 0; 
} 