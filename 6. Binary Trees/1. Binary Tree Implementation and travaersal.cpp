#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* createNode(int val)
{
    Node *newNode = new Node(val);
    if(newNode == NULL)
    {
        cout<<"Node not crreated!";
        return NULL;
    }
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node *root, int val)
{
    if(root == NULL)
    {
        root = createNode(val);
        return root;
    }
    queue<Node *> q;
    q.push(root);

    while(q.empty() == false)
    {
        Node *temp = q.front();
        q.pop();

        if(temp->left != NULL)
            q.push(temp->left);
        else{
            temp->left = createNode(val);
            return root;
        }

        if(temp->right != NULL)
            q.push(temp->right);
        else{
            temp->right = createNode(val);
            return root;
        }
    }
}

// function to insert nodes into binary tree in level order
void inorderTraversal(Node *root)
{
    if(root == NULL)
        return;

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node *root)
{
    if(root == NULL)
        return;

    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node *root)
{
    if(root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

void levelorderTraversal(Node *root)
{
    if(root == NULL)
        return;
    
    queue<Node *> q;
    q.push(root);

    while(q.empty() == false)
    {
        Node *temp = q.front();
        q.pop();
        cout<<temp->data<<" ";

        if(temp->left != NULL)
            q.push(temp->left);

        if(temp->right != NULL)
            q.push(temp->right);
    }
}

int main()
{

    Node *root = NULL;

    for(int i=1; i<=7; i++)
    {
        root = insertNode(root, i);
    }

    cout<<"Level order Traversal:\n";
    levelorderTraversal(root);
    cout<<"\nIn-order Traversal: "<<endl;
    inorderTraversal(root);
    cout<<"\nPre-order Traverdal"<<endl;
    preorderTraversal(root);
    cout<<"\nPost-order Traversal: \n";
    postorderTraversal(root);

    return 0;
}