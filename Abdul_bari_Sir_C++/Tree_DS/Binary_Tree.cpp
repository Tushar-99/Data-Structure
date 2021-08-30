//Revision -> i) postorder iterative version
//ii) Tree generation using preorder + inorder & postorder + inorder & preorder + postorder(full binary tree)

//Tree Sarra Recursion hai --> formula banao i.e. mathematical function banao recursion ke maje uthao
#include<bits/stdc++.h>

using namespace std;

class Node{

public: 
    int data;
    Node *lchd;
    Node *rchd;

public: 
    Node(){
        data = 0;
        lchd = NULL;
        rchd = NULL;
    }
};

class Tree{

public:
    Node* root;

public:
    Tree(){
        root = NULL;
    }

    void create();

    void preorder(Node* p);

    void inorder(Node* p);

    void postorder(Node* p);

    int levelorder(Node* p);

    int height(Node *p);
    
    int countNodes(Node *p);

    void iPreorder(Node* p);

    void iInorder(Node* p);

    void iPostorder(Node* p);
    
    int countLeaf(Node* p);
    
    int deg_zero(Node* p);
    
    int deg_one(Node* p);
    
    int deg_two(Node* p);
    
    int deg_z_o(Node* p);
    
    int deg_o_t(Node* p);
    
    int deg_z_t(Node* p);
    
    int deg_z_o_t(Node* p);

    int noOfUBinTree(int);

    int noOfLBinTree(int);

    int dpNoOfBST(int);

    int dp_TD_NoOfBST(int , int *);
    
    unsigned long int bin_cof_NoOfBST(unsigned int n);

    Node* generate_PRI_Tree(int *, int *, int);

    Node* generate_POI_Tree(int *, int *, int);

    Node* gen_PP_Tree(int* , int * , int);

    void invBinT(Node*);

    void IinvBinT(Node*);
};

class llNode{

public:
    Node* data;
    llNode* next;

public:
    llNode(){
        data = NULL;
        next = NULL;
    }
};

class Stack{

public:
    llNode* top;

    Stack(){
        top = NULL;
    }

    void push(Node* s){
        llNode* t = new llNode();
        t->data = s;
        t->next = NULL;
        if(top == NULL){
            top = t;
        }
        else{
            t->next = top;
            top = t;
        }
        
    }

    bool isEmpty(){
        if(top == NULL)
            return true;

        return false;
    }

    Node* pop(){
        if(isEmpty())
            return NULL;

        Node* temp = top->data;
        top = top->next;

        return temp;
        }

};

class Queue{

public:
    llNode* front;
    llNode* rear;

public:
    Queue(){
        front = rear = NULL;
    }

    void enQueue(Node *q){
        llNode* temp = new llNode;
        temp->data = q;
        if(front == NULL){
            front = temp; 
            rear = temp;           
        }

        else{
            rear->next = temp;
            rear = rear->next;
        }
    }
    
    bool isEmpty(){
        if(front == NULL)
            return true;
        
        return false;
    }
    
    Node* deQueue(){
        if(isEmpty())
            return NULL;

        Node* temp = front->data;
        front = front->next;

        return temp;
    }

};

void Tree::create(){
    
    Node *p = new Node();
    Node *t;
    char x;
    Queue *q = new Queue();
    cout << "Enter Root data: "<<endl;
    cin >> x;
    root = new Node();
    root->data = x;
    q->enQueue(root);
    
    while(!q->isEmpty()){
    
        p = q->deQueue();
        cout << "Enter the left child data of "<< p->data << " :" <<endl;
        cin >> x;

        if(x != '0'){
            t = new Node();
            t->data = x;
            p->lchd = t;
            q->enQueue(t);

        }

        cout << "Enter the right child data of "<< p->data << " :" <<  endl;
        cin >> x;
        if(x != '0'){
            t = new Node();
            t->data = x;
            p->rchd = t;
            q->enQueue(t); 
        }
    }

}

void Tree::preorder(Node *p){
    
    if(p){
        cout << p->data << " ";
        preorder(p->lchd);
        preorder(p->rchd);
    }
}

void Tree::inorder(Node* p){

    if(p){
        inorder(p->lchd);
        cout << p->data << " ";
        inorder(p->rchd);
    }
}

void Tree::postorder(Node *p){

    if(p){
        postorder(p->lchd);
        postorder(p->rchd);
        cout << p->data << " ";
    }
}

//This is same as creation of tree
// here queue is used to store the address node level wise
// queue helps in maintain the order of left and right child node
int Tree::levelorder(Node* p){
     
    int count = 0;
    Queue *q = new Queue();
    Node* temp = new Node;
    q->enQueue(p);
    cout << "Root Data: ";
    cout << p->data <<" "<<endl;
    while(!q->isEmpty()) {
        temp = q->deQueue();
        if(temp->lchd){
            cout << "Left Child of "<< temp->data << ": ";
            cout << temp->lchd->data << " " << endl;
            q->enQueue(temp->lchd);
        }
            
        if(temp->rchd){
            cout << "Right Child of " << temp->data << ": ";
            cout << temp->rchd->data << " " << endl;
            q->enQueue(temp->rchd);
        }
        count++;
    }
    cout << endl;
    return count;
}

//in tree most of the times we perform operation in postorder processing i.e. at end of each traces
//here we have to count the edges
int Tree::height(Node* p){

    // int x = 0 , y = 0;
    if(p == NULL)
        return -1;
    
    // x = height(p->lchd);
    // y = height(p->rchd);

    // if(x > y)
    //     return x + 1;
    
    // else
    //     return y + 1;

    return height(p->lchd) > height(p->rchd) ? height(p->lchd) + 1 : height(p->rchd) + 1;
    
}

int Tree::countNodes(Node *p){
    
    // if(p == NULL)
    //     return 0;
        
    // return countNodes(p->lchd) + countNodes(p->rchd) + 1;
    
    if(p == NULL)
        return 1;
        
    return countNodes(p->lchd) + countNodes(p->rchd);
}

int Tree::countLeaf(Node* p){
    
    if(p == NULL)
        return 0;
    
    if(p->lchd == NULL && p->rchd == NULL)
        return countLeaf(p->lchd) + countLeaf(p->rchd) + 1;
    
    return countLeaf(p->lchd) + countLeaf(p->rchd);
    
}

void Tree::iPreorder(Node* p){

    Stack* s = new Stack();

    //while(!s->isEmpty()){
        //Wrong code check by dry run o/p -> A , B , D , E , B ,D , E , ............
        // cout << p->data << " ";
        // while(p->lchd){
        //     cout << p->lchd->data << " ";
        //     s->push(p->lchd);
        //     p = p->lchd;
        // }
        // p = s->pop();
        // while(p->rchd){
        //     cout << p->rchd->data << " ";
        //     s->push(p->rchd);
        //     p = p->rchd;
        // }
        // p = s->pop();
//Here we have to forcibly use the stack memory because no other option is there otherwise we lost previous node addresses
//jab uske left ka kaam pura ho gya to uske address ko pop karke uske right mae chale jayo
//agar vo uska left aa raha hai toh uska adddress store ho raha aur uska right aa raha toh pop ho raha hai
    while(!s->isEmpty() || p){

        if(p){
            cout << p->data << " ";
            s->push(p);
            p = p->lchd;
        }
        else{
            p = s->pop();
            p = p->rchd;
        }
    }
}

void Tree::iInorder(Node* p){

    Stack s;

    while(!s.isEmpty() || p){

        if(p){
            s.push(p);
            p = p->lchd;
        }
        
        else{
            p = s.pop();
            cout << p->data << " ";
            p = p->rchd;
        }
    }
}


void Tree::iPostorder(Node* p){

    Stack s;
    // Node* temp;
    // long int temp;

    // while(!s.isEmpty() || p){
        
        
    //     if(p){
    //         s.push(p);
    //         p = p->lchd;
    //     }
        
    //     else{
    //         //cout << "Hello" << endl;
    //         temp = (long int)s.pop();
    //         //cout << "Hello" << endl;
    //         if(temp > 0){
    //             //cout << "Hello" << endl;
    //             s.push((Node*)-temp);
    //             //cout << "Hello" << endl;
    //             p = p->rchd;
    //         }
            
    //         else{
    //             cout << "Hello" << endl;
    //             cout << ((Node*)-temp)->data << " ";
    //             // p = s.pop();
    //             p = NULL;
    //         }
    //     }
    // }

    while(1){

        if(p){
            s.push(p);
            p = p->lchd;
        }
        else{

            if(s.isEmpty())
                break;
            
            else{
                if(s.top->data->rchd == NULL){
                    p = s.pop();
                    cout << p->data << " ";
                    while(p == s.top->data->rchd){
                        cout << s.top->data->data << " ";
                        p = s.pop();

                        if(s.isEmpty())
                            break;
                    }
                }
                if(!s.isEmpty())
                    p = s.top->data->rchd;
                
                else
                    p = NULL;
            }
        }
    }
}

int Tree::deg_zero(Node* p){
    
    int x = 0 , y = 0;
    
    if(!p)
        return 0;
        
    x = deg_zero(p->lchd);
    y = deg_zero(p->rchd);
    
    if(!p->lchd && !p->rchd){
        cout << p->data << " ";
        return x + y + 1;
    }
    else
        return x + y;
}
    
int Tree::deg_one(Node* p){
    
    int x = 0 , y = 0;
    
    if(!p)
        return 0;
        
    x = deg_one(p->lchd);
    y = deg_one(p->rchd);
    
    if(p->lchd != NULL ^ p->rchd != NULL)
        return x + y + 1;
    
    else
        return x + y;   
}
    
int Tree::deg_two(Node* p){
    
    int x = 0 , y = 0;
    
    if(!p)
        return 0;
        
    x = deg_two(p->lchd);
    y = deg_two(p->rchd);
    
    if(p->lchd && p->rchd)
        return x + y + 1;
    
    else
        return x + y;
}
    
int Tree::deg_z_o(Node* p){
    
    int x = 0 , y = 0;
    
    if(!p)
        return 0;
        
    x = deg_z_o(p->lchd);
    y = deg_z_o(p->rchd);
    
    if((!p->lchd && !p->rchd) || (p->lchd != NULL ^ p->rchd != NULL))
        return x + y + 1;
    
    else
        return x + y;
}
    
int Tree::deg_o_t(Node* p){
    
    int x = 0 , y = 0;
    
    if(!p)
        return 0;
        
    x = deg_o_t(p->lchd);
    y = deg_o_t(p->rchd);
    
    if((p->lchd && p->rchd) || (p->lchd != NULL ^ p->rchd != NULL))
        return x + y + 1;
    
    else
        return x + y;   
}
    
int Tree::deg_z_t(Node* p){
    
    int x = 0 , y = 0;
    
    if(!p)
        return 0;
        
    x = deg_z_t(p->lchd);
    y = deg_z_t(p->rchd);
    
    //if((!p->lchd && !p->rchd) || (p->lchd && p->rchd))
    if(!(p->lchd != NULL ^ p->rchd != NULL))
        return x + y + 1;
    
    else
        return x + y;
}

// Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following.
// 1) Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).
// 2) Count the number of possible Binary Search Trees with n keys (See this)
// 3) Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.
// 4) Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points such that no 2 chords intersect.
// See this for more applications. 
// The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …  
  
// counting all nodes   
int Tree::deg_z_o_t(Node* p){
    
    if(!p)
        return 0;
    
    return deg_z_o_t(p->lchd) + deg_z_o_t(p->rchd) + 1;
}

//no 0f unlabelled binary tree = no of Binary search Tree
int Tree::noOfUBinTree(int n){

    if(n == 0 || n == 1)
        return 1;
    
    int ans = 0;
    for(int i = 1 ; i <= n ; i++)
        ans += noOfUBinTree(i - 1) * noOfUBinTree(n - i);

    return ans;
}

int Tree::noOfLBinTree(int n){

    if(!n)
        return 1 ;
    
    int count = 0;
    for(int i = 1 ; i <= n ; i++)
        count += noOfUBinTree(i - 1) * noOfUBinTree(n - i);

    return count;
}

//Top down DP
int Tree::dp_TD_NoOfBST(int n , int *dp){
    
    if(dp[n] != 0)
        return dp[n];

    for(int i = 1 ; i <= n ; i++)
        dp[n] += dp_TD_NoOfBST(i - 1 , dp) * dp_TD_NoOfBST(n - i , dp);

    return dp[n];
}

// Since C(n, k) = C(n, n-k)
 
// Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]

unsigned long int bin_cof(unsigned int n ,unsigned int k){

    unsigned int res = 1;
    if(k > n - k)
        k = n - k;

    for(int i = 0 ; i < k ; i++){
        res *= (n - i);
        res /= (i + 1); 
    }

    return res;    
}

unsigned long int Tree::bin_cof_NoOfBST(unsigned int n){

    return bin_cof(2 * n , n) / (n + 1);
}

//Bottom UP DP
int Tree::dpNoOfBST(int n){
    
    int dp[n+1] = {1,1};

    for(int i = 2 ; i <= n ; i++)
        for(int j = 0 ; j < i ; j++)
            dp[i] += dp[j] * dp[i - j - 1];

    return dp[n];


}

//Tree Generation using Preorder and Inorder
Node* btPRHelper(int *pre , int *in , int inS , int inE , int preS , int preE){

    if(inS > inE)
        return NULL;

    int rootData = pre[preS];
    //cout << pre[preS] << endl; 
    int rootIndex = 0;
    for(int i = inS ; i <= inE ; i++){
        if(in[i] == rootData){
            // cout << in[i] << endl;
            // cout << rootData << endl; 
            // cout << i << " ";
            rootIndex = i;
            break;
        }
    }

// {4,2,5,1,8,6,9,3,7} <-- IN
// {4,5,2,8,9,6,7,3,1} <-- POST

    int linS = inS;
    int linE = rootIndex - 1;
    int lpreS = preS + 1;
    int lpreE = linE - linS + lpreS;
    int rinS = rootIndex + 1;
    int rinE = inE;
    int rpreS = lpreE + 1;
    int rpreE = preE;

//    cout << linS << " " << linE << " " << lpreS << " " << lpreE << " " << rinS<< " " << rinE << " " << rpreS << " " << rpreE << endl;
// recusive algo based on divide and conquor
    Node* root = new Node();
    root->data = rootData;
    //cout << root->data << endl;
    root->lchd = btPRHelper(pre , in , linS , linE , lpreS , lpreS);
    root->rchd = btPRHelper(pre , in , rinS , rinE , rpreS , rpreE);    

    return root;
}

Node* Tree::generate_PRI_Tree(int *pre , int *in , int size){

   return btPRHelper(pre , in , 0 , size - 1 , 0 , size - 1);
}

// Tree Generation using Postorder and Inorder
Node* btPOHelper(int *post , int *in , int inS , int inE , int postS , int postE){

    if(inS > inE)
        return NULL;

    int rootData = post[postE];

    int rootIndex = 0;
    for(int i = inS ; i <= inE ; i++){
        if(in[i] == rootData){
            rootIndex = i;
            break;
        }
    }

// {4,2,5,1,8,6,9,3,7} <-- IN
// {4,5,2,8,9,6,7,3,1} <-- POST

    int linS = inS;
    int linE = rootIndex - 1;
    int lpostS = postS;
    int lpostE = linE - linS + lpostS;
    int rinS = rootIndex + 1;
    int rinE = inE;
    int rpostS = lpostE + 1;
    int rpostE = postE - 1;

    //cout << linS << " " << linE << " " << lpostS << " " << lpostE << " " << rinS<< " " << rinE << " " << rpostS << " " << rpostE << endl;
// recusive algo based on divide and conquor
    Node* root = new Node();
    root->data = rootData;
    //cout << root->data << endl;

    root->lchd = btPOHelper(post , in , linS , linE , lpostS , lpostE);
    root->rchd = btPOHelper(post , in , rinS , rinE , rpostS , rpostE);    

    return root;
}

Node* Tree::generate_POI_Tree(int *post , int *in , int size){

   return btPOHelper(post , in , 0 , size - 1 , 0 , size - 1);
}


Node* btPPHelper(int* pre , int* post , int preS , int preE , int postS , int postE){

    if(preS > preE || postS > postE)
        return NULL;

    Node* par = new Node();
    par->data = pre[preS];
    int prIndex = -1 , poIndex = -1;

    if(preS != preE){
        preS++;
        for(int i = postS ; i <= postE ; i++){
            if(pre[preS] == post[i]){
                poIndex = i;
            }
        }
    }
    else
        return par;
    
    if(postS != postE){
        postE--;
        for(int i = preS ; i <= preE ; i++){
            if(post[postE] == pre[i]){
                prIndex = i;
            }
        }
    }
    else
        return par;
    

    par->lchd = btPPHelper(pre , post , preS , prIndex - 1 , postS , poIndex);
    par->rchd = btPPHelper(pre , post , prIndex , preE , poIndex + 1 , postE); 

    return par;   
}

Node* Tree::gen_PP_Tree(int* pre , int* post , int n){

    return btPPHelper(pre , post , 0 , n - 1 , 0 , n - 1);
}

void Tree::invBinT(Node *par){

    if(par){
        invBinT(par->lchd);
        invBinT(par->rchd);
        //swap done at the end of each postorder  
        Node* temp = par->lchd;
        par->lchd = par->rchd;
        par->rchd = temp;
    }
}

//its like level order traversal and swapping before traversal
void Tree::IinvBinT(Node* par){
    
    if(!par)
        return;

    Queue *q =new Queue();
    q->enQueue(par);
    Node* temp = new Node();
    Node* cur = new Node();
    while(!q->isEmpty()){
    
        cur = q->deQueue();

        if(!cur->lchd && !cur->rchd)
            continue;
            
        Node* temp = cur->lchd;
        cur->lchd = cur->rchd;
        cur->rchd = temp;

        if(cur->lchd)
            q->enQueue(cur->lchd);

        if(cur->rchd)
            q->enQueue(cur->rchd);
    }

}

int main(){

    Tree *t = new Tree();
//    t->create();
//     cout << "PREORDER :" << " ";
//     t->preorder(t->root);
//     cout << '\n';
//     cout << "INORDER :" << " ";
//     t->inorder(t->root);

//     cout << '\n';
//     cout << "POSTORDER :" << " ";
//     t->postorder(t->root);
//     cout << '\n';
//     cout << "LEVELORDER :" << " ";
//     cout << t->levelorder(t->root);
//     cout << '\n';
//     cout << "Height Of Tree :" << t->height(t->root) << endl;
//     cout << "No of Nodes in a Tree :" << t->countNodes(t->root) - 1 << endl;
//     cout << "No of Leaf Nodes in a Tree :" << t->countLeaf(t->root) << endl;
//     t->iPreorder(t->root);
//     cout << '\n';
//     t->iInorder(t->root);
//     cout << '\n';
//     t->iPostorder(t->root);
//    cout << '\n';
    
//    cout << "No of deg_zero Nodes in a Tree :" << t->deg_zero(t->root) << endl;
//     cout << "No of deg_one Nodes in a Tree :" << t->deg_one(t->root) << endl;
//     cout << "No of deg_two Nodes in a Tree :" << t->deg_two(t->root) << endl;
//     cout << "No of deg_z_o Nodes in a Tree :" << t->deg_z_o(t->root) << endl;
//     cout << "No of deg_o_t Nodes in a Tree :" << t->deg_o_t(t->root) << endl;
//     cout << "No of deg_z_t Nodes in a Tree :" << t->deg_z_t(t->root) << endl;
//     cout << "No of deg_z_o_t Nodes in a Tree :" << t->deg_z_o_t(t->root) << endl
//     cout << t->noOfUBinTree(6) << endl;
//     cout << t->noOfLBinTree(5) * 5 * 4 * 3 * 2 * 1 << endl;
    // int n = 8;
    // int dp[n + 1];
    // dp[0] = dp[1] = 1;
    // for(int i = 2 ; i < n + 1 ; i++)
    //     dp[i] = 0;

    // cout << t->dp_TD_NoOfBST(n , dp) << endl;
//    cout << t->dpNoOfBST(5) << endl;
//    cout << t->bin_cof_NoOfBST(6) << endl;
    // vector<int> pre;
    // vector<int> in;

    // pre.push_back(1);
    // pre.push_back(2);
    // pre.push_back(4);
    // pre.push_back(5);
    // pre.push_back(3);
    // pre.push_back(6);
    // pre.push_back(8);
    // pre.push_back(9);
    // pre.push_back(7);

    // in.push_back(4);
    // in.push_back(2);
    // in.push_back(5);
    // in.push_back(1);
    // in.push_back(8);
    // in.push_back(6);
    // in.push_back(9);
    // in.push_back(3);
    // in.push_back(7);
    int pre[9] = {1,2,3,4,5,6,8,9,7};
    int in[9] = {2,1,4,3,8,6,9,5,7};
    int post[9] = {2,4,8,9,6,7,5,3,1};

    // Node* piTree = t->generate_PRI_Tree(pre , in , 9);
    // t->levelorder(piTree);

    // Node* poTree = t->generate_POI_Tree(post , in , 9);
    // t->levelorder(poTree);

    Node* ppTree = t->gen_PP_Tree(pre , post , 9);
    t->levelorder(ppTree);
    // cout << '\n';
    // t->invBinT(ppTree);
    // t->levelorder(ppTree);
    t->IinvBinT(ppTree);
    t->levelorder(ppTree);
}

//Output -->
// Enter Root data: 
// A
// Enter the left child data of A :
// 0
// Enter the right child data of A :
// B
// Enter the left child data of B :
// C
// Enter the right child data of B :
// D
// Enter the left child data of C :
// E
// Enter the right child data of C :
// 0
// Enter the left child data of D :
// F
// Enter the right child data of D :
// G
// Enter the left child data of E :
// 0
// Enter the right child data of E :
// 0
// Enter the left child data of F :
// 0
// Enter the right child data of F :
// 0
// Enter the left child data of G :
// H
// Enter the right child data of G :
// 0
// Enter the left child data of H :
// I
// Enter the right child data of H :
// 0
// Enter the left child data of I :
// 0
// Enter the right child data of I :
// 0
// PREORDER : A B C E D F G H I 
// INORDER : A E C B F D I H G 
// POSTORDER : E C F I H G D B A 
// LEVELORDER : A B C D E F G H I 
// 9
// Height Of Tree :5
// No of Nodes in a Tree :9
// A B C E D F G H I 
// A E C B F D I H G 
// Segmentation fault (core dumped)

// 0 2 1 3 4 8 4 8
// 1
// 0 0 2 2 2 2 3 1
// 2
// 0 -1 3 2 1 0 3 2
// 4
// 2 1 4 3 3 2 4 1
// 5
// 4 6 5 7 8 8 8 8
// 3
// 4 4 6 6 6 6 7 5
// 6
// 4 3 7 6 5 4 7 6
// 8
// 6 5 8 7 7 6 8 5
// 9
// 8 7 9 8 9 8 9 8
// 7
// Root Data: 1
// Left Child of 1: 2
// Right Child of 1: 3
// Left Child of 2: 4
// Right Child of 2: 5
// Left Child of 3: 6
// Right Child of 3: 7
// Left Child of 6: 8
// Right Child of 6: 9

// 0 2 1 3 4 8 4 8
// 0 0 2 2 2 2 3 1
// 0 -1 3 2 1 0 3 2
// 2 1 4 3 3 2 4 1
// 4 6 5 7 8 8 8 8
// 4 4 6 6 6 6 7 5
// 4 3 7 6 5 4 7 6
// 6 5 8 7 7 6 8 5
// 8 7 9 8 9 8 9 8
