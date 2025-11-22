#include <iostream>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

class Graph {
    int v;
    list<int> *l;  //int *arr

public:
    Graph(int v) {
        this->v = v;
        l = new list<int>[v];
        //arr = new int[v]
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdList() {
        for (int i = 0; i < v; i++) {
            cout << i << " -> ";
            for (int node : l[i]) {
                cout << node << " ";
            }
            cout << endl; 
        }
    }

};

int main() {
    Graph g(4);
    
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    
    g.printAdList();
    
    return 0;
}