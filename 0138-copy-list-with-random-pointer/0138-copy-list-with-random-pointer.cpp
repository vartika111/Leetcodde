/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    private:
    void insertAtTail(Node* &head,Node* &tail,int data)
    {   Node* newNode= new Node(data);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;

        }
        else
        {
            tail->next=newNode;
            tail=newNode;
        }
    }
public:
    Node* copyRandomList(Node* head) {

        //step1 : create a clone list
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
         Node* temp=head;
         while(temp!=NULL)
         {
            int data=temp->val;
            insertAtTail(cloneHead,cloneTail,data);
            temp=temp->next;
         }

         //step 2: add cloneNode in between orinalNOde
         Node* originalNode=head;
         Node* cloneNode=cloneHead;
         while(cloneNode!=NULL&& originalNode!=NULL)
         {
            Node* next = originalNode->next; //saving next of orginal
            originalNode->next=cloneNode;   // changing next of origi
            originalNode=next;              // update origi

            next=cloneNode->next;     //down arrow, cloneNode next is saved
            cloneNode->next=originalNode;  // update cloneNodes next to updated Orignal Node , triangle is formed
            cloneNode=next;  //update cloneNode


 

         }



        
        //step3  copy random pointer
        temp=head;
        while(temp!=NULL)
        {
            if(temp->next!=NULL)
            {
                temp->next->random=temp->random? temp->random->next:temp->random;
            }
            temp=temp->next->next;
        }



        //step4  revertt step 2  remove digonal links
        originalNode=head;
        cloneNode=cloneHead;
         while(cloneNode!=NULL&& originalNode!=NULL)
         {
            originalNode->next= cloneNode->next;
            originalNode=originalNode->next;

            if(originalNode!=NULL)
            {
                cloneNode->next=originalNode->next;

            }
            cloneNode=cloneNode->next;

         }


         //step5: return head
         return cloneHead;



    }
};