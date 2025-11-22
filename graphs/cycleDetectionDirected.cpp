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
        // l[v].push_back(u);
    }

    bool isCycleDirDFS(int curr, vector<bool> &vis, vector<bool> &recPath) {
        vis[curr] = true;
        recPath[curr] = true;

        for(int v : l[curr]) {
            if(!vis[v]) {
                if(isCycleDirDFS(v, vis, recPath)) {
                    return true;
                }
            } else if(recPath[v]) {    
                return true;
            }
        }
        recPath[curr] = false;  
        return false;           
    }

    bool isCycleDir() {
        vector<bool> vis(v, false);
        vector<bool> recPath(v, false);

            for(int i = 0; i < v; i++) {
                if(!vis[i]) {
                    if(isCycleDirDFS(i, vis, recPath)) {
                        return true;
                    }
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
    
    cout << g.isCycleDir() << endl;

    return 0;
}