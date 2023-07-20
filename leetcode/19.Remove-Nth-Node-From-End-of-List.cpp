#include <iostream>
using namespace std;

class ListNode{
    public:
        int val;
        ListNode* next;
};

ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode* newHead = head;
    int size = 0;
    while(newHead!=NULL){
        size++;
        newHead = newHead->next;
    }
    newHead = head;
    int indexNeed = size - n;
    int index = 1;
    while(newHead!=NULL){
        if(index==indexNeed){
            newHead->next = newHead->next->next;
            break;
        }
        else if (indexNeed==0){
            head = head->next;
            return head;
        }
        index++;
        newHead = newHead->next;
    }
    return head;
}

void display(ListNode* head){
    while( head != NULL ){
        cout << head->val << " ";
        head = head->next;
    }cout<<endl;
}

int main(){
    int t;
    cin >> t;
    ListNode* head = NULL;
    ListNode* tail = NULL;
    while(t>0){
        ListNode* newNode = new ListNode();
        cin >> newNode->val;
        if(head==NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        t--;
    }
    int n;
    cin >> n;
    head = removeNthFromEnd(head,n);
    display(head);
    return 0;
}