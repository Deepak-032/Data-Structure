// linked list 
#include<iostream>
using namespace std;

typedef struct node
{
    int val;
    struct node *next;
}node_t;
node_t *head=NULL;
void insertAsLASTnode()
{
    node_t *current, *ptr;
    current = (node_t *)malloc(sizeof(node_t));
    cout<<"Enter a number"<<endl;
    cin>>current->val;
    current->next=NULL;
    if (head==NULL)
        head=current;
    else
    {
        ptr=head;
        while (ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=current;
    } 
}
void deleteAsFIRSTnode()
{
    node_t *ptr; 
    if (head==NULL)
        cout<<"List is empty";
    else
    {
        ptr=head;
        head=head->next;
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
    cout<<"Enter choice:\n1. Insertion\n2. Deletion\n3. View List\n";
    while(1)
    {
        cout<<"Enter choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            insertAsLASTnode();
            break;
        case 2:
            deleteAsFIRSTnode();
            break;
        case 3:
            viewlist();
            break;
        default:
            exit (0);
        }
    }
    return 0;
}