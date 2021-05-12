  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
       ListNode start(0);
        ListNode*temp=&start;

        ListNode*begin=&start;
        while(l1&&l2)
        {
            
        if(l1->val>l2->val)
        {
            temp->next=l2;
            l2=l2->next;
        }
        else
        {
            temp->next=l1;
            l1=l1->next;
        }
        temp=temp->next;
        }
        
       temp->next=l1?l1:l2;
        return begin->next;
    }
