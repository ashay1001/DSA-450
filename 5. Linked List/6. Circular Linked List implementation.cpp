#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node* insertAtHead(Node *head, int val)
{
    Node *new_node = new Node(val);
    if(head == NULL)
    {
        new_node->next = new_node;
        head = new_node;
        return head;
    }

    Node *temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head;
    head = new_node;
    return head;
}

Node* insertAtTail(Node *head, int val)
{
    if(head == NULL)
    {
        head = insertAtHead(head, val);
        return head;
    }

    Node *new_node = new Node(val);
    Node *temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head;
    return head;
}

void display(Node *head)
{
    Node *temp = head;
    while(temp->next != head)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout <<temp->data<<" ";
}
Node* deleteAthead(Node *head)
{
    Node *temp = head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    Node *del_node = head;
    temp->next = head->next;
    head = head->next;
    delete del_node;
    return head;
}
Node* deleteNode(Node *head, int pos)
{
    if(pos == 1)
    {
        return deleteAthead(head);
    }

    Node *temp=head;
    int count=1;

    while(count != pos-1)
    {
      temp=temp->next;
      count++;
    }
 
      Node *del_node = temp->next;
      temp->next=temp->next->next;
 
      delete del_node;
      return head;
}

int main()
{
    Node *head = NULL;
    for(int i=1; i<=5; i++)
    {
        head = insertAtTail(head, i);
    }
    cout<<"Befor deleting head: \n";
    display(head);
    head = deleteNode(head, 2);
    cout<<"\nAfter deleting: \n";
    display(head);
}