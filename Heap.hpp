#ifndef Heap_hpp
#define Heap_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Heap
{
public:
    //Constructor
    Heap();
    Heap(vector<int> list);
    //Modifier
    void add(int num);
    void buildHeap();
    int deleteMin();
    void percolateDown(int parent);
    void percolateUp(int child);
    //Observer
    void getList();
    int getSize();

private:
    //child1 = parent*2+1
    //child2 = parent*2+2
    //parent = (child-1)/2
    vector<int> heapList;
    int smallerChild(int parent);
    void swap(int a, int b);
//  void buildHeapHelper(int current,)
};
#endif /* Heap_hpp */
