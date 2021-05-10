#include<iostream>
#include<conio.h>

using namespace std;
char stack[20];
int top=-1;

void push(char value)
{
    stack[++top]=value;
}
char pop()
{
    if(top==-1)
    return -1;
    else
    return stack[top--];
}
int priority(char op)
{
    if(op=='*'||op=='/')
    return 2;
    if(op=='+'||op=='-')
    return 1;
    return 0;
}
int main()
{
    int i;
    char ex[20]="",x;
    cout<<"enter infix expression"<<endl;
    cin>>ex;

    for(i=0;ex[i]!='\0';i++)
    {
        if((ex[i]>='a' && ex[i] <= 'z')||(ex[i] >= 'A' && ex[i] <= 'Z'))
        cout<<ex[i];

        else if(ex[i] == '(')
            push(ex[i]);

        else if(ex[i] == ')')
        {
            //we can use either of the below two statements
           /* while((stack[top])!= '(')
            cout<<pop();
            pop();*/
            while((x = pop()) != '(')
            cout<<x;
        }

        else
        {
            while(priority(stack[top]) >= priority(ex[i]))
            cout<<pop();
            push(ex[i]);
        }
    }
    while(top!=-1)
    cout<<pop();
    getch();
    return 0;
}