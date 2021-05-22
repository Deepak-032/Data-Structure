#include<iostream>
using namespace std;

typedef struct node
{
    int val;
    struct node *prev, *next;
}node_t;
node_t *head=NULL;
void insertasfirstnode()
{
    node_t *current;
    current = (node_t *)malloc(sizeof(node_t));
    cout<<"Enter a number"<<endl;
    cin>>current->val;
    current->next=NULL;
    current->prev=NULL;
    if (head==NULL)
        head=current;
    else
    {
        current->next=head;
        head->prev=current;
        head=current;
    } 
}
void deletenode()
{
    node_t *ptr; 
    if (head==NULL)
        cout<<"List is empty";
    else
    {
        ptr=head;
        head=head->next;
        head->prev=NULL;
        free(ptr);
    }
}
void viewlist()
{
    node_t *ptr;
    if (head==NULL)
        cout<<"List is empty";
    ptr=head;
    while (ptr!=NULL)
    {
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

int main()
{
    int choice;
    char ch;
    cout<<"Enter choice:\n1. Insertion\n2. Deletion\n3. View List\n";
    do
    {
        cin>>choice;
        switch (choice)
        {
        case 1:
            insertasfirstnode();
            break;
        case 2:
            deletenode();
            break;
        case 3:
            viewlist();
            break;
        default:
            exit (0);
        }
        cout<<"wanna repeat\n";
        fflush(stdin);
        cin>>ch;
    }while(ch=='y');
    return 0;
}