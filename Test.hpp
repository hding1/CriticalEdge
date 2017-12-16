#ifndef Test_hpp
#define Test_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <list>
#include <map>
using namespace std;

class Test
{
public:
    //Constructor
    Test();
    //Modifier
    
    //Observer
    vector<int> getGraph16();
    vector<int> getGraph32();
    vector<int> getGraph64();
    vector<int> getGraph128();
    vector<int> getGraph256();
    vector<int> getGraph1024();
private:
    vector<int> graph16;
    vector<int> graph32;
    vector<int> graph64;
    vector<int> graph128;
    vector<int> graph256;
    vector<int> graph1024;
};
#endif /* Test_hpp */
