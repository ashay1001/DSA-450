#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
Node* insertAtHead(Node *head, int val)
{
    Node *new_node = new Node(val);
    if(head == NULL)
    {
        head = new_node;
        return head;
    }
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
}
Node* insertAtTail(Node *head, int val)
{
    if(head == NULL)
    {
        head = insertAtHead(head, val);
        return head;
    }
    Node *temp = head;
    Node *new_node = new Node(val);
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
    return head;
}

void display(Node *head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
Node* deleteNodeAtHead(Node *head)
{
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
    return head;
}

Node* deleteNode(Node *head, int pos)
{
    if(pos == 1) 
    {
        head = deleteNodeAtHead(head);
        return head;
    }
    int count = 1;
    Node *temp = head;
    while(temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if(temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    delete temp;
    return head;
}

Node* rotate(Node *head, int n)
{
    if(head == NULL) {return NULL;}
    Node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->prev = temp;
    int count = 1;
    while(count <= n)
    {
        head = head->next;
        temp = temp->next;
        count++;
    }
    temp->next = NULL;
    head->prev = NULL;
    return head;
}

int main()
{
    int choice, value;
    char ch;
    Node *head = NULL;
    do
    {
        cout<<"1. Insert at tail 2. Insert at head 3. delete 4. Display 5. Rotate anti clockwise by N nodes\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter value: \n"; cin>>value;
            head = insertAtTail(head, value);
            break;
            case 2:
            cout<<"Enter value: \n"; cin>>value;
            head = insertAtHead(head, value);
            break;
            case 3:
            cout<<"Enter position of node to delete\n";
            cin>>value;
            head = deleteNode(head, value);
            case 4:
            display(head);
            break;
            case 5:
            cout<<"Enter N:\n";
            cin>>value;
            head = rotate(head, value);
            break;
            default:
            cout<<"invalid choice\n";
        }
        cout<<"Do u want to continue? (y/n)\n";
        cin>>ch;
    }while(ch == 'y');
    return 0;
}