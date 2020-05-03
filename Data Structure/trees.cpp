#include <bits/stdc++.h>
using namespace std;

// trees:
/*
A tree is a data structure similar to a linked list but instead of each node pointing simply to the
next node in a linear fashion, each node points to a number of nodes. Tree is an example of a nonlinear
data structure. A tree structure is a way of representing the hierarchical nature of a structure
in a graphical form.
*/
/*
• The root of a tree is the node with no parents. There can be at most one root node in
a tree.
• An edge refers to the link from parent to child.
• A node with no children is called leaf node.
• Children of same parent are called siblings.
• A node p is an ancestor of node q if there exists a path from root to q and p appears
on the path. The node q is called a descendant of p.
• The set of all nodes at a given depth is called the level of the tree.
The root node is at level zero.
*/

// Binary Trees
/*
A tree is called binary tree if each node has zero child, one child or two children. Empty tree is
also a valid binary tree. We can visualize a binary tree as consisting of a root and two disjoint
binary trees, called the left and right subtrees of the root.
*/
/*
Types of Binary Trees:
-Strict Binary Tree: A binary tree is called strict binary tree if each node has exactly two
children or no children.
-Full Binary Tree: A binary tree is called full binary tree if each node has exactly two children
and all leaf nodes are at the same level.
-Complete Binary Tree:A binary tree is called complete binary tree if all leaf nodes are at height
h or h – 1 and also without anymissing number in the sequence.
*/

struct TreeNode{
    int val;
    TreeNode *left,*right;
  };
#define null nullptr;
class BinaryTree{
  private: 
  TreeNode *root;
  void insert(TreeNode *&, TreeNode *&);
  //traverse
  void displayInOrder(TreeNode *) ;
  void displayPreOrder(TreeNode *);
  void displayPostOrder(TreeNode *);
  void displayLevelOrder(TreeNode *);
  public:
  BinaryTree(){
    root=null;}
  //operation
  void insertNode(int);
  void display(int);
  bool search(int);
  int size(); // recursion:return size(right)+1+size(left) , iterative:any traverse technique..
    
};

//insert a node
void BinaryTree::insert(TreeNode *&root , TreeNode *&newNode){
  if(!root) root=newNode;
 
  else if(root->val > newNode->val) insert(root->left,newNode);
  else insert(root->right,newNode);
}
void BinaryTree::insertNode(int val){
  TreeNode *newNode = nullptr; // Pointer to a new node.

 // Create a new node and store num in it.
 newNode = new TreeNode;
  newNode->val = val; 
  newNode->left = newNode->right = nullptr;
 // Insert the node.
 insert(root, newNode);
}

//Traversaling the tree
//1)  PreOrder(DLR) Traversal : visit root->left->right;
//2)  InOrder(LDR) Traversal : visit left->root->right;
//3)  PostOrder(LRD)Traversal : visit left->right->root;
void BinaryTree::displayPreOrder(TreeNode *root){
  if(root){   
    cout<<root->val<<" ";
    displayInOrder(root->left);
    displayInOrder(root->right);
  }
}
void BinaryTree::displayInOrder(TreeNode *root){
   if(root){   
    displayInOrder(root->left);
    cout<<root->val<<" ";
    displayInOrder(root->right);
  }
}
void BinaryTree::displayPostOrder(TreeNode *root){
   if(root){   
    displayInOrder(root->left);  
    displayInOrder(root->right);
    cout<<root->val<<" ";
  }
}
// Level Order Traversal : 
/*
Visit the root.
While traversing level  keep all the elements at level +1 in queue.
Go to the next level and visit all the nodes at that level.
Repeat this until all levels are completed.
*/
void BinaryTree::displayLevelOrder(TreeNode *root){
  queue<TreeNode*> q;
  TreeNode *temp;
  if(!root) return;
  q.push(root);
  while(!q.empty()){
    temp=q.front();
    q.pop();
    cout<<temp->val<<" ";
    if(temp->left)
    q.push(temp->left);
    if(temp->right)
    q.push(temp->right);
  }
}
void BinaryTree::display(int ch){
  if(ch==1) displayPreOrder(root);
  else if(ch==2) displayInOrder(root);
  else if(ch==3) displayPostOrder(root);
  else displayLevelOrder(root);
}

bool BinaryTree::search(int val){
  TreeNode *nodeptr=root;
  while(nodeptr){
    if(nodeptr->val == val)  return true;
    else if(nodeptr->val > val)nodeptr=nodeptr->left;
    else nodeptr=nodeptr->right;
  }
  return false;
}

int BinaryTree::size(){
  stack<TreeNode*>q;
  q.push(root);
  int s=0;
  while(!q.empty()){
    TreeNode *temp=q.top();
    q.pop();
    s++;
    if(temp->left)q.push(temp->left);
    if(temp->right)q.push(temp->right);
  }
  return s;
}
//
int main(){
   BinaryTree b1;
   b1.insertNode(1);
   b1.insertNode(3);
   b1.insertNode(4);
   b1.insertNode(2);
   b1.insertNode(10);
   b1.insertNode(0);
   cout<<b1.search(5)<<" "<<b1.search(10);
  cout<<"\nsize: "<<b1.size();
   cout<<"\npreorder: ";b1.display(1);
   cout<<"\ninorder: ";b1.display(2);
   cout<<"\npostorder: ";b1.display(3);
   cout<<"\nlevel order: ";b1.display(4);
}