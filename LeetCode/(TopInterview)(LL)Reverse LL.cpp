 //For recursive method:
 
    ListNode*revList(ListNode*head,ListNode *prev)
    {
        if(!head)
            return prev;
        
        ListNode *nxt=head->next;
        head->next=prev;      
        return revList(nxt,head);
    }
    
    ListNode* reverseList(ListNode* head) {
    
        // For Recursive Method:
        return revList(head,NULL);      
      }

//Iterative:

  ListNode* reverseList(ListNode* head) {
    
        // For Recursive Method:
        return revList(head,NULL);
        
        if(!head)
             return NULL;
        
        if(!head||!head->next)
            return head;
        
        ListNode*curr=head,*prev=head,*nxt;
        curr=curr->next;
            nxt=curr->next;

        while(curr&&curr->next)
        {
            curr->next=prev;
            prev=curr;
            curr=nxt;
            nxt=curr->next;
        }
        curr->next=prev;
        prev=curr;
       head->next=NULL;
        // return prev;
        

    }
