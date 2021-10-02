#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        left = NULL;
        right = NULL;
        data = val;
    }
};

void binaryToDLL(Node *root, Node **head)
{
    if(root == NULL) {return;}

    static Node *prev = NULL;
    binaryToDLL(root->left, head);

    if(prev == NULL) { *head = root;}
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    binaryToDLL(root->right,head);

}

void display(Node *root)
{   
    Node *temp = root;
    if(!root)
        cout<<"List is Empty"<<endl;
        //root = root -> next;
        while(root->right != NULL)
        {
            cout<<root->data<<" ";
            root = root->right;
        }
        cout<<root->data<<" ";
        cout<<endl;
        while(root != NULL)
        {
            cout<<root->data<<" ";
            root = root->left;
        }
        
}
int main()
{   
    Node *head = NULL;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    binaryToDLL(root, &head);
    display(head);
    return 0;
}