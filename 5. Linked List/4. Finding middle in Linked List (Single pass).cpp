#include <bits/stdc++.h>
using namespace std;

int check()
{
	#ifndef ONLINE_JUDE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w",stdout);
	#endif
}

struct node
{
    node* next;
    int data;
};

node* head = NULL;

void appendNode(int n)
{
    if(head == NULL)
    {
        node* temp = new node();
        temp->data = n;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        node* temp = head;
        while(temp->next)
        {
            temp = temp->next;
        }
        node* t = new node();
        temp->next = t;
        t->data = n;
    }
}

void display()
{
    node* temp = head;
    while(temp->next)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}

void getMiddle()
{
    node* fast = head;
    node* slow = head;
    while(fast->next != NULL)
    {  
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<"Middle Element: "<<slow->data;
}

int main()
{   
    check();
    for(int i=1; i<=15; i++)
    {
        appendNode(i);
    }
    display();
    getMiddle();

    return 0;
}