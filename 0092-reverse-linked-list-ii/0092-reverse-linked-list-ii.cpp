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
class Solution {
    private:
    ListNode* rev(ListNode* head)
    {
         ListNode* prev=NULL;
        ListNode* frwd=NULL;
        ListNode* curr=head;

        while(curr!=NULL)
        {
            frwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=frwd;
        }

       return prev; 

    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
       ListNode* temp=head;
       ListNode* prev=NULL;
       int cnt=1;
       while(cnt<left && temp!=NULL)
       {
        prev=temp;
        temp=temp->next;
        cnt++;
       }
        
        ListNode* start=temp;
         // Cut the list before 'left'
        if(prev != NULL)
            prev->next = NULL;

      
        
       
        while(cnt<right && temp!=NULL)
        { 
            temp=temp->next;
            cnt++;
        }
      ListNode* pr=temp->next;
      ListNode* end=temp;
       end->next=NULL;

        start=rev(start);
       
       ListNode* temp2=start;
       // Reconnect
        if(prev != NULL)
        {
            // left > 1
            prev->next = start;
        }
        else
        {
            // left == 1
            head = start;
        }

       while(temp2->next!=NULL)
       {
        temp2=temp2->next;

       }
       temp2->next=pr;


        return head;


    }
};
