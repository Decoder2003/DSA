#include <iostream>
using namespace std;

class ListNode{
    public:
        int val;
        ListNode* next;
};

void display(ListNode* head){
    while(head!=NULL){
        cout << head->val << " ";
        head = head->next;
    }cout << endl;
}

ListNode* reverseList(ListNode* head) {
    ListNode* newHead = NULL;
    ListNode* tail = new ListNode();
    while(head!=NULL){
        ListNode* newNode = new ListNode();
        if(newHead==NULL){
            tail->val = head->val;
            newHead = tail;
        }
        else{
            newNode->next = tail;
            newNode->val = head->val;
            newHead = newNode;
            tail = newNode;
        }
        head = head->next;
    }
    return newHead;
}

int main(){
    int n;
    cin >> n;
    ListNode* head = NULL;
    ListNode* tail = NULL;
    while(n>0){
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
        n--;
    }
    head = reverseList(head);
    display(head);
    return 0;
}