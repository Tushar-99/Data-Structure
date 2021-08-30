#include <bits/stdc++.h>
#define SIZE 10

using namespace std;

class Node
{
public:
    int data;
    Node* next;

}* tail;

class Hashing
{
public:
    //here we take table node as double pointer because we need to create table array dynamically of user defined size

    Node** table;
    int hash_size;

    Hashing()
    {
        hash_size = 0;
    }

    Hashing(int size)
    {
        table = new Node*(); 
        *table = new Node[size];
        
        int i = 0;

        while(i < size){
            table[i] = NULL;
            i++;
        }

        hash_size = size;
    }

    int hash_fun(int x)
    {
        return x % 10;
    }

    void Insert(int key)
    {
        int index = hash_fun(key);
        insertSort(&table[index] , key);
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

    void insertSort(Node** temp , int key)
    {
        Node *t = new Node();
        Node *p = *temp;
        Node *c = NULL;
        t->data = key;
        t->next = NULL;

        if(*temp == NULL){
            *temp = t;
        }   

        else if((*temp)->data >= key){
            t->next = *temp;
            *temp = t;
        }

        else {
            c = p;
            p = p->next;
            
            while(p && p->data < key)
            {
                c = p;
                p = p->next;
            }

            t->next = c->next;
            c->next = t;
        }

        Node *max = maxNode(*temp);
        tail = max;
    }

    void display()
    {
        Node* temp;
        for(int i = 0 ; i < hash_size ; i++)
        {   
            temp = table[i];
            while(temp)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    }

    void hash_Sort()
    {
        Node** mem;
        *mem = new Node[hash_size];

        for(int i = 0 ; i < hash_size ; i++)
        {
            mem[i] = table[i];
            cout << mem[i] << " ";
        }

        cout << endl ;

        for(int i = 0 ; i < 28 ; i++)
        {
            for(int i = 0 ; i < hash_size ; i++)
            {   
                if(mem[i])
                {
                    cout << mem[i]->data << " ";
                    mem[i] = mem[i]->next;
                }
            }
        }
    }

    void deleteNode(int key)
    {  
        int x;
        int index = key % 10;
        Node *prev = table[index];
        Node* temp = NULL;
        if(prev)
            temp = prev->next;

        if(prev == NULL){
            cout << endl;
            cout<< index <<" Pointing List is Empty";
            return;
        }
        
        else if(prev->data == key){
            table[index] = table[index]->next;
            x = table[index]->data;

            //isme delete nahi kar raha kyoki addressing related issue hai
            // prev = prev->next;
            // x = prev->data;
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

    Node* searchImproved(int key){

        int index = key % 10;
        Node *temp = table[index]; 

        while(temp){
            if(temp->data == key)
                return temp;
            
            temp = temp->next;
        }
        return NULL;
    }
};

struct LP
{
    int data;
    bool flag;

    LP()
    {
        data = 0;
        flag = false;
    }
};

void insert_LP(LP *H , int key)
{
    int index = key % SIZE;
    int i = 0;
    while(H[(index + i) % SIZE].data != 0)
        i++;
    
    H[(index + i) % SIZE].data = key;
    H[(index + i) % SIZE].flag = true;
}

void display(LP *H)
{
    int i = 0;
    while(i < SIZE)
    {
        if(H[i].flag == true)
            cout << H[i].data << " ";
        
        i++;
    }
}

bool search(LP *H , int key)
{
    int index = key % 10;
    int i = 0;
    
    while(H[(index + i)].data != 0 && H[(index + i)].data != key)
        i++;

    if(H[index + i].flag == true && H[(index + i)].data == key)
        return true;
    
    return false;
}

void delete_Key(LP *H , int key)
{
    int index = key % 10;
    int i = 0;
    
    while(H[(index + i)].data != 0 && H[(index + i)].data != key)
        i++;

    if(H[(index + i)].data == key)
        H[index + i].flag = false;
}

int main()
{
    // Hashing *h = new Hashing(10);
    // h->Insert(22);
    // h->Insert(12);
    // h->Insert(32);
    // h->Insert(42);
    // h->Insert(2);
    // h->Insert(1);
    // h->Insert(21);
    // h->Insert(11);
    // h->Insert(51);
    // h->Insert(23);
    // h->Insert(33);
    // h->Insert(43);
    // h->Insert(44);
    // h->Insert(45);
    // h->Insert(24);
    // h->Insert(16);
    // h->Insert(76);
    // h->Insert(87);
    // h->Insert(47);
    // h->Insert(48);
    // h->Insert(88);
    // h->Insert(99);
    // h->Insert(19);

    // h->display();

    // h->deleteNode(10);
    // h->deleteNode(20);
    // h->deleteNode(19);
    // h->deleteNode(12);
    // cout << endl;
    // h->display();
    // cout << endl;
    
    // if(h->searchImproved(12))
    //     cout << h->searchImproved(12)->data << " Element Found" << endl;
    // else
    //     cout << " Element not Found" << endl;

    // if(h->searchImproved(88))
    //     cout << h->searchImproved(88)->data << " Element Found" << endl;
    // else
    //     cout << " Element not Found" << endl;
    
    // if(h->searchImproved(10))
    //     cout << h->searchImproved(10)->data << " Element Found" << endl;
    // else
    //     cout << " Element not Found" << endl;

    // if(h->searchImproved(2))
    //     cout << h->searchImproved(2)->data << " Element Found" << endl;
    // else
    //     cout << " Element not Found" << endl;
    
    // cout << &h << endl;
    // cout << h << endl;
    // cout << *(&h) << endl;
    // cout << &h->table << endl;
    // cout << h->table << endl; // table kis address ko point kar raha hai
    // cout << *h->table << endl; // table kis address pae hai

    // for(int i = 0 ; i < h->hash_size ; i++)
    //     cout << &h->table[i] << endl;

    // for(int i = 0 ; i < h->hash_size ; i++)
    //     cout << h->table[i] << endl;

    //h->hash_Sort();
    // LP **H = new LP*();
    // *H = new LP[SIZE];

    struct LP H[SIZE];

    for(int i = 0 ; i < SIZE ; i++)
    {
        H[i].data = 0;
        H[i].flag = false;
    }

    insert_LP(H , 12);
    insert_LP(H , 44);
    insert_LP(H , 66);
    insert_LP(H , 34);
    insert_LP(H , 55);

    display(H);

    cout << "\n";
    cout << search(H , 12) << endl;
    cout << search(H , 22) << endl;
    cout << search(H , 32) << endl;
    cout << search(H , 55) << endl;

    delete_Key(H , 66);
    delete_Key(H , 22);
    delete_Key(H , 55);

    display(H);
    cout << "\n";
    cout << search(H , 66) << endl;

}


// &h --> 0x61ff00
// h --> 0x2ec1620
// &h->table -->0x2ec1620
// h->table -->0x2ec1550
// *h->table --> 0

// &h->table[0] --> 0x2ec1550
// &h->table[1] --> 0x2ec1554
// &h->table[2] --> 0x2ec1558
// &h->table[3] --> 0x2ec155c
// &h->table[4] --> 0x2ec1560
// &h->table[5] --> 0x2ec1564
// &h->table[6] --> 0x2ec1568
// &h->table[7] --> 0x2ec156c
// &h->table[8] --> 0x2ec1570
// &h->table[9] --> 0x2ec1574

// h->table[0] --> 0
// h->table[1] --> 0
// h->table[2] --> 0
// h->table[3] --> 0
// h->table[4] --> 0
// h->table[5] --> 0
// h->table[6] --> 0
// h->table[7] --> 0
// h->table[8] --> 0
// h->table[9] --> 0

// 0
// 0
// 0x2ec1650
// 0
// 0
// 0
// 0
// 0
// 0
// 0