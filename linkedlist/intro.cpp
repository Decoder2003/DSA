#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    void display(){
        cout << "data : " << data << endl; 
    }
    Node(int x){
        data = x;
    }
};

int main(){
    // Node linkedlistNode(10);
    Node* linkedlistNode = new Node();
    linkedlistNode->display();
    return 0;
}