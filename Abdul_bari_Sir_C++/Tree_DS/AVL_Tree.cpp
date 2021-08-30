#include<bits/stdc++.h>

using namespace std;

class Node
{
public:

    int data;
    int height;
    Node* left;
    Node* right;
public:
    Node()
    {
        data = 0;
        height = 0;
        left = NULL;
        right = NULL;
    }

    Node(int data)
    {
        this->data = data;
        height = 0;
        left = NULL;
        right = NULL;
    }
};

class AVL
{
public:
    Node* root;

    AVL()
    {
        root = NULL;
    }

    void insert(int);

    void inorder(Node*);

    void checkBalF(Node*);

    void preorder(Node*);

    void postorder(Node*);

    void LLRotation(Node*);
    
    void LRRotation(Node*);
    
    void RRRotation(Node*);
    
    void RLRotation(Node*);

    int treeHeight(Node*);
};

int AVL::treeHeight(Node* par)
{   
    if(!par)
        return 0;

    int x = 0 , y = 0;

    x = treeHeight(par->left);
    y = treeHeight(par->right);

    //root->height = max(x , y);
    par->height = x - y;
    
    if(x > y)
        return x + 1;
    
    else 
        return y + 1;

    // int hl , hr;

    // hl = par && par->left ? par->left : 0;
    // hr = par && par->right ? par->right : 0;

    // return hl > hr ? hl + 1 : hr + 1;
}


void AVL::insert(int key)
{
    Node* temp = new Node();
    temp->data = key;
    Node* t;
    Node* r = root;
    
    if(r == NULL)
    {
        root = temp;
        return;
    }

    while(r != NULL)
    {
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

    treeHeight(this->root);
    
    // checkBalF(this->root);
}

void AVL::checkBalF(Node* par)
{
    if(par && (par->left || par->right))
    {
        checkBalF(par->left);
        checkBalF(par->right);
        
        if(par->height == 2 && par->left->height == 1)
            LLRotation(par); 
    
        else if(par->height == 2 && par->left->height == -1)
            LRRotation(par); 

        else if(par->height == -2 && par->right->height == -1)
            RRRotation(par); 

        else if(par->height == -2 && par->right->height == 1)
            RLRotation(par); 
    }
}

void AVL::inorder(Node* root)
{
    if(root)
    {
        inorder(root->left);
        cout << root->data << " ";
        cout << root->height << endl;
        inorder(root->right);
    }    
}

void AVL::preorder(Node* root)
{
    if(root)
    {
        cout << root->data << " ";
        cout << root->height << endl;
        inorder(root->left);
        inorder(root->right);
    }    
}

void AVL::postorder(Node* root)
{
    if(root)
    {
        inorder(root->left);
        inorder(root->right);
        cout << root->data << " ";
        cout << root->height << endl;
    }    
}

void AVL::LLRotation(Node* par)
{
    Node* pl = par->left;
    Node* plr = pl->right;
    
    pl->right = par;
    par->left = plr;

    treeHeight(root);

    if(par == root)
        root = pl;        
}

void AVL::LRRotation(Node* par)
{
    Node* pl = par->left;
    Node* plr = pl->right;

    pl->right = plr->left;
    par->left = plr->right;

    par->left = pl;
    par->right = par;

    treeHeight(root);

    if(par == root)
        root = plr;
}

void AVL::RRRotation(Node* par)
{
    
}

void AVL::RLRotation(Node* par)
{

}

int main()
{
    AVL *at = new AVL();
    at->insert(40);
    at->insert(20);
    at->insert(50);
    at->insert(10);
    at->insert(30);
    at->insert(60);
    at->insert(5);
    at->insert(25);
    at->insert(35);
    at->insert(27);

    // at->inorder(at->root);
    at->preorder(at->root);
    // at->postorder(at->root);
    cout << endl;
    cout << at->treeHeight(at->root);
}