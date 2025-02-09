Prob Link: "https://leetcode.com/problems/reverse-nodes-in-k-group/description/"



Hint: k size ka grp reverse karte jao aage jodte jao , and so on....







































CODE:-

        class Solution {
            public:
                ListNode* reversell(ListNode* head){
                    ListNode* temp=head;
                    ListNode* prev=nullptr;
                    while(temp){
                        ListNode* fr=temp->next;
                        temp->next=prev;
                        prev=temp;
                        temp=fr;
                    }
                    
                    return prev;
                }
                ListNode* reverseKGroup(ListNode* head, int k) {
                    ListNode* temp=head;
                    ListNode* prevnode=NULL;
                    ListNode* kthNode=head;
                    while(temp){
                        int x=k;
                        kthNode=temp;
                        while(kthNode && --x)kthNode=kthNode->next;
            
                        if(kthNode==nullptr)break;
                        
                        ListNode* nextNode=kthNode->next;
                        kthNode->next=nullptr;
                        
                        ListNode* nhead= reversell(temp);
                        if(head==temp)head=nhead;
                        temp->next=nextNode;
                        if(prevnode)prevnode->next=kthNode;
                        prevnode=temp;
                        temp=temp->next;
                    }
                    return head;
                }
        };