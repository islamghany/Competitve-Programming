#include <bits/stdc++.h>
using namespace std;

// pointer & refrences
int main() {

  // pointers are variables can be changed;
  // pointer can be null or uninitialize;
  // int num{4};
  // cout<<"the value of num : "<<num<<endl;
  // cout<<"the sizeof num : "<<sizeof num<<endl;
  // cout<<"the address of num : "<<&num<<endl;

  // int *p;//garbge we can use nullptr or nullprt address zero
  // cout<<"the value of p : "<<p<<endl; // garbge
  // cout<<"the sizeof p : "<<sizeof p<<endl;
  // cout<<"the address of p : "<<&p<<endl;
  // p=nullptr;
  // cout<<"the value of p : "<<p<<endl;


  // double d{100.4};
  // int x=13;

  // int *ptr_x{&x};
  // cout<<"the value of x "<<x<<endl;
  // cout<<"the address of x "<<&x<<endl;
  // cout<<"the vlaue of ptr_x "<<ptr_x<<endl; // ptr_x == &x
  // cout<<"access the data we are point to (dereferencing a pointer) "<<*ptr_x<<endl;
  //// ptr_x =&d;  cout<<ptr_x; //// error because the address of d is more than the value of ptr_x


  vector<string> names{"ahmed","islam","mohamed"};
  vector<string> *namesptr{&names};
  cout<<(*namesptr)[1]<<endl; //islam
  for(auto name: *namesptr){
    cout<<name<<" ";
  }
  cout<<endl;


}
