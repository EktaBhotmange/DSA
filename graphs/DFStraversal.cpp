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

    void dfsHelper(int u, vector<bool> &vis) {
        cout << u << " ";
        vis[u] = true;

        for(int v : l[u]) {
            if(!vis[v]) {
                dfsHelper(v, vis);
            }
        }
    }

    void dfs() {
        int src = 0;
        vector<bool> vis(v, false);

        // for(int i=0; i<v; i++) {
        //     if(!vis[i]) {
        //         dfsHelper(src, vis);
        //     }
        // }       ===>> for disconnected graphs

        dfsHelper(src, vis);
    }
};

int main() {
    Graph g(4);
    
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    
    g.dfs();
     
    return 0;
}