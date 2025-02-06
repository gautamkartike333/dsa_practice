

Steps:-
    step-1- find mid
    step-2- reverse
    step-3- comparing
    step-4- dont forgot to again reverse as we should not alter ll .

CODE-:

    ListNode* revll(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        
        while(curr!=NULL){
            ListNode* front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)return true;
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* newhead = revll(slow->next);
        ListNode* first=head;
        ListNode* second=newhead;
        
        while(second!=NULL){
            if(first->val != second->val)return false;
            
            first=first->next;
            second=second->next;
        }

        return true;}