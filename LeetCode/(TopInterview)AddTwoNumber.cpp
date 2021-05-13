/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//Number represented in inked list in reverse order already,
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        
        
        if(!l1)
                return l2;
        if(!l2)
            return l1;
        ListNode* start=new ListNode(0);
        
        ListNode*temp1=l1,*temp2=l2,*begin=start;
        
        while(temp1->next)
        {
            if(!temp2->next)
            {
                
                ListNode* temp=new ListNode(0);
                temp2->next=temp;
                                
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        while(temp2->next)
        {
            if(!temp1->next)
            {
                
                ListNode* temp=new ListNode(0);
                temp1->next=temp;
                                
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        
        int carry=0;
        
        temp1=l1;
        temp2=l2;
        
        while(temp1)
        {
        int sum=temp1->val+temp2->val+carry;
            if(sum<=9)
            {  
                ListNode* temp=new ListNode(sum);
                begin->next=temp;
                begin=begin->next;
                carry=0;
            }
             else
            {
                int num=sum-10;
                ListNode* temp=new ListNode(num);
                begin->next=temp;
                begin=begin->next;
                 carry=1;
            }    
            temp1=temp1->next;
            temp2=temp2->next;
                

                    
        }

            if(carry==1)
            {
                  ListNode* temp=new ListNode(1);
                begin->next=temp;
                begin=begin->next;
               
            }
        
        begin=start;
        
        return begin->next;
    }
};
