#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* reverse(Node *head)
    {
    if(head == NULL || head->next == NULL)
        return head;

    Node *head_new = reverse(head->next);
    head->next->next = head;

    head->next = NULL;

    return head_new;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        int sum=0, carry = 0;
        Node *head = NULL;
        Node *temp = NULL;
        Node *new_node;
        first = reverse(first);
        second = reverse(second);
    
        while(first != NULL || second != NULL)
        {
            sum = carry + (first ? first->data:0) + (second ? second->data:0);
            carry = sum/10;
            sum = sum % 10;
        
            new_node = new Node(sum);
        
            if(head == NULL)
            {
                head = new_node;
            }
            else
            {
                temp->next = new_node;
            }

            temp = new_node;
        
            if(first)
            {
                first = first->next;
            }
        
            if(second)
            {
                second = second->next;
            }
        }
        if(carry>0)
        {
            new_node = new Node(carry);
            temp->next = new_node;
            temp = new_node;
        }

        head = reverse(head);
        return head;
    }
};


int main()
{
    int n, m;
    cin>>n;
    Node* first = buildList(n);
    cin>>m;
    Node* second = buildList(m);
    Solution ob;
    Node* res = ob.addTwoLists(first,second);
    printList(res);
    return 0;
}