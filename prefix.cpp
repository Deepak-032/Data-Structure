#include<iostream>
using namespace std;

char stack[20];
int top=-1;

char* reversee(char *p)
{
    int l,i;
    char t;
    for(l=0;*(p+l)!='\0';l++);
    for(i=0;i<l/2;i++)
    {
        t=*(p+i);
        *(p+i)=*(p+l-1-i);
        *(p+l-1-i)=t;
    }
    return (p);
}
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
    int i,j=0;
    char ex[20]="",x,result[20]="";
    cout<<"enter infix expression"<<endl;
    cin>>ex;
    reversee(ex);

    for(i=0;ex[i]!='\0';i++)
    {
        if((ex[i]>='a' && ex[i] <= 'z')||(ex[i] >= 'A' && ex[i] <= 'Z'))
            result[j++]=ex[i];

        else if(ex[i] == ')')
            push(ex[i]);

        else if(ex[i] == '(')
        {
            //we can use either of the below two statements
           /* while((stack[top])!= ')')
            cout<<pop();
            pop();*/
            while((x = pop()) != ')')
                result[j++]=x;
        }

        else
        {
            while(priority(stack[top]) >= priority(ex[i]))
                result[j++]=pop();
            push(ex[i]);
        }
    }
    while(top!=-1)
    {
        if(stack[top]==')'||stack[top]=='(')
            pop();
        result[j++]=pop();
    }
    result[j]='\0';
    cout<<reversee(result);
    return 0;
}