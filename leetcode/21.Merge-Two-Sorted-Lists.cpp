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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head = NULL;
    ListNode* tail = NULL;
    while(list1!=NULL && list2!=NULL){
        ListNode* newNode1 = new ListNode();
        ListNode* newNode2 = new ListNode();
        if(head==NULL){
            if( list1->val < list2->val ){
                newNode1->val = list1->val;
                tail = newNode1;
                head = newNode1;
                list1 = list1->next;
            }
            else{
                newNode1->val = list2->val;
                tail = newNode1;
                head = newNode1;
                list2 = list2->next;
            }
        }
        else if( list1->val < list2->val ){
            newNode1->val = list1->val;
            tail->next = newNode1;
            tail = newNode1;
            list1 = list1->next;
        }
        else{
            newNode1->val = list2->val;
            tail->next = newNode1;
            tail = newNode1;
            list2 = list2->next;
        }
    }
    while(list1!=NULL){
        if(tail != NULL){
            tail->next = list1;
        }
        else if(tail == NULL){
            head = list1;
        }
        tail = list1;
        list1 = list1->next;
    }
    while(list2!=NULL){
        if(tail != NULL){
            tail->next = list2;
        }
        else if(tail == NULL){
            head = list2;
        }
        tail = list2;
        list2 = list2->next;
    }
    return head;
}

int main(){
    int n1;
    cin >> n1;
    ListNode* list1 = NULL;
    ListNode* tail = NULL;
    while(n1>0){
        ListNode* newNode = new ListNode();
        cin >> newNode->val;
        if(list1==NULL){
            list1 = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        n1--;
    }
    int n2;
    cin >> n2;
    ListNode* list2 = NULL;
    tail = NULL;
    while(n2>0){
        ListNode* newNode = new ListNode();
        cin >> newNode->val;
        if(list2==NULL){
            list2 = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        n2--;
    }

    ListNode* answer = mergeTwoLists(list1,list2);
    display(answer);
    return 0;
}