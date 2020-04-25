#include <bits/stdc++.h>

using namespace std;


/*
A linked list is a data structure used for storing collections of data. A linked list has the following
properties.
• Successive elements are connected by pointers
• The last element points to NULL
• Can grow or shrink in size during execution of a program
• Can be made just as long as required (until systems memory exhausts)
• Does not waste memory space (but takes some extra memory for pointers). It
allocates memory as list grows.
*/

#define null NULL


class LinkedList{
   struct Node{
     struct Node *next;
     int data;
   };
   Node *head;
   public:
       LinkedList():head{null}{
           cout<<"a linked list has been created."<<endl;
       }
       ~LinkedList();
       void append(int);
       void insert(int);
       void remove(int);
       void display() const;
};

// AppEnd Node
/*
Create a new node.
Store data in the new node.
If there are no nodes in the list
Make the new node the first node.
Else
Traverse the list to find the last node.
Add the new node to the end of the list.
End If.
*/
void LinkedList::append(int data){
    Node *newNode,*nextNode=head;
    newNode = new Node;
    newNode->data = data;
    newNode->next =null;
    if(!head){
        head=newNode;
  cout<<data<<" appended"<<endl;
        return;
    }
    while(nextNode->next){
        nextNode = nextNode->next;
    }
    nextNode->next=newNode;
  cout<<data<<" appended"<<endl;
}

// Insert a Node
/*
Create a new node.
Store data in the new node.
If there are no nodes in the list
Make the new node the first node.
Else
Find the first node whose value is greater than or equal to the new
value, or the end of the list (whichever is first).
Insert the new node before the found node, or at the end of the list
if no such node was found.
End If.
*/

void LinkedList::insert(int data){
   Node *newNode,*nextNode=head,*prevNode=null;
   newNode = new Node;
   newNode->next=null;
   newNode->data=data;
   if(!head) head=newNode;
   else{
    while(nextNode && data > nextNode->data){
     prevNode=nextNode;
     nextNode=nextNode->next;
    }
     if(!prevNode){
        head=newNode;
        newNode->next = nextNode;
   }
   else {
   prevNode->next=newNode;
   newNode->next=nextNode;
   }
   }
  cout<<data<<" inserted"<<endl;
}

// Traverse list
/*
Assign List head to node pointer.
While node pointer is not null
Display the value member of the node pointed to by node pointer.
Assign node pointer to its own next member.
End While.
*/

void LinkedList::display() const{
    Node *nextNode=head;
    if(!head){
    cout<<"the list is empty"<<endl;
    return;
    }
 cout<<"display the list : ";
    while(nextNode){
        cout<<nextNode->data<<" ";
        nextNode=nextNode->next;
    }
    cout<<endl;
}

//Deleting a Node
/*
1. Remove the node from the list without breaking the links created by the next pointers.
2. Delete the node from memory.
*/
void LinkedList::remove(int data){
    Node *selected,*prev=null,*next=head;
    if(!head){
        cout<<"the list is empty"<<endl;
        return;
    }
    if(head->data == data){
        selected=head;
        head=head->next;
    }
    else{
    while(next->next && next->data != data){
        prev=next;
        next=next->next;
    }
    if(next->data != data){
      cout<<data<<" removed"<<endl;
        return;
    }
    selected=prev->next;
    next=selected->next;
    prev->next=next;
    }
     cout<<data<<" removed"<<endl;
    delete selected;
}

// destroy List

LinkedList::~LinkedList(){
    Node *next,*curr=head;
    cout<<"the list is going to destroy :"<<endl;
    while(curr){
        next=curr->next;
        cout<<curr->data<<" destroyed"<<endl;
        delete curr;
        curr=next;
    }
}
int main()
{
   LinkedList node;
   node.remove(2);
   node.append(17);
   node.append(1);
   node.append(10);
   node.append(-20);
   node.remove(1);
   node.append(2);
   node.insert(200);
   node.append(33);
   node.remove(33);
   node.append(3010);
   node.display();
}
