#include<bits/stdc++.h>

using namespace std;

struct Node{
    Node *prev;
    int data;
    Node *next;
};

class Linked_List{

private:
    Node *head,*tail;

public:
    Linked_List(){
        head = NULL;
        tail = NULL;
    }

    void add_Node(int data);

    void printList();

    void deleteAtPos(int pos);

    int countNode();

    void reverseList();
};

void Linked_List::add_Node(int data){

    Node *t = new Node();
    t->data = data;

    if(head == NULL){
        head = t;
        tail = t;
        head->prev = NULL;
        head->next = NULL;
    }

    else{
        tail->next = t;
        t->prev = tail;
        tail = t;
        tail->next = NULL;
    }
}

void Linked_List::printList(){

    Node *temp = head;
    cout<<temp<<endl;
    while(temp){
        cout<<temp->prev<<" "<<temp->data<<" "<<temp->next<<endl;
        temp = temp->next;
    }
    cout<<tail<<endl;    
}

int Linked_List::countNode(){

    int count = 0;
    Node *temp = head;
    while(temp){
        count++;
        temp =temp->next;
    }
    return count;
}
//Note All operations you done in singly linked list are also applied here
void Linked_List::deleteAtPos(int pos){
    
    int x;
    int count = countNode();
    Node *cur = head;
    if(head == NULL){
        cout<<"List is Empty"<<endl;
        return;
    }

    else if(pos == 1){
        
        if(head->next){
            head->next->prev = NULL;
        }
        
        head = head->next;
        x = cur->data;
        cout<<"Deleted Node Data "<<x<<endl;
        if(!head)
            tail = NULL;

        delete cur;
    }

    else if(count >= pos && pos > 1){
        pos = pos-1;
        while(pos--){
            cur = cur->next;
        }

        if(cur->next)
            cur->next->prev = cur->prev;
        
        else
            tail = cur->prev;
        
        cur->prev->next = cur->next;
        x = cur->data;
        cout<<"Deleted Node Data "<<x<<endl;
        delete cur;
    }
}  

void Linked_List::reverseList(){

    Node* prevp = NULL;
    Node* cur = head;
    Node* next;

    while(cur){
        next = cur->next;
        cur->prev = next;
        cur->next = prevp;
        prevp = cur;
        cur = next;
    }

    tail = head;
    head = prevp;
}

int main(){

    Linked_List ll;
    ll.add_Node(2);
    ll.add_Node(3);
    ll.add_Node(5);
    ll.add_Node(7);

    cout<<ll.countNode()<<endl;
    ll.printList();

    // ll.deleteAtPos(3);
    // ll.deleteAtPos(1);
    // ll.deleteAtPos(1);
    // ll.deleteAtPos(1);
    // ll.deleteAtPos(4);
    ll.reverseList();
    ll.reverseList();
    cout<<ll.countNode()<<endl;
    ll.printList();
}