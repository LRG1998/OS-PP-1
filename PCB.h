#include <map>
#include<iostream>

using namespace std;

class PCB{
    private:
        map<int, int> pcb;
    public:
    PCB(){
        pcb[0] = 0;
    }
    void addChild(int parent, int maxChild){
        int childrenToAdd;
        if(pcb.size() >1){
            childrenToAdd = maxChild;
        }
        else{
            childrenToAdd = maxChild -1;
        }
        while(childrenToAdd >= 1){
            pcb[pcb.end()->first + 1] = parent;
            childrenToAdd -=1;
        }
    }
    void printPCB(){
        if(pcb.size() == 1){
            cout<<"Only the head. \n";
        }else{
        for(int i = 1; i<pcb.size();i++){
            cout<<"Parent: " << pcb[i] << " ";
            cout << "Node: " << i << "\n";
        };
        }
    }
    void destroyTail(int startVal){
        for(int i  = pcb.size()-1; i >startVal; i--){
            pcb.erase(i);
        };
    }
};