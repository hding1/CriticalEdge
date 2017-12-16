#include <limits>
#define MAX numeric_limits<int>::max()
#include "MST.hpp"
MST::MST(vector<int> input){
    criticalWeight = MAX;
    int size = input.size()/3;
    adjacencyList.resize(4096+1);
    for(int i = 0;i<input.size();i+=3){
        int node1 = input[i];
        int node2 = input[i+1];
        int weight = input[i+2];
        adjacencyList[node1].push_back(make_pair(node2,weight));
        adjacencyList[node2].push_back(make_pair(node1,weight));
        weightToEdge[weight] = make_pair(node1,node2);
        vector<int>::iterator it;
        it = find(vertex.begin(),vertex.end(),node1);
        if(it==vertex.end()){
            vertex.push_back(node1);
            cityToIndex[node1] = vertex.size()-1;
            indexToCity[vertex.size()-1] = node1;
        }
        it = find(vertex.begin(),vertex.end(),node2);
        if(it==vertex.end()){
            vertex.push_back(node2);
            cityToIndex[node2] = vertex.size()-1;
            indexToCity[vertex.size()-1] = node2;
        }
    }
}
void MST::prim(int start){
    int difference = 0;
    bool contained[vertex.size()];
    if(vertex.empty()){
        return;
    }
    for(int i = 0;i<vertex.size();i++){
        contained[i] = false;
    }
    vector<int> dv;//weights
    for(int i = 0;i<vertex.size();i++){
        dv.push_back(MAX);
    }
    vector<int> pv;
    for(int i = 0;i<vertex.size();i++){
        pv.push_back(-1);
    }
    int startNode = start;
    int startIndex = cityToIndex[start];
    contained[startIndex] = true;
    dv[startIndex] = 0;
    int minCost = 0;
    for(int i=1;i<vertex.size();i++){
        Heap weightList;
        for(int j = 0; j<adjacencyList[startNode].size();j++){
            if(dv[cityToIndex[adjacencyList[startNode][j].first]]>adjacencyList[startNode][j].second){
                if(dv[cityToIndex[adjacencyList[startNode][j].first]]!=MAX){
                    pv[cityToIndex[adjacencyList[startNode][j].first]] = dv[cityToIndex[adjacencyList[startNode][j].first]] - adjacencyList[startNode][j].second;
                }
                dv[cityToIndex[adjacencyList[startNode][j].first]]=adjacencyList[startNode][j].second;
            }
        }
        for(int j = 0;j<vertex.size();j++){
            if(!contained[j]){
                weightList.add(dv[j]);
            }
        }
        minCost = weightList.deleteMin();
        int node2 = weightToEdge[minCost].second;
        if(contained[cityToIndex[node2]]){
            node2 = weightToEdge[minCost].first;
        }
        while(contained[cityToIndex[node2]]&&weightList.getSize()>0){
            minCost = weightList.deleteMin();
            node2 = weightToEdge[minCost].second;
            if(contained[cityToIndex[node2]]){
                node2 = weightToEdge[minCost].first;
            }
        }
        result.push_back(weightToEdge[minCost]);
        if(i==1){
            firstCost=minCost;
        }
        startNode = node2;
        startIndex = cityToIndex[node2];
        contained[startIndex] = true;
        dv[startIndex] = minCost;
    }
    int location = 0;
    for(int i = 0;i<pv.size();i++){
        if(difference < pv[i]){
            difference = pv[i];
            location = i;
        }
    }
    criticalWeight = dv[location];
}
void MST::getList(){
    cout<<firstCost<<endl;
    for(int i = 0;i<result.size();i++){
        if(result[i].first<result[i].second){
            cout<<result[i].first<<" "<<result[i].second<<" ";
        }else{
            cout<<result[i].second<<" "<<result[i].first<<" ";
        }
    }
    cout<<endl;
    if(weightToEdge[criticalWeight].first<weightToEdge[criticalWeight].second){
        cout<<weightToEdge[criticalWeight].first<<" "<<weightToEdge[criticalWeight].second;
    }else{
        cout<<weightToEdge[criticalWeight].second<<" "<<weightToEdge[criticalWeight].first;
    }
//    cout<<weightToEdge[criticalWeight].first<<" "<<weightToEdge[criticalWeight].second<<" ";
    cout<<endl;
}
