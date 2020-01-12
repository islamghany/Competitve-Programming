#include <bits/stdc++.h>
using namespace std;

// dynamic memory allocation
int main() {
  //  int *p{nullptr};
  //  p = new int; //allocate an integer on the heap;
  //  *p=5;
  //  cout<<*p;
  //  delete p; //frees the allocated storage


  // double *temp_ptr{nullptr};
  // size_t size;
  // cout<<"enter the number of temps: ";
  // cin>>size;

  // temp_ptr=new double[size];
  // cout<<temp_ptr<<endl;

  // //temp_ptr=nullptr; // memory leak; dont miss the address
  // delete [] temp_ptr;

  // array poniter
  // by default array name is the address of the array thet i don't need to put & when point to array
  int arr[3]={1,2,3};
  int *arr_ptr{arr};
  cout<<*(arr_ptr+1)<<endl; // (address + 4byte) => 1 specify the size of the data type
  cout<<*(arr+1)<<endl;
}
