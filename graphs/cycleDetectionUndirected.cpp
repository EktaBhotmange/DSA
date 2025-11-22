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

    bool isCycleUndiBFS(int src, int par, vector<bool> &vis) {  //dfs algo
        vis[src] = true;
        list<int> neighbors = l[src];

        for(int v : neighbors) {
            if(!vis[v]) {
                if(isCycleUndiBFS(v, src, vis)) {
                    return true;
                }
            } else if(v != par) {
                return true;
            }
        }

        return false;
    }

    bool isCycle() {
        vector<bool> vis(v, false);

        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                if(isCycleUndiBFS(i, -1, vis))
                return true;
            } 
        }

        return false;
    }
};

int main() {
    Graph g(4);
    
    g.addEdge(1, 0);
    // g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    
    cout << g.isCycle() << endl;

    return 0;
}