#include<iostream>
using namespace std;

#define SIZE 10
int queue[SIZE];
int front=-1, rear=-1;
bool isFull()
{
    if(rear==SIZE-1)
    return true;
    else
    return false;
    
}
bool isEmpty()
{
    if(front==-1)
    return true;
    else
    return false;
}
void enqueue(int value)
{
    if( isFull() )
    cout<<"queue is full"<<endl;
    else
    {
        if (front==-1)
            front=0;
        queue[++rear]= value;
    }
    
}
int dequeue()
{
    int value;
    if( isEmpty() )
    cout<<"queue is empty"<<endl;
    else if(front>=rear)
    {
        value=queue[rear];
        front=-1;
        rear=-1;
        return value;
    }
    else
    {
        value=queue[front++];
        return value;  
    } 
}

int main()
{
    int value, choice;
    cout<<"enter choice\n1. TO ADD ELEMENT\n2. TO DELETE ELEMENT\n3. TO CHECK IF IT IS EMPTY\n4. TO CHECK IF IT IS FULL\n5. EXIT\n"<<endl;
    while(5)
    {
    cout<<"enter choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1: 
        cout<<"enter value to be inserted: ";
        cin>>value;
        enqueue(value);
        break;
    case 2:
        cout<<"deleted element from queue is: "<<dequeue()<<endl;
        break;
    case 3: 
        if(isEmpty())
        cout<<"queue is empty\n";
        else
        cout<<"No, there are "<<rear+1-front<<" elements in the queue"<<endl;
        break;
    case 4:
        if(isFull())
        cout<<"queue is full"<<endl;
        else if(rear==front&&rear!=0)
        cout<<"queue is empty\n";
        else
        cout<<"No, there are "<<rear+1-front<<" elements in the queue"<<endl;
        break;
    default:
        exit(0);
        break;
    }
    cout<<front<<endl<<rear<<endl;
    }
    
    return 0;
}