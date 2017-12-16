#include <iostream>
#include <sstream>
#include "Heap.hpp"
#include <vector>
#include "MST.hpp"
#include "Test.hpp"
#include <ctime>
using namespace std;
int main(int argc, const char * argv[]) {
    bool loop = true;
    vector<int> numInput;
    vector<string> result;
    while(loop){
        string input = "";
        getline(cin,input);
        istringstream iss(input);
        for(string s; iss >> s;)
            result.push_back(s);
        if(!result.empty()){
            if(result.front()=="HEAP"){
                for(int i=1;i<result.size();i++){
                    if(i!=0){
                        numInput.push_back(stoi(result[i]));
                    }
                }
                Heap a(numInput);
                a.buildHeap();
                a.getList();
                a.deleteMin();
                a.deleteMin();
                a.deleteMin();
                a.getList();
                loop = false;
            }else if(result.front()=="PRIM"){
                for(int i=1;i<result.size();i++){
                    if(i!=0){
                        numInput.push_back(stoi(result[i]));
                    }
                }
                MST b(numInput);
                b.prim(1);
                b.getList();
                loop = false;
            }else if(result.front()=="END"){
                loop = false;
            }else if(result.front()=="TEST"){
                Test c;
                MST test1(c.getGraph16());
                MST test2(c.getGraph32());
                MST test3(c.getGraph64());
                MST test4(c.getGraph128());
                MST test5(c.getGraph256());
                MST test6(c.getGraph1024());
                clock_t begin = clock();
                test1.prim(1);
                clock_t end = clock();
                double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC * 1000;
                cout<<elapsed_secs<<" ";
                begin = clock();
                test2.prim(1);
                end = clock();
                elapsed_secs = double(end - begin) / CLOCKS_PER_SEC * 1000;
                cout<<elapsed_secs<<" ";
                begin = clock();
                test3.prim(1);
                end = clock();
                elapsed_secs = double(end - begin) / CLOCKS_PER_SEC * 1000;
                cout<<elapsed_secs<<" ";
                begin = clock();
                test4.prim(1);
                end = clock();
                elapsed_secs = double(end - begin) / CLOCKS_PER_SEC * 1000;
                cout<<elapsed_secs<<" ";
                begin = clock();
                test5.prim(1);
                end = clock();
                elapsed_secs = double(end - begin) / CLOCKS_PER_SEC * 1000;
                cout<<elapsed_secs<<" ";
                begin = clock();
                test6.prim(1);
                end = clock();
                elapsed_secs = double(end - begin) / CLOCKS_PER_SEC * 1000;
                cout<<elapsed_secs<<" ";
                cout<<endl;
                loop = false;
            }
            result.clear();
        }
        numInput.clear();
    }
    return 0;
}

