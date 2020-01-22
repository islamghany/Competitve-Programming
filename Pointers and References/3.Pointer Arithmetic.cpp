#include <bits/stdc++.h>
using namespace std;

// pointer arthimetic
int main() {
 /* int a[]={1,4,2,5,2,1,-1};
  int *ptr {a}; //here ptr point to the first el in a
  while(*ptr != -1){
    cout<<*ptr<<" ";
    ptr++; // here i increased the ptr to point the next el
  }*/

  /*
  int x=2,y=3,z=2;
  int *p1{&x},*p2{&y},*p3{&z};
  cout<<(p1 == p3)<<endl; // false; not the same address
  p2=&x;
  cout<<(p1==p2)<<endl; // true
  cout<<(*p1==*p3)<<endl; //true; the same value
  */

  //suppose name address = 1000 and char size is 1 byte and l = 1002 and o=1007
  // we want know the dist between 2 chars;
  char name[]="islam mostafa";
  char *ch_p1 {&name[2]},*ch_p2{&name[7]}; // l , o
  cout<<"in the string \""<<name<<"\" "<<*ch_p1<<" is "<<(ch_p2 -ch_p1)<<" chars away from "<<*ch_p2;

  }
