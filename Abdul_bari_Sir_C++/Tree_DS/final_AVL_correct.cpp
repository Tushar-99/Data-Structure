#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    int height;
    Node* left;
    Node* right;

    Node()
    {
        data = 0;
        height = INT_MIN;
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

    Node* insert(Node* , int);

    int nodeHeight(Node*);

    int balFactor(Node*);

    Node* LLRotation(Node*);
    
    Node* LRRotation(Node*);
    
    Node* RRRotation(Node*);
    
    Node* RLRotation(Node*);

    void inorder(Node*);

    void preorder(Node*);

    void postorder(Node*);

    Node* checkBal(Node*);

    Node* deletion(Node* , int);

    Node* FindMin(Node*);
};

Node* AVL::insert(Node* par , int key)
{

    Node* temp = new Node();
    temp->data = key;

    if(!par)
    {   
        temp->height = 1;
        return temp;
    }

    if(par->data > key) par->left = insert(par->left , key);
    
    else if(par->data < key) par->right = insert(par->right , key);

    else 
        return par;
    
    par->height = nodeHeight(par);

    if(balFactor(par) == 2 && balFactor(par->left) == 1)
    {
        cout << "LLRotation" << endl;
        return LLRotation(par);
    }

    else if(balFactor(par) == 2 && balFactor(par->left) == -1)
    {
        cout << "LRRotation" << endl;
        return LRRotation(par);
    }

    else if(balFactor(par) == -2 && balFactor(par->right) == -1)
    {
        cout << "RRRotation" << endl;
        return RRRotation(par);
    }
    else if(balFactor(par) == -2 && balFactor(par->right) == 1)
    {
        cout << "RLRotation" << endl;
        return RLRotation(par);
    }

    return par;
}

int AVL::nodeHeight(Node* par)
{
    int hl , hr;

    hl = par && par->left ? par->left->height : 0;
    hr = par && par->right ? par->right->height : 0;

    return hr > hl ? hr + 1 : hl + 1;
}

int AVL::balFactor(Node* par)
{
    int hl , hr;

    hl = par && par->left ? par->left->height : 0;
    hr = par && par->right ? par->right->height : 0;

    return hl - hr;
}

Node* AVL::LLRotation(Node* par)
{
    Node* pl = par->left;
    Node* plr = pl->right;
    
    pl->right = par;
    par->left = plr;

    par->height = nodeHeight(par);
    pl->height = nodeHeight(pl);

    if(par == root)
        root = pl;    

    return pl;
}

Node* AVL::LRRotation(Node* par)
{
    Node* pl = par->left;
    Node* plr = pl->right;

    pl->right = plr->left;
    par->left = plr->right;

    plr->left = pl;
    plr->right = par;

    par->height = nodeHeight(par);
    pl->height = nodeHeight(pl);
    plr->height = nodeHeight(plr);

    if(par == root)
        root = plr;

    return plr;
}

Node* AVL::RRRotation(Node* par)
{
    Node* pr = par->right;
    Node* prl = pr->left;
    
    pr->left = par;
    par->right = prl;

    pr->height = nodeHeight(pr);
    par->height = nodeHeight(par);

    if(par == root)
        root = pr;    
    return pr;
}

Node* AVL::RLRotation(Node* par)
{
    Node* pr = par->right;
    Node* prl = pr->left;

    pr->left = prl->right;
    par->right = prl->left;

    prl->left = par;
    prl->right = pr;

    par->height = nodeHeight(par);
    pr->height = nodeHeight(pr);
    prl->height = nodeHeight(prl);

    
    if(par == root)
        root = prl;

    return prl;
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

Node* AVL::checkBal(Node* par)
{
    if(balFactor(par) == 2 && balFactor(par->left) == 1)
    {
        cout << "LLRotation" << endl;
        return LLRotation(par);
    }

    else if(balFactor(par) == 2 && balFactor(par->left) == -1)
    {
        cout << "LRRotation" << endl;
        return LRRotation(par);
    }

    else if(balFactor(par) == -2 && balFactor(par->right) == -1)
    {
        cout << "RRRotation" << endl;
        return RRRotation(par);
    }
    else if(balFactor(par) == -2 && balFactor(par->right) == 1)
    {
        cout << "RLRotation" << endl;
        return RLRotation(par);
    }

    return NULL;
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
        }

        else if(par->left == NULL)
        {
            Node* temp = par;
            par = par->right;
            delete temp;
        }

        else if(par->right == NULL)
        {
            Node* temp = par;
            par = par->left;
            delete temp;
        }

        else
        {
            Node* temp = FindMin(par->right);
            par->data = temp->data;
            par->right = deletion(par->right , temp->data);
        }
    } 

    if(par == NULL)
        return par;

    par->height = nodeHeight(par);

    if(par->left && balFactor(par) == 2 && balFactor(par->left) == 1)
    {
        cout << "LLRotation" << endl;
        return LLRotation(par);
    }

    else if(par->left && balFactor(par) == 2 && balFactor(par->left) == -1)
    {
        cout << "LRRotation" << endl;
        return LRRotation(par);
    }

    else if(par->right && balFactor(par) == -2 && balFactor(par->right) == -1)
    {
        cout << "RRRotation" << endl;
        return RRRotation(par);
    }
    
    else if(par->right && balFactor(par) == -2 && balFactor(par->right) == 1)
    {
        cout << "RLRotation" << endl;
        return RLRotation(par);
    }

    return par;  
}

int main()
{
    AVL *at = new AVL();
    // at->root = at->insert(at->root , 21);
    // at->insert(at->root , 26);
    // at->insert(at->root , 30);
    // at->insert(at->root , 9);
    // at->insert(at->root , 4);
    // at->insert(at->root , 14);
    // at->insert(at->root , 28);
    // at->insert(at->root , 18);
    // at->insert(at->root , 15);
    // at->insert(at->root , 10);
    // at->insert(at->root , 2);
    // at->insert(at->root , 3);
    // at->insert(at->root , 7);

    at->root = at->insert(at->root , 44);
    at->insert(at->root , 17);
    at->insert(at->root , 62);
    at->insert(at->root , 32);
    at->insert(at->root , 50);
    at->insert(at->root , 78);
    at->insert(at->root , 48);
    at->insert(at->root , 54);
    at->insert(at->root , 88);

    at->preorder(at->root);

    at->deletion(at->root , 32);
    at->deletion(at->root , 62);
    at->deletion(at->root , 44);
    at->deletion(at->root , 48);
    at->deletion(at->root , 88);
    at->deletion(at->root , 17);
    cout << endl;
    at->preorder(at->root);
}

// Final output ->
// RRRotation
// LLRotation
// LRRotation
// RLRotation
// RLRotation
// RLRotation
// LLRotation
// LRRotation
// LRRotation
// 14 4
// 4 3
// 3 2
// 2 1
// 9 2
// 7 1
// 10 1
// 21 3
// 15 2
// 18 1
// 28 2
// 26 1
// 30 1