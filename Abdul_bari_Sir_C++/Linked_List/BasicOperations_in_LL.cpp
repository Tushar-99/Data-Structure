#include<bits/stdc++.h>

using namespace std;

static int no = 0;

class Node{

private:
    int data;
    Node *next;//self referencial pointer

public:
    Node(){
        data = 0;
        next = NULL;
    }

    void createList(int element);

    void create_LL(int);

    void display();
    
    friend void dispRec(Node *n);

    int countNode();

    friend int countNodeRec(Node *n);

    int sumLL();

    friend int sumLLRec(Node *n);

    friend int maxList(Node *n);

    friend int maxListRec(Node *n);

    friend int minListRec(Node *n);

    friend int minList(Node *n);

    friend Node* searchList(Node *n,int key);

    friend Node* searchListRec(Node *n,int key);

    friend Node* searchImproved(Node *head,int key);

    friend Node* binSearchLL(Node *n,int ele);

    ~Node(){
        delete next;
    }
}*first = NULL , *tail = NULL;//it can be directly accessed here first pointer is global

void Node::createList(int element){

    Node *node = new Node();
    node->next = NULL;
    node->data = element;
    if(first == NULL){
        first = node;
        tail = node;
    }
    else{
        tail->next = node;
        tail = node;
    }
    //first->next = NULL;
}

void Node::create_LL(int n){

    if(n == 0 || this == NULL){
        return;
    }

    int i;
    Node *LL,*last;
    //here last is like reference node which helps us in track of linked list here issue is that if we doesn't take this last node then we have to change head node for insertion of next node due to this our Linked list head or starting point changed so reference node help us overcome this issue we use reference node last to track the list and at the end it refer to last node of linked list such that we now change last node next reference.
    
    cout<<"Enter data"<<endl;
    cin>>this->data;
    //this->next = NULL;
    last = this;
    no++;
    for(i = 1 ; i < n ; i++){
        LL = new Node();
        cin>>LL->data;
        last->next = LL;
        last = LL;
        //LL->next = NULL;
        no++;
    }
}

void Node::display(){

    int i;
    Node *temp ;
    //cout << no <<endl;
    // if(this == NULL || no == 0){
    //     return;
    // }

    if(this == NULL){
        return;
    }

    else{
        cout<<this->data<<" ";
        temp = this->next;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    cout<<endl;
}

void dispRec(Node *n){

    // if(n != NULL){
    //     cout<<n->data<<" ";
    //     dispRec(n->next);
    //     cout<<n->data<<" ";
    // }

    if(n == NULL || no == 0)
        return;

    else{
        cout<<n->data<<" ";
        dispRec(n->next);
        cout<<n->data<<" ";
    }
}

int Node::countNode(){

    int i,count = 0;
    // if(this == NULL)
    //     return 0;

    Node *last;
    last = this;
    while(last != NULL){
        count++;
        last = last->next;
    }
    return count;   
}

int countNodeRec(Node *head){

    // int count = 0;
    // if(head != NULL){
        //count++;//incorrect gives 0 as a result
        //in wrong scenario during calling time count flow like 0 1 , 0 1 upto 5 times
        //in wrong scenario during returning time count flow like 1 0 , 1 0 upto 5 times
        //++count = countNodeRec(head->next);-->bej=haves as head recursion
        //count++ not aloowed here but ++count allowed i.e. count++ = countNodeRec(head->next);(N.A.) , ++count = countNodeRec(head->next);(Allowed)
        //count++;

    //     count = countNodeRec(head->next);
    //     count++;
    // }
    
    // return count;

    // if(head != NULL)
    //     count = countNodeRec(head->next)+1;

    // return count;

    if(head == 0)
        return 0;

    else
        return countNodeRec(head->next)+1;
    
}

int Node::sumLL(){

    int sum = 0;
    Node *temp;
    temp = this;
    while(temp != NULL){
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

int sumLLRec(Node *head){
    
    int sum = 0;

    if(head != NULL){
        sum = head->data + sumLLRec(head->next); //+ head->data;
    }

    return sum;
}

int maxList(Node *n){

    if(n == NULL)
        return INT_MIN;
    
    int max = n->data;
    n = n->next;
    while(n){
        if(n->data > max)
            max = n->data;

        n = n->next;
    }
    return max;
}

int maxListRec(Node *n){

    int max = INT_MIN;
    if(n == NULL)
        return max;

    max = maxListRec(n->next);
    
    // if(n->data > max)
    //     return n->data;
    //         or
    //     max = n->data;
    
    return max < n->data ? n->data : max;
}


int minList(Node *n){

    int min = INT_MAX;
    while(n){
        if(min > n->data)
            min = n->data;
        
        n = n->next;
    }

    return min;
}

int minListRec(Node *n){

    int min = INT_MAX;
    if(n == NULL)
        return min;
    min = minListRec(n->next);
    //if(min > n->data)
        //return n->data;
            //or
        //min = n->data;

    //return min;
    return min > n->data ? n->data : min;
}

Node* searchList(Node *n,int ele){

    // if(n == NULL)
    //     return INT_MIN;
    int count = 0;
    while(n){
        if(n->data == ele){
            return n;
        }
        n = n->next;
        count++;
    }
    return NULL;
}

Node* searchListRec(Node *n,int key){

    if(n == NULL)
        return NULL;

    if(n->data == key)
        return n;

    return searchListRec(n->next,key);
}

Node* searchImproved(Node *head,int key){

    // Node* temp = head;
    // Node* dojo = NULL;
    Node* q = NULL;
    Node* first = head; 
    while(first){

        if(first->data == key){
        //Wrong approach because starting pointer get disturbed
            //dojo = temp; 
            // head = temp;
            // temp = temp->next;
            // temp->next = head;
            // return head;

            // temp->next = head;
            // head = temp;
            // temp = temp->next;
            // return temp;
            // q->next = first->next;
            // first->next = first;
            // first = n;
            return first;
        }
        q = first;
        first = first->next;
    }
    return NULL;
}

// Node* binSearchLL(Node *n,int ele){

//     int low = 0;
//     int high = countNodeRec(n);
//     int mid = low+(high-low)/2; 

//     while(low <= high){
//         int mid = low+(high-low)/2;

//     }       
// }

int main(){

    // int n;
    // Node *head = new Node();
    // cout<<"How many Nodes u required in Linked list";
    // cin>>n; 
    // (*head).create_LL(n);
    // //(*head).display();
    // dispRec(head);
    // cout<<endl;
    //cout<<(*head).countNode()<<endl;
    //cout<<countNodeRec(head)<<endl;
    //cout<<(*head).sumLL()<<endl;
    //cout<<sumLLRec(head)<<endl;
    //cout<<maxList(head)<<endl;
    //cout<<maxListRec(head)<<endl;
    // int ele;
    // cin>>ele;
    // cout<<searchList(head,ele)<<endl;
    //cout<<minList(head)<<endl;
    //cout<<minListRec(head)<<endl;
    //cout<<searchListRec(head,ele);
    // int test;
    // do{
    //     cout<<searchImproved(head,ele)<<endl;
    //     cin>>test;

    // }while(test);


//     first->createList(1);
//     first->createList(2);
//     first->createList(3);
//     first->createList(4);
//     first->createList(5);

//     first->display();

    first->createList(1);
    first->createList(2);
    first->createList(3);
    first->createList(4);

    first->display();
}