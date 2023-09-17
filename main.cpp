#include "PCB.h"
#include "llistPCB.h"
#include <chrono>
using namespace std::chrono;
LinkedList list;
PCB pcb;
int llistTime(int loops, int dataToAdd){
    auto start = high_resolution_clock::now();
    while(loops > 0){
    for(int i = 1; i<= dataToAdd; i++){
        list.addNode(i);
        loops -= 1;
        list.deleteNode(dataToAdd/10);
    }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    return duration.count();
}

int dictTime(int loops, int dataToAdd){
    auto start = high_resolution_clock::now();
    while(loops > 0){
        for(int i = 1; i< dataToAdd; i++){
            pcb.addChild(dataToAdd-1, dataToAdd);
            loops--;
            pcb.destroyTail(dataToAdd/2);
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    return duration.count();
}

int main(){
    cout<< "Linked List time: " << llistTime(1, 10000) << " microseconds" << endl;
    cout << "My method using maps (Dictionaries): " << dictTime(1,10000)<< " microseconds" << endl;
}

