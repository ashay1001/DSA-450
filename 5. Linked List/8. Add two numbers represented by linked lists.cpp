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