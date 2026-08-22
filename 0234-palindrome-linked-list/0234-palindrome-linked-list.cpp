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
 ListNode* getMid(ListNode* head)
 {
    ListNode* slow=head;
    ListNode* fast= slow->next;
    while(fast!=NULL && fast->next!=NULL )
    {
        slow=slow->next;
        fast=fast->next->next;
    }
return slow;

 }

 ListNode* reverse(ListNode* head)
 {
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* frd=NULL;

    while(curr!=NULL)
    {  //intialse frd
    frd=curr->next;

    curr->next=prev;
      
        prev=curr;
        curr=frd;
    }
    return prev;

 }

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
        return true;
        ListNode* mid=getMid(head);

        //reverse
        ListNode* temp= mid->next;
        mid->next= reverse(temp);

        //compare
        ListNode* head1=head;
        ListNode* head2=mid->next;

        while(head2!=NULL)
        {
            if(head1->val!=head2->val)
            return false;

            head1=head1->next;
            head2=head2->next;

        }

        //repeat step 2
       temp= mid->next;
        mid->next= reverse(temp);


        return true;

        
    }
};