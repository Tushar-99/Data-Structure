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

    int nodeHeight(Node*);

    Node* deletion(Node* , int);

    Node* FindMin(Node*);

    int balF(Node*);
};

int AVL::treeHeight(Node* par)
{   
    if(!par)
        return 1;

    int x = 0 , y = 0;

    x = treeHeight(par->left);
    y = treeHeight(par->right);

    par->height = max(x , y);

    if(x > y)
        return x + 1;
    
    else 
        return y + 1;

    //par->height = x - y;
    // int hl , hr;

    // hl = par && par->left ? par->left : 0;
    // hr = par && par->right ? par->right : 0;

    // return hl > hr ? hl + 1 : hr + 1;
}

int AVL::nodeHeight(Node* par)
{   
    int hl , hr;

    hl = par && par->left ? par->left->height : 0;
    hr = par && par->right ? par->right->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
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

    treeHeight(root);
    
    checkBalF(root);
}

int AVL::balF(Node* par)
{
    int hl , hr;

    hl = par && par->left ? par->left->height : 0;
    hr = par && par->right ? par->right->height : 0;

    return hl - hr;
}

void AVL::checkBalF(Node* par)
{
    if(par)
    {
        checkBalF(par->left);
        checkBalF(par->right);

        if(par->left && balF(par) == 2 && balF(par->left) == 1)
        {
            cout << "LLRotation"<<endl;
            LLRotation(par); 
        }
        else if(par->left && balF(par) == 2 && balF(par->left) == -1)
        {
            cout << "LRRotation"<<endl;
            LRRotation(par); 
        }
        else if(par->right && balF(par) == -2 && balF(par->right) == -1)
        {
            cout << "RRRotation" << endl;
            RRRotation(par); 
        }
        else if(par->right && balF(par) == -2 && balF(par->right) == 1)
        {
            cout << "RLRotation" << endl;
            RLRotation(par);
        }
    }
}

void AVL::LLRotation(Node* par)
{
    Node* pl = par->left;
    Node* plr = pl->right;
    
    pl->right = par;
    par->left = plr;

    // par->height = nodeHeight(par);
    // pl->height = nodeHeight(pl);

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

    plr->left = pl;
    plr->right = par;

    // par->height = nodeHeight(par);
    // pl->height = nodeHeight(pl);
    // plr->height = nodeHeight(plr);

    treeHeight(root);
    
    if(par == root)
        root = plr;
}

void AVL::RRRotation(Node* par)
{
    Node* pr = par->right;
    Node* prl = pr->left;
    
    pr->left = par;
    par->right = prl;

    // par->height = nodeHeight(par);
    // pl->height = nodeHeight(pl);

    treeHeight(root);

    if(par == root)
        root = pr;    
}

void AVL::RLRotation(Node* par)
{
    Node* pr = par->right;
    Node* prl = pr->left;

    pr->left = prl->right;
    par->right = prl->left;

    prl->left = par;
    prl->right = pr;

    // par->height = nodeHeight(par);
    // pl->height = nodeHeight(pl);
    // plr->height = nodeHeight(plr);

    treeHeight(root);
    
    if(par == root)
        root = prl;
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
        preorder(root->left);
        preorder(root->right);
    }    
}

void AVL::postorder(Node* root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
        cout << root->height << endl;
    }    
}

Node* AVL::FindMin(Node* par)
{
    while(par->left) par = par->left;

    return par;
}

Node* AVL::deletion(Node* par , int key)
{
    if(par == NULL) return par;

    else if(par->data > key) par->left = deletion(par->left , key);
    else if(par->data < key) par->right = deletion(par->right , key);
    
    else 
    {
        if(par->left == NULL && par->right == NULL)
        {
            delete par;
            par = NULL;
            checkBalF(par);
        }

        else if(par->left == NULL)
        {
            Node* temp = par;
            par = par->right;
            delete par;
            checkBalF(par);
        }

        else if(par->right == NULL)
        {
            Node* temp = par;
            par = par->left;
            delete par;
            checkBalF(par);
        }

        else
        {
            Node* temp = FindMin(par->right);
            par->data = temp->data;
            par->right = deletion(par->right , temp->data);
        }
    } 
    return par;  
}

int main()
{
    AVL *at = new AVL();
    at->insert(21);
    at->insert(26);
    at->insert(30);
    at->insert(9);
    at->insert(4);
    at->insert(14);
    at->insert(28);
    at->insert(18);
    at->insert(15);
    at->insert(10);
    at->insert(2);
    at->insert(3);
    at->insert(7);
    // at->inorder(at->root);
    at->preorder(at->root);
    // at->postorder(at->root);
    cout << endl;
    cout << at->treeHeight(at->root) - 1 << endl;

    // at->deletion(at->root , 25);
    // at->preorder(at->root);
    // cout << at->treeHeight(at->root) << endl;
}