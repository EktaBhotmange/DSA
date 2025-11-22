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

    void bfs() {
        queue<int> q;
        vector<bool> vis(v, false);
        
        q.push(0);
        vis[0] = true;

        while(q.size() > 0) {
            int u = q.front(); //u-v
            q.pop();

            cout << u << " ";

            for(int v : l[u]) {  // v -> immediate neighb
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                } 
            }
        }

        cout << endl;
    }

};

int main() {
    Graph g(4);
    
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    
    g.bfs();
    return 0;
}