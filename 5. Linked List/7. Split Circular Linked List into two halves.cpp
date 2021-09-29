void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    Node *slow = head;
    Node *fast = head;
    
    //when there are only two nodes
    if(slow->next->next == head)
    {
        *head1_ref = slow;
        (*head1_ref)->next = *head1_ref;
        *head2_ref = slow->next;
        (*head2_ref)->next = *head2_ref;
    }
    
    /*affter below while loop slow pointer will be at last node of first split.
    when elements are odd 1st will have one extra node and slow pointer will
    be pointing to it i.e last element of 1st split. when elements are even then 
    1st and 2nd split will have same number of nodes and slow pointer will be pointing 
    to last node of 1st split.*/ 

    while(fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    //move fast to last node of list
    while(fast->next != head)
    {
        fast = fast->next;
    }
    
    *head1_ref = head;
    *head2_ref = slow->next;
    slow->next = *head1_ref;
    fast->next = *head2_ref;
    
}