class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head->next == NULL) {return head;}
        if(head->next->next == NULL) {return head->next;}
        
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != NULL && fast->next->next != NULL)
        {  
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast->next != NULL)
            return slow->next;
        else
            return slow;
    }
};