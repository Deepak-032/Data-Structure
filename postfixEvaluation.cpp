#include<iostream>

using namespace std;
int stack[20];
int top=-1;

void push(int value)
{
    stack[++top]=value;
}
int pop()
{
    if(top==-1)
    return -1;
    else
    return stack[top--];
}
int main()
{
    char ex[20]="";
    int i,y,x,z,result;
    cout<<"Enter postfix expression to evaluate :: ";
    cin>>ex;

    for(i=0;ex[i]!='\0';i++)
    {
        if(isdigit(ex[i])) // if(ex[i]>='0' && ex[i] <= '9')
        {
            z=ex[i]-48;
            push(z);
        }
        else
        {
            y=pop();
            x=pop(); 
            if(ex[i]=='*')
            {
                result= x*y;
                push(result);
            }
            else if(ex[i]=='/')
            {
                result= x/y;
                push(result);
            }
            else if(ex[i]=='+')
            {
                result= x+y;
                push(result);
            }
            else if(ex[i]=='-')
            {
                result= x-y;
                push(result);
            }
        }
    }
    cout<<"The result of expression "<<ex<<" = "<<pop();
    return 0;
}