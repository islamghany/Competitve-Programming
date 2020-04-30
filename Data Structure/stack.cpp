#include <iostream>
using namespace std;

//stack :A stack is an ordered list in which insertion and deletion are done at one end, called
//top. The last element inserted is the first one to be deleted. Hence, it is called the Last in First out
//(LIFO) or First in Last out (FILO) list

//Main stack operations
//Push (int data): Inserts data onto stack.
//int Pop(): Removes and returns the last inserted element from the stack.

//Auxiliary stack operations
//int Top(): Returns the last inserted element without removing it.
//int Size(): Returns the number of elements stored in the stack.
//int IsEmpty(): Indicates whether any elements are stored in the stack or not.
//int IsFull(): Indicates whether the stack is full or not.

//static and dynamic stack:There are two types of stack data structure: static and dynamic. Static stacks have a fixed size
//and are implemented as arrays. Dynamic stacks grow in size as needed and are implemented
//as linked lists.

//1)Static Stack
#define MAX 1000 
class StaticStack{
  private:
  int stackArray[MAX];
  int stackSize;
  int peek;
  public:
    // Constructor
    StaticStack(int);
    //operation();
     void push(int); 
     void pop();
     int top();
     bool isEmpty();
     bool isFull();
};
StaticStack::StaticStack(int s){
  stackSize=s;
  peek=-1;
}

void StaticStack::push(int el){
  if(isFull()){
    cout<<"the stack is full"<<endl;
    return;
  }
  stackArray[++peek]=el;
}
void StaticStack::pop(){
  if(isEmpty()){
    cout<<"the stack is empty"<<endl;
    return;
  }
  peek--;
}
int StaticStack::top(){ 
  if(isEmpty()){
    cout<<"the stack is empty"<<endl;
    return -1;
  }
  return stackArray[peek];
}
bool StaticStack::isFull(){
  if(peek == stackSize-1) return true;
  return false;
}

bool StaticStack::isEmpty() 
{ 
    return (peek < 0); 
}


//dynamic stack :A stack may be implemented as a linked list and expand or shrink with
//each push or pop operation.

class DynamicStack{
  private:
  struct StackNode{
    int val;
    StackNode *next;
  };
  StackNode *head;
  int stackSize;
  public:
  //constructor
  DynamicStack(){head=nullptr;stackSize=0;}
  //destructor
  ~DynamicStack();
  //operation();
  void push(int); 
  void pop();
  int top();
  bool isEmpty();
  int size();
  
};
DynamicStack::~DynamicStack(){
  StackNode *curr=head,*next=nullptr;
  while(curr){
    next = curr->next;
    delete curr;
    curr=next;
  }
}

void DynamicStack::push(int val){
  StackNode *newNode = new StackNode;
  stackSize++;
  newNode->val=val;
  if(isEmpty()){
    head=newNode;
    newNode->next=nullptr;
    return;
  }
  newNode->next =head;
  head=newNode;
}
void DynamicStack::pop(){
  if(isEmpty()){
    cout<<"the stack is empty."<<endl;
    return;
  }
  stackSize--;
  StackNode *curr=head;
  head=head->next;
  delete curr;
}

int DynamicStack::top(){
   if(isEmpty()){
    cout<<"the stack is empty."<<endl;
    return -1;
  }
  return head->val;
}
bool DynamicStack::isEmpty(){
  return !head ? true : false;
}
int DynamicStack::size(){
  return stackSize;
}
int main(){
 	/*
    StaticStack s(4); 
   
    s.push(20); 
    s.push(30); 
    cout<<s.top()<<endl; // 30;
    s.pop();
    cout<<s.top()<<endl;//20
    s.push(10); 
    cout<<s.top()<<endl; //10
    s.push(2);
    s.push(1); 
    s.push(10); // the stack is empty
    cout<<s.top()<<endl;
   cout<<s.isFull(); // true
   */
   DynamicStack ds;
   ds.pop(); // the stack is empty;
   cout<<ds.isEmpty()<<endl; // true
   ds.push(10);
   cout<<ds.top()<<endl; // 10
   ds.push(20);
   ds.pop();
   ds.push(40);
   cout<<ds.top()<<endl; //40
   ds.push(50);
   cout<<ds.top()<<endl; //50
   cout<<ds.size()<<endl; //3;
}