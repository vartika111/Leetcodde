/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 ListNode* intersect(ListNode* head)
 {
    if(head==NULL)
    return NULL;

    ListNode* slow=head;
    ListNode* fast=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
        return slow;
    }
 return NULL;

 }
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      

        if(head==NULL)
        return NULL;

          ListNode*intp=intersect(head);

           // No cycle
        if(intp == NULL)
            return NULL;
            
          ListNode* slow=head;
        
          while(slow!=intp)
          {
            slow=slow->next;
            intp=intp->next;
          }

          return slow;

        
    }
};