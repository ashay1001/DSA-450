#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val; left = NULL; right = NULL;
    }
};

Node* insertBST(Node *root, int val)
{
    if(root == NULL) {return new Node(val);}

    if(root->data > val)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }
}

void inorderBST(Node *root)
{
    if(root == NULL) {return;}
    inorderBST(root->left);
    cout<<root->data<<" ";
    inorderBST(root->right);
}

int searchBST(Node *root, int key)
{
    if(root == NULL) {return -1;}
    if(root->data == key) {return 1;}
    if(root->data > key)
        searchBST(root->left,key);
    else
        searchBST(root->right, key);
}

Node* inorderSuccesor(Node *root)
{
    Node *temp = root;
    while(temp != NULL && temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node* deleteBST(Node *root, int key)
{
    if(root->data > key)
    {
        root->left = deleteBST(root->left, key);
    }
    else if(root->data < key)
    {
        root->right = deleteBST(root->right, key);
    }
    else
    {
        if(root->left == NULL) // only right child case
        {
            Node *temp = root->right;
            free(root);
            return temp;                
        }
        else if(root->right == NULL) // only left child case
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            // root to be deleted has both the childs
            Node *temp = inorderSuccesor(root->right);
            root->data = temp->data;
            root->right = deleteBST(root->right, temp->data);
        }
        return root;
    }
}
int main()
{
    Node *root = NULL;
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++)
    {
        root = insertBST(root, arr[i]);
    }
    inorderBST(root);
    cout<<"\nkey is present or not: "<<searchBST(root, 2)<<endl;
    root = deleteBST(root, 2);
    inorderBST(root);
    cout<<endl;
    return 0;
}