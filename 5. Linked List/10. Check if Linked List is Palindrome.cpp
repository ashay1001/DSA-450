#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution{
  public:
    //Function to check whether the list is palindrome.
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
    bool isPalindrome(Node *head)
    {
        if(!head) {return false;}
        if(head->next == NULL) {return true;}
        if(head->next->next == NULL) 
        {
            if(head->data == head->next->data) return true;
            else return false;
        }
        Node *slow = head;
        Node *fast = head;
        Node *new_head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        new_head = reverse(slow->next);
        while(new_head != NULL)
        {
            if(head->data != new_head->data)
            {
                return false;
            }
            head = head->next; new_head = new_head->next;
        }
        return true;
    }
};

int main()
{
  int i,n,l,firstdata;
        
    struct Node *head = NULL,  *tail = NULL;
    cin>>n;
    // taking first data of LL
    cin>>firstdata;
    head = new Node(firstdata);
    tail = head;
    // taking remaining data of LL
    for(i=1;i<n;i++)
    {
        cin>>l;
        tail->next = new Node(l);
        tail = tail->next;
    }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    return 0;
}