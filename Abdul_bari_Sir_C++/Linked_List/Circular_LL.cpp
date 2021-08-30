//Note All operations you done in singly linked list are also applied here
#include<bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    Node *next;
};

class Linked_List{

public:
    Node *head;
    Node *tail;

public:
    Linked_List(){
        head = NULL;
        tail = NULL;
    }

    void add_Node(int data);

    int countNode();

    void printList();

    void deleteAtPos(int pos);

    void reverseList();

};

void Linked_List::add_Node(int data){

    Node *t = new Node();
    t->data = data;

    if(head == NULL){
        head = t;
        tail = t;
        tail->next = head;
    }

    else{
        tail->next = t;
        tail = t;
        t->next = head;
    }
}

int Linked_List::countNode(){

    int count = 0;
    Node *temp = head;

    if(head != NULL){
        do{
            count++;
            temp =temp->next;
        }while(temp != head);
    
    }
    return count;
}

void Linked_List::printList(){

    Node *temp = head;
    cout<<temp<<endl;
    if(head != NULL){
        do{
            cout<<temp->data<<" "<<temp->next<<endl;
            temp =temp->next;
        }while(temp != head);
    }
    cout<<tail<<endl;
}

void Linked_List::deleteAtPos(int pos){
    
    int x,postemp = pos;
    int count = countNode();
    Node *prev = NULL;
    Node *cur = head;
    if(head == NULL){
        cout<<"List is Empty"<<endl;
        return;
    }

    else if(pos == 1){
                
        tail->next = head->next;
        x = head->data;
        cout<<"Deleted Node Data "<<x<<endl;
        if(head->next != head)
            head = head->next;
        
        else{
            head = NULL;
            tail = NULL;
        } 
        delete cur;
    }

    else if(count >= pos && pos > 1){
        pos = pos-1;
        while(pos--){
            prev = cur;
            cur = cur->next;
        }

        prev->next = cur->next;
        x = cur->data;
        cout<<"Deleted Node Data "<<x<<endl;
        if(count == postemp)
            tail = prev;
        
        delete cur;
    }
}  

void Linked_List::reverseList(){

    Node *prev = tail;
    Node *cur = head;
    Node *next;

    if(head == NULL && cur->next != head && tail == NULL){
        cout<<"List is empty or only single Node is there"<<endl;
        return;
    }

    do{
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }while(cur != head);
     
    tail = head;
    head = prev;
    //Wrong approach
    //tail = head->next;
}

int main(){

    Linked_List ll;
    ll.add_Node(12);
    ll.add_Node(15);
    ll.add_Node(17);
    ll.add_Node(19);
    ll.add_Node(23);
    ll.add_Node(29);
    ll.add_Node(31);

    cout<<ll.countNode()<<endl;
    ll.printList();
    // ll.deleteAtPos(7);
    // ll.deleteAtPos(2);
    // ll.deleteAtPos(5);
    // ll.deleteAtPos(1);
    // ll.deleteAtPos(1);
    // ll.deleteAtPos(1);
    // ll.deleteAtPos(1);
    // ll.deleteAtPos(1);
    // ll.deleteAtPos(1);

    ll.reverseList();
    ll.reverseList();
    cout<<ll.countNode()<<endl;
    ll.printList();

    return 0;
}