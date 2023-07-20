int getDecimalValue(ListNode* head) {
        int power = 0;
        ListNode* newHead = head;
        while(newHead!=NULL){
            power++;
            newHead = newHead->next;
        }
        int value = 0;
        while(head!=NULL){
            value += pow(2,power-1)*(head->val);
            power--;
            head = head->next;
        }
        return value;
    }