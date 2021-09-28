#include <bits/stdc++.h>
#include <climits>
using namespace std;

struct linkedList
{
    int data;
    linkedList *next;
};
struct linkedList *head1 = NULL;

int check()
{
	#ifndef ONLINE_JUDE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w",stdout);
	#endif
}

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
    if(head == NULL || head->next == NULL)
        return head;

    linkedList *head_new = reverse(head->next);
    head->next->next = head;

    head->next = NULL;

    return head_new;
}

int main()
{
    for(int i=0; i<4; i++)
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