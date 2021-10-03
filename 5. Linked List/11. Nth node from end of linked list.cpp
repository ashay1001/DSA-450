#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

int main()
{
    int i,n,l,k;
    struct Node *head = NULL,  *tail = NULL;
    cin>>n>>k;
    int firstdata;
    cin>>firstdata;
    head = new Node(firstdata);
    tail = head;
    for(i=1;i<n;i++)
    {
        cin>>l;
        tail->next = new Node(l);
        tail = tail->next;
    }
    cout<<getNthFromLast(head, k)<<endl;
    return 0;
}

Node* reverse(Node *head)
{
    Node *prev = NULL, *next = NULL, *curr = head;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
int getNthFromLast(Node *head, int n)
{
    if(n==0) return -1;
    
    head = reverse(head);
    while(n>1 && head != NULL)
    {
        n--;
        head = head->next;
    }
    if(head == NULL) {return -1;}
    else return head->data;
}