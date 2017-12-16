#include "Heap.hpp"
int isLeaf(int parent,int size);
Heap::Heap(){
}
Heap::Heap(vector<int> list){
    heapList = list;
}
void Heap::buildHeap(){
    for(int i = heapList.size()/2;i>=0;i--){
        percolateDown(i);
        if(i==heapList.size()/2-1){
            getList();
        }
    }
}
void Heap::percolateDown(int parent){
    bool heap_ok = false;
    int current = parent;
    int smallerChildIndex;
    while(!heap_ok&&!isLeaf(current,heapList.size())){
        smallerChildIndex = smallerChild(current);
        if(heapList[current]>heapList[smallerChildIndex]){
            swap(current,smallerChildIndex);
            current = smallerChildIndex;
        }else{
            heap_ok = true;
        }
    }
}
void Heap::add(int num){
    heapList.push_back(num);
    percolateUp(heapList.size()-1);
}
void Heap::percolateUp(int child){
    int parent = (child-1)/2;
    if(child!=0&&heapList[child]<heapList[parent]){
        swap(child,parent);
        percolateUp(parent);
    }
}
int Heap::smallerChild(int parent){
    int child1 = parent*2+1;
    int child2 = parent*2+2;
    if((child2)>=heapList.size()){
        return child1;
    }else{
        if(heapList[child1]<heapList[child2]){
            return child1;
        }else{
            return child2;
        }
    }
}
int isLeaf(int parent,int size){
    if(parent*2+2>size){
        return true;
    }
    return false;
}
void Heap::swap(int a, int b){
    int temp = heapList[a];
    heapList[a] = heapList[b];
    heapList[b] = temp;
}
void Heap::getList(){
    for(int i = 0;i<heapList.size();i++){
        cout<<heapList[i]<<" ";
    }
    cout<<endl;
}
int Heap::deleteMin(){
    if(heapList.size()>0){
        int result= heapList.front();
        swap(0,heapList.size()-1);
        heapList.pop_back();
        percolateDown(0);
        return result;
    }
    return 0;
}
int Heap::getSize(){
    return heapList.size();
}
