#include <bits/stdc++.h>
using namespace std;

void doubleValue(int *v){
  *v*=2;
  //cout<<" d "<<v;
}
int *createArr(int size,int initialValue=0){
  int *newArray = new int[size];
  for(int i=0;i<size;i++){
      *(newArray+i)=initialValue;
  }
  return newArray;
}
void display(const int * arr,int size){
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }
}
int main() {
  // passing pointers to function
  // 1) pass with ref
  /*int x=2,*ptr{nullptr};
  cout<<x<<endl;
  doubleValue(&x);
  cout<<x<<endl; //4;
  ptr=&x;
  doubleValue(ptr);
  cout<<x<<endl; //8
  */
  // return a pointer from function
  int s,iv;cout<<"enter the size of the array : "<<endl; cin>>s;
  cout<<"enter the intitial value of the array : "<<endl; cin>>iv;
  int *ptr=createArr(s,iv);
  display(ptr,s);
  delete []ptr;
}
