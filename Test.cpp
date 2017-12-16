#include "Test.hpp"
#include <algorithm>
bool contained(vector<int> list, int key);
vector<int> generateVertexSet(int k);
vector<int> makeGraph(int num);
Test::Test(){
    graph16 = makeGraph(16);
    graph32 = makeGraph(32);
    graph64 = makeGraph(64);
    graph128 = makeGraph(128);
    graph256 = makeGraph(256);
    graph1024 = makeGraph(1024);
}
vector<int> Test::getGraph16(){
    return graph16;
}
vector<int> Test::getGraph32(){
    return graph32;
}
vector<int> Test::getGraph64(){
    return graph64;
}
vector<int> Test::getGraph128(){
    return graph128;
}
vector<int> Test::getGraph256(){
    return graph256;
}
vector<int> Test::getGraph1024(){
    return graph1024;
}
vector<int> generateVertexSet(int k){
    vector<int> result;
    int randomNum=1;
    for(int i = 0; i<k;i++){
        while(contained(result,randomNum)){
            randomNum = rand()%4096;
        }
        result.push_back(randomNum);
    }
    return result;
}

vector<int> makeGraph(int num){
    vector<int> vertex = generateVertexSet(num);
    vector<int> result;
    vector<int> weight;
    for(int i=1;i<=num;i++){
        weight.push_back(i);
    }
    int randomNum = 0;
    random_shuffle(vertex.begin(),vertex.end());
    random_shuffle(weight.begin(),weight.end());
    for(int i = 0; i < vertex.size();i++){
        for(int j = i+1 ; j < vertex.size();j++){
            result.push_back(vertex[i]);
            result.push_back(vertex[j]);
            result.push_back(weight[0]);
            randomNum++;
        }
    }
    return result;
}
bool contained(vector<int> list, int key){
    vector<int>::iterator it;
    it = find(list.begin(),list.end(),key);
    if(it==list.end()){
        return false;
    }
    return true;
}
