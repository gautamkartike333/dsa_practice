
Steps- odd ko odd pe rakho and even ko even pe , then link change karo and movie karwao dono ko....



 ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        
        ListNode* first=head;
        ListNode* second=head->next;
        ListNode* second2=head->next;
        
        while(second!=NULL && second->next!=NULL){
            first->next=first->next->next;
            second->next=second->next->next;
            second=second->next;
            first=first->next;
        }
        first->next=second2;
        return head;
    }