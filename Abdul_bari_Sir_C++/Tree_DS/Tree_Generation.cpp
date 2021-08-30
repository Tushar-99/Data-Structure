// #include<bits/stdc++.h>

// using namespace std;

// class Tnode{

// public:
//     int data ;
//     Tnode *lchd;
//     Tnode *rchd;

//     Tnode(){
//         data = 0;
//         lchd = NULL;
//         rchd = NULL;
//     }

//     Tnode(int data){
//         this->data = data;
//         lchd = NULL;
//         rchd = NULL;
//     }
// };

// class Tree{

// public:
//     Tnode* root;

//     Tree(){
//         root = NULL;
//     }

//     void insert(Tnode* , int);

//     void printTree(Tnode*);

//     void inOrder(Tnode* par);

//     Tnode* genTree(vector<int> &, vector<int> &);
// };

// void printTree(Tnode* par){


// }

// void inOrder(Tnode* par){

//     if(par){
//         inOrder(par->lchd);
//         cout << par->data << " ";
//         inOrder(par->rchd);
//     }
// }

// Tnode* btHelp(vector<int> &pre , vector<int> &in , int preS , int inS , int inE){

//     if(preS > pre.size() - 1 || inS > inE) 
//         return NULL;

//     Tnode* par = new Tnode(pre[preS++]);
//     int index = 0;

//     for(int i = inS ; i <= inE ; i++){

//         if(in[i] == par->data){
//             index = i;
//         }
//     }

//     par->lchd = btHelp(pre , in , preS + 1 , inS , index - 1);
//     par->rchd = btHelp(pre , in , preS + index - inS + 1 , index + 1 , inE);

//     return par;
// }


// Tnode* Tree::genTree(vector<int> &pre , vector<int> &in){

//     return btHelp(pre , in , 0 , 0 , in.size() - 1);
// }

// int main(){

//     Tree* t = new Tree();

//     vector<int> pre;
//     vector<int> in;

//     pre.push_back(1);
//     pre.push_back(2);
//     pre.push_back(4);
//     pre.push_back(5);
//     pre.push_back(3);
//     pre.push_back(6);
//     pre.push_back(8);
//     pre.push_back(9);
//     pre.push_back(7);

//     in.push_back(4);
//     in.push_back(2);
//     in.push_back(5);
//     in.push_back(1);
//     in.push_back(8);
//     in.push_back(6);
//     in.push_back(9);
//     in.push_back(3);
//     in.push_back(7);

//     Tnode* par = t->genTree(pre , in);
//     cout << par->data << " ";
//     cout << par->lchd->data << " ";
//     cout << par->rchd->data << " ";
//     cout << par->lchd->lchd->data << " ";
//     cout << par->lchd->rchd->data << " ";
//     //t->inOrder(par);
//     //t->printTree(par);
// }


/* C++ program to construct tree using inorder and 
postorder traversals */
#include <bits/stdc++.h> 

using namespace std; 

/* A binary tree node has data, pointer to left 
child and a pointer to right child */
struct Node { 
	int data; 
	Node *left, *right; 
}; 

// Utility function to create a new node 
Node* newNode(int data); 

/* Prototypes for utility functions */
int search(int arr[], int strt, int end, int value); 

/* Recursive function to construct binary of size n 
from Inorder traversal in[] and Postorder traversal 
post[]. Initial values of inStrt and inEnd should 
be 0 and n -1. The function doesn't do any error 
checking for cases where inorder and postorder 
do not form a tree */
Node* buildUtil(int in[], int post[], int inStrt, int inEnd, int* pIndex) 
{ 
	// Base case 
	if (inStrt > inEnd) 
		return NULL; 

	/* Pick current node from Postorder traversal using 
	postIndex and decrement postIndex */
	Node* node = newNode(post[*pIndex]); 
	(*pIndex)--; 

	/* If this node has no children then return */
	if (inStrt == inEnd) 
		return node; 

	int iIndex = search(in, inStrt, inEnd, node->data); 
	/* Else find the index of this node in Inorder 
	traversal */

	/* Using index in Inorder traversal, construct left and 
	right subtress */
    
	node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex); 
	node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex); 

	return node; 
} 

// This function mainly initializes index of root 
// and calls buildUtil() 
Node* buildTree(int in[], int post[], int n) 
{ 
	int pIndex = n - 1; 
	return buildUtil(in, post, 0, n - 1, &pIndex); 
} 

/* Function to find index of value in arr[start...end] 
The function assumes that value is postsent in in[] */
int search(int arr[], int strt, int end, int value) 
{ 
	int i; 
	for (i = strt; i <= end; i++) { 
		if (arr[i] == value) 
			break; 
	} 
	return i; 
} 

/* Helper function that allocates a new node */
Node* newNode(int data) 
{ 
	Node* node = (Node*)malloc(sizeof(Node)); 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

/* This funtcion is here just to test */
void preOrder(Node* node) 
{ 
	if (node == NULL) 
		return; 
	printf("%d ", node->data); 
	preOrder(node->left); 
	preOrder(node->right); 
} 

// Driver code 
int main() 
{ 
	int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 }; 
	int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 }; 
	int n = sizeof(in) / sizeof(in[0]); 

	Node* root = buildTree(in, post, n); 

	cout << "Preorder of the constructed tree : \n"; 
	preOrder(root); 

	return 0; 
} 


// // C++ program to construct a tree using 
// // inorder and preorder traversal 
// #include<bits/stdc++.h> 
// using namespace std; 

// class TreeNode 
// { 
// 	public: 
// 	int val; 
// 	TreeNode* left; 
// 	TreeNode* right; 
// 	TreeNode(int x) { val = x; } 
// }; 

// set<TreeNode*> s; 
// stack<TreeNode*> st; 

// // Function to build tree using given traversal 
// TreeNode* buildTree(int preorder[], int inorder[],int n) 
// { 

// 	TreeNode* root = NULL; 
// 	for (int pre = 0, in = 0; pre < n;) { 
//         TreeNode* node = NULL; 
// 		do{ 
// 			node = new TreeNode(preorder[pre]); 
// 			if (root == NULL) 
// 				root = node; 
			
// 			if (st.size() > 0) { 
// 				if (s.find(st.top()) != s.end()) { 
// 					s.erase(st.top()); 
// 					st.top()->right = node; 
// 					st.pop(); 
// 				} 
// 				else
// 					st.top()->left = node;
// 			} 
// 			st.push(node); 
// 		} while (preorder[pre++] != inorder[in] && pre < n); 

// 		node = NULL; 
// 		while (st.size() > 0 && in < n && 
// 				st.top()->val == inorder[in]) 
// 		{ 
// 			node = st.top(); 
// 			st.pop(); 
// 			in++; 
// 		} 

// 		if (node != NULL) 
// 		{ 
// 			s.insert(node); 
// 			st.push(node); 
// 		} 
// 	} 

// 	return root; 
// } 

// // Function to print tree in Inorder 
// void printInorder(TreeNode* node) 
// { 
// 	if (node == NULL) 
// 		return; 

// 	/* first recur on left child */
// 	printInorder(node->left); 

// 	/* then print the data of node */
// 	cout << node->val << " "; 

// 	/* now recur on right child */
// 	printInorder(node->right); 
// } 

// // Driver code 
// int main() 
// { 
// 	int in[] = { 9, 8, 4, 2, 10, 5, 10, 1, 6, 3, 13, 12, 7 }; 
// 	int pre[] = { 1, 2, 4, 8, 9, 5, 10, 10, 3, 6, 7, 12, 13 }; 
// 	int len = sizeof(in)/sizeof(int); 

// 	TreeNode *root = buildTree(pre, in, len); 

// 	printInorder(root); 
// 	return 0; 
// } 