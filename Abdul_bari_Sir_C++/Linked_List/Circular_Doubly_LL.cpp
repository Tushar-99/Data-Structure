//Note All operations you done in singly linked list are also applied here
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

    int countNode();

    void deleteAtPos(int pos);

    void reverseList();
};

void Linked_List::add_Node(int data){

    Node *t = new Node();
    t->data = data;

    if(head == NULL){
        head = t;
        tail = t;
        head->prev = head;
        head->next = head;
    }

    else{
        tail->next = t;
        t->prev = tail;
        tail = t;
        head->prev = tail;
        tail->next = head;
    }

    // head->prev = tail->next;
    // tail->next = head;
}

void Linked_List::printList(){

    Node *temp = head;

    cout<<temp<<endl;
    if(temp){
        do{
            cout<<temp->prev<<" "<<temp->data<<" "<<temp->next<<endl;
            temp = temp->next;
        }while(temp != head);
    }
    cout<<tail<<endl;
}

int Linked_List::countNode(){

    int count = 0;
    Node *temp = head;

    if(temp){
        do{
            count++;
            temp =temp->next;
        }while(temp != head);
    }
    return count;
}

void Linked_List::deleteAtPos(int pos){
    
    int x;
    int count = countNode();
    Node *cur = head;
    if(head == NULL){
        cout<<"List is Empty"<<endl;
        return;
    }

    else if(pos == 1){
        
        if(head->next != head){
            head = head->next;
            head->prev = tail;
            tail->next = head;
        }

        else{
            head = NULL;
            tail = NULL;
        }

        x = cur->data;
        cout<<"Deleted Node Data "<<x<<endl;
        
        delete cur;
    }

    else if(count >= pos && pos > 1){
        pos = pos-1;
        
        while(pos--){
            cur = cur->next;
        }

        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;

        x = cur->data;
        
        cout<<"Deleted Node Data "<<x<<endl;
     
        delete cur;
    }
}  

void Linked_List::reverseList(){

    Node* prevp = tail;
    Node* cur = head;
    Node* next;

    if(head == NULL && head->next == head && tail == NULL){
        cout<<"List is Empty or only Single Node is there"<<endl;
        return;
    }

    do{
        next = cur->next;
        cur->prev = next;
        cur->next = prevp;
        prevp = cur;
        cur = next;
    }while(cur != head);

    head = prevp;
    tail = next;
}

int main(){

    Linked_List ll;
    ll.add_Node(2);
    ll.add_Node(3);
    ll.add_Node(5);
    ll.add_Node(7);
    cout<<ll.countNode()<<endl;
    ll.printList();

    // ll.deleteAtPos(1);
    // ll.deleteAtPos(2);
    // ll.deleteAtPos(1);
    // ll.deleteAtPos(1);
    // ll.deleteAtPos(1);
    ll.reverseList();
    ll.reverseList();
    cout<<ll.countNode()<<endl;
    ll.printList();
}