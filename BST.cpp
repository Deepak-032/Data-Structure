#include<iostream>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;
};
BSTNode* findMIN(BSTNode* root)
{
    BSTNode* current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
void inorder(BSTNode* root) 
{ 
    if (root != NULL)
    { 
        inorder(root->left); 
        cout<<root->data<<endl; 
        inorder(root->right);
    }
}
BSTNode* insert (BSTNode *root ,int data)
{
    BSTNode *current;
    if(root==NULL)
    {
    current= (BSTNode*)malloc(sizeof(BSTNode));
    current->data=data;
    current->left=NULL;
    current->right=NULL;
    return current;
    }
    else if(data<root->data)
            root->left=insert(root->left, data);
    else if(data>root->data)
            root->right=insert(root->right,data);
    return root;
}
BSTNode* find (BSTNode *root,int data)
{
    if(root==NULL)
    return NULL;
    else if(data<root->data)
    return(find(root->left,data));
    else if(data>root->data)
    return(find(root->right,data));
    return(root);
}
BSTNode* deletee (BSTNode* root,int data)
{
    BSTNode *temp;
    if(root==NULL)
        cout<<"element "<<data<<" not found in BST"<<endl;
    else if(data<root->data)
        root->left=deletee(root->left,data);
    else if(data>root->data)
        root->right=deletee(root->right,data);
    else if(root->left && root->right)
    {
        temp=findMIN(root->right);
        root->data=temp->data;
        root->right=deletee(root->right,temp->data);
    }
    else
    {
        temp=root;
        if(temp->right==NULL)
            temp=temp->left;
        else if(temp->left==NULL)
            temp=temp->right;
        free(root);
        return temp;
    }
    return root;
}
int main()
{
    int value, choice;
    BSTNode *root=NULL;
    cout<<"enter choice\n1. TO INSERT ELEMENT\n2. TO DELETE ELEMENT\n3. TO FIND ELEMENT\n4. TO PRINT ELEMENTS\n5. EXIT\n"<<endl;
    while(5)
    {
    cout<<"enter choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1: 
        cout<<"enter value to be inserted: ";
        cin>>value;
        root=insert(root,value);
        break;
    case 2:
        cout<<"enter element to delete: ";
        cin>>value;
        deletee(root,value);
        break;
    case 3: 
        cout<<"enter element to find: ";
        cin>>value;
        if(find(root,value)==NULL)
        cout<<"element does not exist"<<endl;
        else
        cout<<"address of this element is: "<<find(root,value);
        break;
    case 4:
        inorder(root);
        break;
    default:
        exit(0);
        break;
    }
    }
    return 0;
}