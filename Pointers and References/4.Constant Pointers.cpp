#include <bits/stdc++.h>
using namespace std;

// pointer arthimetic
int main() {
//constant pointer
   int x= 10,y=5;
     //-1 pointer to constant : the pointer itself can change but not its value;
       // const int *ptr_x{&x};
       //*ptr_x = 5; // error;
       //ptr_x = &y; //ok

    //-2 constant pointers : the pointer it self can't be change  and the value can change(oppsite of prev);
       //int *const ptr_x {&x};
       //*ptr_x = 5; // ok;
       //ptr_x = &y; //error;

     //-3 const poniter to const: we can not change either the address nor value;
       //const int *const ptr_x{&x};
        //*ptr_x = 5; // error;
         //ptr_x = &y; //error;

  }
