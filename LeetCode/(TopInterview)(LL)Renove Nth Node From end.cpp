 ListNode* removeNthFromEnd(ListNode* head, int n) {
              
        ListNode*start=head;
        ListNode*end=head;
    
        ListNode*prev=head;

        for(int i=0;i<n;i++)
            start=start->next;        
        
        if(!start)
                return head->next;
   
        while(start&&start->next)
        {
            start=start->next;
            prev=prev->next;
        }
        
        end=prev->next;
        
        prev->next=prev->next->next;
        
        delete(end);
        
        return head;
            
    }
