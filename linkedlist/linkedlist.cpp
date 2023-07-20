#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void display(Node* head){
    while( head != NULL ){
        cout << head->data << " ";
        head = head->next;
    }cout<<endl;
}

void insertAtFront(Node** head, int value){
    Node* node = new Node();
    node->data = value;
    node->next = *head;
    *head = node;
    // return head;
}

void insertAtLast(Node* head, int value){
    Node* node = new Node();
    node->data = value;
    node->next = NULL;
    while(head!=NULL){
        if(head->next==NULL){
            head->next = node;
            break;
        }
        head = head->next;
    }
}

void insertAtAnyPosition(Node* head, int value, int position){
    Node* node = new Node();
    node->data = value;
    while(head!=NULL){
        if (head->data == position){
            node->next = head->next;
            head->next = node;
        }
        head = head->next;
    }
}

void delAtFront(Node** head){
    *head = (*head)->next;
}

void delAtLast(Node** head){
    while( (*head)->next->next !=NULL){
        cout << (*head)->next << " ";
        cout << (*head) << " ";
        head = head->next;
    }cout<<endl;
}

int main(){
    Node* head;
    Node* one = new Node();
    Node* two = new Node();
    Node* three = new Node();

    // head
    head = one;

    // node 1
    one->data = 10;
    one->next = two;

    // node 2
    two->data = 12;
    two->next = three;

    // node 3
    three->data = 13;
    three->next = NULL;

    cout << "Orginal linked list : ";
    display(head);

    int value;
    // cout << "Enter data to be inserted at front : ";
    // cin >> value;
    // insertAtFront(&head,value);

    // cout << "Enter data to be inserted at last : ";
    // cin >> value;
    // insertAtLast(head,value);

    // int position;
    // cout << "Enter data and postion : ";
    // cin >> value >> position;
    // insertAtAnyPosition(head,value,position);

    // cout << "Deleting first value...";
    // delAtFront(&head);

    cout << "Deleting last value....";
    delAtLast(&head);

    cout << "Resultant linked list : ";
    display(head);
    return 0;
}