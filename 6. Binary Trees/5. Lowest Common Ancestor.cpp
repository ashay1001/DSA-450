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

// function to insert nodes into binary tree in level order
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

        if(temp->left != NULL && temp->data != -1)
        {
            if(temp->left->data != -1) q.push(temp->left);
        }
        else
        {
            temp->left = createNode(val);
            return root;
        }

        if(temp->right != NULL)
        {
            if(temp->right->data != -1) q.push(temp->right);
        }
        else
        {
            temp->right = createNode(val);
            return root;
        }
    }
}

void inorderTraversal(Node *root)
{
    if(root == NULL)
        return;

    inorderTraversal(root->left);
    if(root->data != -1) cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node *root)
{
    if(root == NULL)
        return;

    if(root->data != -1) cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node *root)
{
    if(root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    if(root->data != -1) cout<<root->data<<" ";
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

        if(temp->left != NULL && temp->left->data != -1)
            q.push(temp->left);

        if(temp->right != NULL && temp->right->data != -1)
            q.push(temp->right);
    }
}

bool getPath(Node *root, int key, vector<int> &path)
{
    if(root == NULL)
    {
        return false;
    }
    path.push_back(root->data);
    if(root->data == key)
    {
        return true;
    }
    bool left = getPath(root->left, key, path);
    bool right = getPath(root->right, key, path);
    if(left || right)
    {
        return true;
    }
    path.pop_back();
    return false;
}

int findLowestCommonAncestor(Node *root, int n1, int n2)
{
    vector<int> path1, path2;
    bool p1 = getPath(root, n1, path1);
    bool p2 = getPath(root, n2, path2);
    if(p1 == false || p2 == false)
    {
        return -1;
    }
    int i;
    for(i=0; i<path1.size() && i<path2.size(); i++)
    {
        if(path1[i] != path2[i])
        {
            break;
        }
    }
    return path1[i-1];
}

int main()
{
    Node *root = NULL;
    int arr[] = {100,11,3,4,22,90,45,60,70,80};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++)
    {
        root = insertNode(root, arr[i]);
    }

    cout<<"Level order Traversal:\n";
    levelorderTraversal(root);
    cout<<"\nIn-order Traversal: "<<endl;
    inorderTraversal(root);
    cout<<"\nPre-order Traverdal"<<endl;
    preorderTraversal(root);
    cout<<"\nPost-order Traversal: \n";
    postorderTraversal(root);
    cout<<"\nLowest common ancestor:\n";
    cout<<findLowestCommonAncestor(root,60, 70);
    return 0;
}