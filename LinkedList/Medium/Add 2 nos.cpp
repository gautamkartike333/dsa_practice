Prob Link :"https://leetcode.com/problems/add-two-numbers/description/"



Hint : are direct add akrdo and new node banake dusri linked list me save karte jao ..



































CODE:-

class Solution {
    public:
    
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
    
        ListNode* dNode =new ListNode(-1);
        ListNode* temp =dNode;
        int carry=0;
        while(temp1!=NULL || temp2!=NULL){
            int sum=carry;
            int rem;
            if(temp1) sum += temp1->val;
            if(temp2) sum += temp2->val;
            carry=sum/10;
            ListNode* newnode = new ListNode(sum%10);
            temp->next = newnode;
            temp=temp->next;
            if(temp1) temp1=temp1->next;
            if(temp2) temp2=temp2->next;
    
        }
        if(carry!=0){
            ListNode* newnode = new ListNode(carry);
            temp->next = newnode;
    
        }
        return dNode->next;
    
        }
    };