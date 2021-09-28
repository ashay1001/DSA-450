#include <bits/stdc++.h>
#include <climits>
using namespace std;

struct linkedList
{
    int data;
    linkedList *next;
};
struct linkedList *head1 = NULL;

void insertNode(linkedList *head, int data)
{
    if(head == NULL)
    {
        head1 = new linkedList();
        head1->data = data;
    }
    else
    {
        linkedList *temp = new linkedList();
        temp->data = data;
        while(head->next != NULL)
        {
            head = head->next;
        }
        head->next = temp;
    }
}

void display(linkedList *head)
{
    if(!head)
        cout<<"List is Empty"<<endl;
    else
    {
        //head = head -> next;
        while(head != NULL)
        {
            cout<<head->data<<" ";
            head = head->next;
        }
        cout<<endl;
    }
}

linkedList* reverse(linkedList *head)
{
    linkedList *prev = NULL, *next = NULL, *curr = head;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main()
{
    for(int i=1; i<=10; i++)
    {
        insertNode(head1, i);
    }
    
    cout<<"Before reversing: \n";
    display(head1);

    head1 = reverse(head1);
    
    cout<<"After reversing: \n";
    display(head1);
    
    return 0;
}