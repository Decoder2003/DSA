#include <iostream>
using namespace std;

class ListNode{
    public:
        int val;
        ListNode* prev;
        ListNode* next;
};

void display(ListNode* head, int size){
    int index = 1;
    while(head!=NULL){
        cout << head->val << " "; 
        if(size==index){
            cout << endl;
            cout << head->val << " "; 
            index++;
            head = head->prev;
        }
        else if(size<index){
            head = head->prev;
        }
        else{
            head = head->next;
            index++;
        }
    }cout << endl;
}


int main(){
    int n;
    cin >> n;
    int size = n;
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
            newNode->prev = tail;
            tail = newNode;
        }
        n--;
    }
    display(head,size);
    return 0;
}