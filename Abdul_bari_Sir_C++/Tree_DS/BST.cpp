#include<bits/stdc++.h>

using namespace std;

class Node{

public:
    int data;
    Node* left;
    Node* right;

public:
    Node(){
        data = 0;
        left = right = NULL;
    }
};

class BST{

public:
    Node* root;

    BST()
    {
        root = NULL;
    }

    Node* Rinsert(Node* , int);

    void Iinsert(int);

    void preOrder(Node*);

    void inOrder();

    void postOrder();

    Node* deleteNode(Node* , int);

    void genTreePre(int* , int);

    void genTreeIn(int* , int);

    void genTreePost(int* , int);

    Node* recPre(int* , int);

    Node* recPrePro(int* , int);

    Node* recgenPost(int* , int , int , Node*);

};

Node* BST::Rinsert(Node* par , int key){

    Node* t;

    if(par == NULL){
        t = new Node();
        t->data = key;
        return t;
    }

    if(key < par->data)
        par->left = Rinsert(par->left , key);

    else if(key > par->data)
        par->right = Rinsert(par->right , key);
    
    return par;
}

void BST::Iinsert(int key){

    Node* temp = new Node();
    temp->data = key;
    Node* t;
    Node* r = this->root;

    if(r == NULL){
        this->root = temp;
        return;
    }
//agar r NULL nahi hai toh next iteration mae r ko agge jana hi jana hai 
    while(r != NULL){
        t = r;
        if(r->data == key)
            return;

        if(key < r->data)
            r = r->left;
        
        else if(key > r->data)
            r = r->right;
    }

    if(t->data > key)
        t->left = temp;

    else
        t->right = temp;
    
}

void BST::preOrder(Node* par){

    if(par){
        cout << par->data << " ";
        preOrder(par->left);
        preOrder(par->right);
    }
}

//helping function
Node* inPre(Node* p)
{
    while(p && p->right != NULL)
        p = p->right;
    
    return p;
}

Node* inSuc(Node* p)
{

    while(p && p->left != NULL)
        p = p->left;

    return p;
}

int height(Node* p)
{
    int x , y;
    if(p == NULL)
        return 0;

    //not initailize again during returning time
    
    x = height(p->left);
    y = height(p->right);
    return x > y ? x + 1 : y + 1;
}

Node* findMin(Node* p)
{
    while(p->left != NULL)
        p = p->left;

    return p;
}

//tree must have atleast two nodes
//wrong result if we are going to delete node which is not present in Tree

Node* BST::deleteNode(Node* p , int key)
{

//     Node* q = NULL;

//     if(!p)
//         return root;

  // //deletion

//     if(p->left == NULL && p->right == NULL)
//     {
//         if(p == root)
//             root = NULL;

//         delete p;
//         return NULL;
//     }

// // Searching

//     if(p->data > key)
//         p->left = deleteNode(p->left , key);

//     else if(p->data < key)
//         p->right = deleteNode(p->right , key);
// // finding right one for deletion

//     else
//     {
//         if(height(p->left) > height(p->right))
//         {
//             q = inPre(p->left);
//             p->data = q->data;
//             p->left = deleteNode(p->left , q->data);
//         }
//         else
//         {
//             q = inSuc(p->right);
//             p->data = q->data;
//             p->right = deleteNode(p->right , q->data);
//         }
//     }    
//     return p;

    if(p == NULL)
        return root;

    else if(p->data > key)
        p->left = deleteNode(p->left , key);

    else if(p->data < key)
        p->right = deleteNode(p->right , key);

    else if(p->data == key)
    {
        if(p->left == NULL && p->right == NULL)
        {
            delete p;
            p = NULL;
        }

        else if(p->left == NULL)
        {
            Node* temp = p;
//previous vale ke left ya right mae p ke right ka address return kar dega
            p = p->right;
            delete temp;
        }

        else if(p->right == NULL)
        {
            Node* temp = p;
            p = p->left;
            delete temp;
        }

        else
        {
            Node* temp = findMin(p->right);
            p->data = temp->data;
//we recusively replace the data of node such we come across a node having one child such that on this scenario node will be deleted without harming remaining Tree 
            p->right = deleteNode(p->right , temp->data);
        }
    }
    return p;
}

// T.C. --> O(N)
void BST::genTreePre(int *pre , int n){

    stack<Node*> st;
    int i = 0;
    Node* dummy = new Node();
    dummy->data = INT32_MAX;// +infinity
    st.push(dummy);
    root = new Node();
    root->data = pre[i++];
    Node* t;
    Node* p = root;

    while(i < n){

        if(p->data > pre[i])
        {
            t = new Node();
            t->data = pre[i++];
            p->left = t;
            st.push(p);
            p = t;
        }

        else if(pre[i] < st.top()->data)
        {
            t = new Node();
            t->data = pre[i++];
            p->right = t;
            p = t;
        }
        
        else
        {
            p = st.top();
            st.pop();
        }
    }
}

// T.C. --> O(N*logN) in worst case T.C. --> O(N^2) i.e. when tree is either left or right skewed
// & jarrori hai samajh le
//for each elememt in pre array it search their required position and inserted at that position
// look like preorder traversing
Node* &buildBST(Node* &par , int ele){

    if(!par)
    {
        par = new Node();
        par->data = ele;
        return par;
    }

    if(par->data > ele)
        par->left = buildBST(par->left , ele);
    
    else
        par->right = buildBST(par->right , ele);
    
    return par;
}

Node* BST::recPre(int *pre , int n){

    Node* par = NULL;

    for(int i = 0 ; i < n ; i++)
        buildBST(par , pre[i]);

    return par;

}

//still it is recursive solution but base condition is not same as previous recusive function here we work on the range of the insertion for a node of tree

int construct_BST(int* pre , int n , int pos , Node* root , int left , int right)
{

    if(pos == n || pre[pos] < left || pre[pos] > right)
        return pos;

    if(root->data > pre[pos])
    {
        root->left = new Node();
        root->left->data = pre[pos];
        pos++;
        pos = construct_BST(pre , n , pos , root->left , left , root->data - 1);
    }    

    if(pos == n || pre[pos] < left || pre[pos] > right)
        return pos;
    
    root->right = new Node();
    root->right->data = pre[pos];
    pos++;
    pos = construct_BST(pre , n , pos , root->right , root->data + 1 , right);
 
    return pos;
}

Node* BST::recPrePro(int *pre , int n){

    if(n == 0 || pre == NULL)
        return NULL;

    Node* root = new Node();
    root->data = pre[0];

    if(n == 1)
        return root;

    construct_BST(pre , n , 1 , root , INT_MIN , INT_MAX);

    return root;
}

void BST::genTreePost(int* post , int n)
{
    int i = n - 1;
    stack<Node*> st;
    Node* dummy = new Node();
    dummy->data = INT_MIN;
    st.push(dummy);
    root = new Node();
    root->data = post[i--];
    Node* p = root;
    Node* t;

    while(i >= 0)
    {
       if(post[i] > p->data)
       {
           t = new Node();
           t->data = post[i--];
           p->right = t;
           st.push(p);
           p = t;
       }

       else if(post[i] > st.top()->data)
       {
           t = new Node();
           t->data = post[i--];
           p->left = t;
           p = t;
       }

       else
       {
            p = st.top();
            st.pop();           
       }       
    }
}

Node* BST::recgenPost(int* post ,int start , int end , Node* root)
{
    // if(post == NULL)
    //     return NULL;

    // int k;
    // Node* p = root;
    // p->data = post[end - 1];

    // for(int i = end - 2 ; i >= 0 ; i--)
    // {
    //     if(post[i] < post[end - 1])
    //     {
    //         k = i;
    //         break;           
    //     }
    // }

    // root->left = recgenPost(post , 0 , k , p->left);
    // root->right = (post , k + 1 , end - 2 , p->right);

    // return p;


}

//recursion mae return ka dhayaan rakho
int main(){

    // BST *b = new BST();
    // b->root = b->Rinsert(b->root , 20);
    // b->Rinsert(b->root , 25);
    // b->Rinsert(b->root , 15);
    // b->Rinsert(b->root , 5);
    // b->Rinsert(b->root , 35);
    // b->Iinsert(2);
    // b->Iinsert(6);
    // b->Iinsert(40);
    // b->preOrder(b->root);

    // int pre[] = {30 , 20 , 10 , 15 , 25 , 40 , 50 , 45};
    int post[] = {15 , 10 , 25 , 20 , 45 , 50 , 40 , 30};
    BST *bb = new BST();
    // bb->genTreePost(post , 8);
    // bb->preOrder(bb->root);
    // Node* par = bb->recPre(pre , 8);
    // bb->preOrder(par);
    bb->genTreePost(post , 8);
    bb->preOrder(bb->root);
    // Node* root = bb->recPrePro(pre , 8);
    // bb->preOrder(root);

    // BST *b = new BST();
    // b->Iinsert(12);
    // b->Iinsert(5);
    // b->Iinsert(15);
    // b->Iinsert(3);
    // b->Iinsert(1);
    // b->Iinsert(7);
    // b->Iinsert(9);
    // b->Iinsert(13);
    // b->Iinsert(17);
    // b->Iinsert(19);

    // // b->deleteNode(b->root , 45);
    // b->preOrder(b->root);
}


//Wrong method because here we have to change whole tree which result in disturbance of tree
//     if(!this->root)
//         return;
    
//     Node *cur = this->root;
//     Node *prev = NULL;
//     Node *l , *r;
//     Node *templ , *tempr;
//     bool flag = true;
    
//     while(cur){

//         if(cur->data == key){
//             l = cur->left;
//             r = cur->right;
            
//             if(flag)
//                 prev->left = l;
            
//             else
//                 prev->right = l;
            
//             if(l){
//                 templ = l->left;
//                 tempr = l->right;

//                 l->right = r;
//                 if(tempr)
//                     r->left = tempr;
                
//                 if(templ && tempr)
//                     tempr->left = templ;
//             }

//             if(cur == prev)
//                 this->root = cur->left;
            
//             delete cur;
//             return;
//         }

//         if(cur->data > key){
//             flag = true;
//             prev = cur;
//             cur = cur->left;
//         }

//         else if(cur->data < key){
//             flag = false;
//             prev = cur;
//             cur = cur->right;
//         }
//     }
//     if(!cur)
//         cout << "Key not found" << endl;