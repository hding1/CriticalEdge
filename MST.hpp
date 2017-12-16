#ifndef MST_hpp
#define MST_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <list>
#include <map>
#include "Heap.hpp"
using namespace std;

class MST
{
public:
    //Constructor
    MST(vector<int> input);
    //Modifier
    void prim(int start);
    //Observer
    void getList();
private:
    //pair.first = destiantion
    //pair.second = weight
    int firstCost;
    int criticalWeight;
    vector<pair<int,int>> result;
    map<int,int> cityToIndex;
    map<int,int> indexToCity;
    map<int,pair<int,int>> weightToEdge;
    vector<int> vertex;
    vector< vector< pair<int, int> > > adjacencyList;
};
#endif /* MST_hpp */
