#ifndef Chains_h
#define Chains_h

#include<bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    Node *next;

    Node()
    {
        data = INT_MIN;
        next = NULL;
    }
};

class Linked_List{

public:
    Node *head,*tail;

public:

    Linked_List(){
        head = NULL;
        tail = NULL;
    }

    void add_node(int n);

    void display();

    Node* search(int);

    Node* searchTrap(int);

    Node* searchImproved(int key);

    void insertNode(int pos,int key);

    void insertSort(int key);

    void deleteNode(int key);

    bool isListSorted();

    void insertPQ(int key);

    void findDuplicate();

    void reverseList();

    void recReverseList(Node *head);

    void reverseData();

    Linked_List concatList(Linked_List ll1,Linked_List ll2);

    Node* detectLoop();

    void detectLoopPro();

    int findMiddle();

    void intersectionList(Linked_List ll1);

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

    Node* minList(Node *n){

        int min = INT_MAX;
        Node *temp = NULL;
        while(n){
            if(min > n->data){
                min = n->data;
                temp = n;
            }
            n = n->next;
        }

        return temp;
    }

    Node* maxNode(Node *n){

        Node *temp;
        if(n == NULL)
            return NULL;

        int max = n->data;
        n = n->next;
        while(n){
            if(n->data > max){
                max = n->data;
                temp = n;
            }
            n = n->next;
        }
        return temp;
    }

    int countNode(){

        int count = 0;
        Node *temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }
};

//Insertion of node at the last of the list
void Linked_List::add_node(int n){

    Node *node = new Node;//we can create object of structure also
    node->data = n;
    node->next = NULL;
    //execute during first node creation
    if(head == NULL){
        head = node;
        tail = node;
    }
    else{
        tail->next = node; 
        tail = tail->next; // or node      
    }
}

void Linked_List::display(){

    Node* temp;
    temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
        cout<<temp<<endl;
    }    
}

//this doesn't work for first node i.e. for first node there may be error named segmentation fault (if q points to NULL) and infinnite loop (if q points to head/tail) and there no other option regarding q pointer because we doesnt have any idea
Node* Linked_List::search(int key){

    Node* temp;
    temp = head; 
    Node *q = head;  //segmentation core dump because q is NULL initailly if q points to head then there is one more problem that is it point to head again
    while(temp){

        if(temp->data == key){
            // q->next = temp->next; //segmentation core dump because q is NULL initailly
            // temp->next = head;
            // // cout<<head->next<<endl;
            // // cout<<ll1.head->next<<endl;
            // head = temp;

            return temp;
        }
        //q = temp;
        temp = temp->next;
    }
    return NULL;
}

Node* Linked_List::searchTrap(int key){
    
    Node *prev = head;
    Node *cur  = head->next;
    Node *next = head->next->next;
    //Node *temp = head->next;
    
    if(head == NULL || (head->next == NULL && head->data != key)){
        return NULL;
    }

    else if(head->data == key) 
        return head;

// truth table 
//   0  0 (here we doesn't omit first and last nodes checking/traversal)
//   Node *temp = head; while(temp)
//   0  1 (here we omit first node but doesn't omit last node checking/traversal)
//   Node *temp = head->next; while(temp)
//   1  0 (here we doesn't omit first node but omit last node checking/traversal)
//   Node *temp = head; while(temp->next)
//   1  1 (here we omit first and last both nodes checking/traversal)
//   Node *temp = head->next; while(temp->next)

//if we write while(next->next) then it doesn't check last node data
//here problem in swapping first and second node of linked list so it it commented
    // else if(cur->data = key){

    //     head->next = cur->next;
    //     cur->next = head;
    //     head = cur;

    //     return cur;
    // }

    else{
        
        while(next){
//in transposition jis bhi node ko aage lana hai us node ki prvious do node ka address hona chahiye        
            
            if(next->data == key){
            
                cur->next = next->next;
                next->next = cur;
                prev->next = next;

                //below approach is wrong
                // prev->next = cur->next;
                // cur->next = prev;
                // prev = cur;

                return next;
            }
            
            prev = cur;
            cur = cur->next;
            next = next->next;
        }
    }
    return NULL;
}
//This function is similar to move any node to the front or first node of the list
//Move to head
Node* Linked_List::searchImproved(int key){
//yaad rakhna thumb rule Linked list ki nodes ko swap karne ke liye hamesha prev node and current node and next node and first node and last node ka address hona chahiye kisi halat mae and kiska address us samay jarrori hai depend karta hai ki kis node ko swap krna hai     
    Linked_List ll1;
//Note dont think that u change dummy list it also changes main list in all condition no! dummy list is meant only for traversal for changing we have to take dummy node which store next,prev,cur node adresses ok 
    ll1.head = head->next;
    ll1.tail = tail;
    Node *temp = head; 
    
    if(head == NULL || (head->next == NULL && head->data != key)){
        return NULL;
    }
    
    if(head->data == key) 
        return head;
    
    while(ll1.head){
        if(ll1.head->data == key){
        
            temp->next = ll1.head->next;
            ll1.head->next = head;
            head = ll1.head;
            
            return head;
        }
            
        temp = ll1.head;
        ll1.head = ll1.head->next;
    }
        
    // if(ll1.head->data == key){
            
    //     //temp = ll1.head;
    //     ll1.head->next = head;
    //     head = temp->next;
    //     temp->next = NULL;
            
    //     return head;
    // }

    return NULL;
}

//Strictly care About segmentation fault
void Linked_List::insertNode(int pos,int key){

    Node *t = new Node();
    t->data = key;
    Node *p = head;
    t->next = NULL;
    // if(head == NULL){
    //     t->data = key;
    //     head = t;
    //     t->next = NULL;
    // }
        

    if(pos == 0){
        t->next = head;
        head = t;
    }

    else if(pos > 0){
        int i;
        for(i = 1 ;p && i < pos ; i++){
            p = p->next;
        }
        if(p){
            t->next = p->next;
            p->next = t;
        }
    }

    Node *temp = head;
    while(temp->next && pos >= 0){
        temp = temp->next;
    }
    if(!temp->next)
        tail = temp;
}

//Strictly care About segmentation fault
void Linked_List::insertSort(int key){

    Node *t = new Node();
    Node *p = head;
    Node *c = NULL;
    t->data = key;
    t->next = NULL;

    if(head == NULL){
        head = t;
    }   

    else if(p->data >= key){
        t->next = head;
        head  = t;
    }

    else {
        c = p;
        p = p->next;
        for(int i = 0 ; p && p->data < key ; i++){
            c = p;
            p = p->next;
        }

        t->next = c->next;
        c->next = t;
    }

    Node *max = maxNode(head);

    tail = max;
}

//Strictly care About segmentation fault
void Linked_List::deleteNode(int key)
{   
 
    int x;
    Node *prev = head;
    Node *temp = head->next;
    if(head == NULL){
        cout<<"List is Empty";
        return;
    }

    else if(head->data == key){
        head = head->next;
        x = head->data;
        delete prev;
    }
    else{
        while(temp && temp->data != key){
            prev = temp;
            temp = temp->next;
        }

        if(temp){
            prev->next = temp->next;
            x = temp->data;
            delete temp;
        }
    }
}

bool Linked_List::isListSorted(){

    Node *temp = head;
    if(head == NULL){
        cout<<"List is Empty"<<endl;
        return false;
    }
    else{

        while(temp->next && temp->data <= temp->next->data){
            temp = temp->next;
        }

        if(!temp->next)
            return true;
    }

    return false;
}

//Priority Queue
void Linked_List::insertPQ(int key){

    Node *t = new Node();
    Node *p = head;
    Node *c = NULL;
    t->data = key;
    t->next = NULL;

    if(head == NULL){
        head = t;
    }   

    else if(p->data < key){
        t->next = head;
        head  = t;
    }

    else {
        c = p;
        p = p->next;
        for(int i = 0 ; p && p->data >= key ; i++){
            c = p;
            p = p->next;
        }

        t->next = c->next;
        c->next = t;
    }

    Node *min = minList(head);

    tail = min;
}

//check duplicates in an array
void Linked_List::findDuplicate(){

    int i = 0;
    int max = maxList(head);
    int *A = new int[max+1]{0};
    Node *temp = head;

    while(temp){
        A[temp->data]++;
        temp = temp->next;
    }

    while(i <= max) {
        if(A[i] > 1){
            cout<<"element "<<i<<" repeats "<<A[i]-1<<" times "<<endl;
        }
        i++;
    }   
}

//More ways to implement this algorithm 

//reverse List
//there are various ways to implement reverse list:-
//1. By changing link address 
//--> 1.a) using iterative approach
//--> 1.b) using recursion
//--> 1.c) by making our own stack ds
//2. By swapping Node data
//3. By using Move to head algo as done earlier(Not so good approach)

//  1.a) using iterative approach :-
void Linked_List::reverseList(){

    Node *cur = head;
    Node *prev = NULL;
    Node *next;
    
    while(cur){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }    
    head = prev;
}
   

//  1.b) using recursion

void Linked_List::recReverseList(Node *temp){

    // Node *next;
    // Node *prev;
    if(temp == NULL){
        return;
    }

    if(temp->next == NULL){
        head = temp;
        return;
    }

    //prev = next;
    //next = temp->next;
    recReverseList(temp->next);
//Now temp is temp = (previous)temp;
    //next->next = temp;
    temp->next->next = temp;
    temp->next = NULL;
    //recursion mae return statement ka dhyaan rakhna jaise ki yaha par hum puche peeche....
}

//2. By swapping Node data --> O(n^2)

void Linked_List::reverseData(){
   
    int len = countNode();
    int i = 0;
    int j = len-1;
    int k;
    Node *p = head;
    Node *q = head;
    Node *temp = new Node();
    //int temp;
    while(i < j){
        k = 0;
        while(k < j){
            q = q->next;
            k++;
        }

        //temp = p->data;
        temp->data = p->data;
        p->data = q->data;
        q->data = temp->data;
        //q->data = temp;
        i++;
        j--;

        p = p->next;
        q = head;
    }
}

void dispRec(Node *head){

    Node *temp = head;

    if(!temp)
        return;

    cout<<temp->data<<endl;

    dispRec(temp->next);

    cout<<temp->data<<endl;
}

Linked_List Linked_List::concatList(Linked_List ll1,Linked_List ll2){

    Node *p = head;
    Node *q = ll1.head;
    while(p && q){

        if(p->data < q->data){

            ll2.add_node(p->data);
            p = p->next;
        }
        else{
            ll2.add_node(q->data);
            q = q->next;
        }
    }

    while(p){
        ll2.add_node(p->data);
        p = p->next;
    }

    while(q){
        ll2.add_node(q->data);
        q = q->next;
    }

    return ll2;
}


//Time Complexity = O(n^2)
Node* Linked_List::detectLoop(){
    
    int count = countNode();
    int countp = count;
    int county = count;
    Node *temp = head;
    Node *copy = NULL;
    while(temp && countp){
        copy = temp->next;
        county = count; 
        while(copy && county){
            if(temp == copy)
                return copy;

            else{
                copy = copy->next; 
                county--;
            }
        }
        temp = temp->next;
        countp--;
    }

    return NULL;
}

//Time Complexity = O(n)
//Using Flloyd Cycle Detection

void Linked_List::detectLoopPro(){

    Node *p = head;
    Node *q = head;
    Node *prev = NULL;

    if(p->next == NULL)
        return;

    while(p){
        p = p->next->next;
        prev = q;
        q = q->next;
        if(p == q){

           cout<<"Loop found"<<endl;
           break;
        }
    }

    q = head;
    while(p){

        if(p == q){
            cout<<"Cyclic Node found"<<endl;
            break;
        }
        
        p = p->next;
        q = q->next;
    }
    //removal of loop or straighting of semi-circular linked list
    //tail->next = NULL;
    prev->next = NULL;
}

int Linked_List::findMiddle(){

    Node *temp = head;
    int count = ceil(countNode()/2.0);
    cout<<count<<endl;
    count -=1;
    while(count--)
        temp = temp->next;
    
    return temp->data;
}
//Total 4 Methods to implement instersection in Linked list :->
//a) Brute Force --> O(n^2)
//b) Using Time , space Trade off --> Time -> O(m+n)  Space -> O(m+n) [Implement using set or stack data structure]--> set is best
//c) Using Count logic method similar to races like logic --> best logic but required to call count method
//d) One More Logic not require count method but internally we count the nodes. Time --> O(n)

// a) Brute Force --> O(n^2)
void Linked_List::intersectionList(Linked_List ll2){

    Node* temp1 = this->head;
    Node* temp2;
    Node* c = NULL;
    while(temp1){
        temp2 = ll2.head;
        while(temp2){
            if(temp1 == temp2){
                cout<<temp2->data<<endl;
                break;
            }
            temp2 = temp2->next;
        }
        if(temp1 == temp2)
            break;

        temp1 = temp1->next;
    }
}

//b) Using Time , space Trade off --> Time -> O(m+n)  Space -> O(m+n) [Implement using set or stack data structure]--> set is best
void isecListS(Linked_List ll1,Linked_List ll2){

    Node* l1point = ll1.head;
    Node* l2point = ll2.head;
    set<Node *> s;
    while(l1point){
        s.insert(l1point);
        l1point = l1point->next;
    }
// find function of set container return iterator at that position where element is found
// find functtion time complexity is O(log n) because elements of set are arranged in sorted order but only unique address that why binary search is implemented at the back so Time complexity is O(log n)
    while(l2point){
        if(s.find(l2point) != s.end()){
            cout<<l2point->data<<endl;
            break;   
        }

        l2point = l2point->next;
    }
}

//No. of times loop runs is O(m+n) in worst case;
// Average Case :-->
//No. of times loop runs = no. of nodes in longest Linked_List + no. of nodes in longest Linked_List before intersection

//using stack implemented through recursion
Node* isecListStack(Node* A,Node* B){

    if(A == NULL || B == NULL)
        return NULL;

    isecListStack(A->next,B->next);

    if(A == B)
        return A;

    return NULL;
}

//c) Using count function

int count(Node *head){

        int count = 0;
        Node *temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }

Node* intersect(Node* A, Node* B){
    
    Node* max;
    Node* min;
    int m = count(A);
    int n = count(B);
    
    int d = m - n;
    if(d < 0){
       d = d* -1; 
    }
    
    if(m > n){
        max = A;
        min = B;
    }
    else{
        max = B;
        min = A;
    }
    
    int cnt = 0;
    while(cnt < d){
        max = max->next; 
        cnt++;
    }
    
    while(max != min){
        max = max->next;
        min = min->next;
    }
    
    return max;
}

//d) One More Logic not require count method but internally we count the nodes. Time --> O(n)
void isecList(Linked_List ll1, Linked_List ll2){

    int c = 0;
    Node* L1point = ll1.head;
    Node* L2point = ll2.head;

    while(L1point != L2point){
        c++;
        if(L1point == NULL)
            L1point = ll2.head;
        // if we write L2point = ll1.head; then this loop goes to infinite

        else
            L1point = L1point->next;
        
        if(L2point == NULL)
            L2point = ll1.head;
        // if we write L1point = ll2.head; then this loop goes to infinite

        else
            L2point = L2point->next;
    }

    cout<<L2point<<endl;

    if(L2point != NULL)
        cout<<L2point->data<<endl;
    
    cout<<c<<endl;

}

#endif