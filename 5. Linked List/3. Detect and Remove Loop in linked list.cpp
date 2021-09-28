class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node *slow_p = head, *fast_p = head;
 
        while (slow_p && fast_p && fast_p->next) 
        {
            
            slow_p = slow_p->next;
            fast_p = fast_p->next->next;
            if (slow_p == fast_p) {
                remove(slow_p, head);
            }
        }

    }
    
    void remove(Node *loop_node, Node *head)
    {
        struct Node* ptr1 = loop_node;
        struct Node* ptr2 = loop_node;
        
        int count = 1; //count the number of nodes in loop
        while(ptr1->next != ptr2)
        {
            ptr1 = ptr1->next;
            count++;
        }
        
        ptr1 = head;
        ptr2 = head;
        for(int i=0; i<count; i++)
        {
            ptr2 = ptr2->next;
        }
        
        while(ptr1 != ptr2)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        while(ptr1 != ptr2->next)
        {
            ptr2 = ptr2->next;
        }
        ptr2->next = NULL;
    }
};