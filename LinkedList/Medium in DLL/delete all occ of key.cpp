Prob Link: "https://www.naukri.com/code360/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list_8160461?leftPanelTabValue=PROBLEM"


Hint-1: Bahut easy hai karlo 
Hint-2: jaha mila waha delete kardo uss node ko , and delete karna tum jaante ho kisi node ko 































CODE:
Node * deleteAllOccurrences(Node* head, int k) {
    // Write your code here
    Node* temp=head;

    while(temp){

        if(temp->data == k){
            if(temp==head)head=temp->next;
            Node* back=temp->prev;
            Node* fr=temp->next;
            if(back)back->next=fr;
            if(fr)fr->prev=back;
            delete(temp);
            temp=fr;
        }
        else temp=temp->next;

    }

    return head;
}
