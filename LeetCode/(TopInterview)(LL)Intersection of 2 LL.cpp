//One Approach is to calculate lengths of both LL and then traverse.

//Another Approach: If null move to head of another list.

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*a=headA;
        ListNode*b=headB;
        
        while(a!=b)
        {
            a=a?a->next:headB;
            b=b?b->next:headA;
            
        }
        
        return a;
    }
