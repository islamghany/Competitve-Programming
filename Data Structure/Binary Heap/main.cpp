#include <iostream>
using namespace std;

class MinHeap{
    int *arr; // the array list
    int capacity; // the maximun number of element
    int currSize; //current size of the Heap

    // Children of a Node
    //for a node at i-th location, its children are at (2 * i + 1) and 2 * i + 2 locations
    //Time Complexity: O(1);
    int leftChild(int i){
        int l =(2*i + 1);
        if(l >= currSize) return -1;
        return l;
    }
    int rightChild(int i){
        int r = (2*i + 2);
        if(r >= currSize) return -1;
        return r;
    }

    void MinHeapify(int i){
        int l = leftChild(i), r = rightChild(i), mn=i,temp;
        if(l != -1 && arr[i] > arr[l]) mn=l;
        if(r != -1 && arr[mn] > arr[r]) mn=r;
        if(mn != i){
            temp = arr[i];
            arr[i]=arr[mn];
            arr[mn]=temp;
            MinHeapify(mn);
        }
    }

    public:
    MinHeap(int sz){
        arr = new int[sz];
        capacity = sz;
        currSize=0;
    }
    //O(1)
    int top(){
        if(currSize <= 0) return -1;
        return arr[0];
    }
    // Increase the heap size
    // Keep the new element at the end of the heap (tree)
    // Heapify the element from bottom to top (root)
    // log(logn);
    void push(int data){
        int i;
        if(currSize == capacity) capacity++; // expand the heap by 1;
        currSize++;
        i=currSize-1; // last node
        while(i > 0 && data < arr[(i-1)/2]){ // parent > pushed element;
        arr[i]=arr[(i-1) / 2];
        i =(i-1) / 2;
        }
        arr[i] = data;
    }
    // Copy the first element into some variable
    // Copy the last element into first element location
    // PercolateUp the first element
    //O(logn)
    void pop(){
        if(currSize<= 0) return;
        arr[0] =arr[currSize-1];
        --currSize;
        MinHeapify(0);
    }
    //Destroying Heap
    //log(1)
    void destroy(){
        if(arr == NULL) return;
        delete(arr);
        arr=NULL;
        currSize=0;
    }
};

int main() {
/*	
    MinHeap h(11);
    h.push(3);
    h.push(2);
    h.pop();
    h.push(15);
    h.push(5);
    h.push(4);
    h.pop();
    h.push(45);
    cout << h.top() << " ";  //4
    */
    // heap sort
    // 1)inserts all elements (from an unsorted array) into a heap
    // 2)removes them from the root of a heap until the heap is empty
    int n,item; cin>>n;
    int a[n];
    MinHeap h(n);
    for(int i=0;i<n;i++){
        cin>>item;
        h.push(item);
    }
    for(int i = 0; i<n;i++){
        a[i]= h.top(); h.pop();

    }
     for(int i = 0; i<n;i++){
        cout<<a[i]<<" ";
    }
	return 0;
}
