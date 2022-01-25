#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int c, d;
    vector<int> disT;
    vector<int> lowT;
    vector<bool> visited;
    vector<int> parent;
    void getBridge(int u, vector<int> adj[], bool &isBridge) {
        static int time = 0;

        visited[u] = true;

        disT[u] = lowT[u] = ++time;

        for(auto x : adj[u]) {
            int v = x;
            if(!visited[v]) {
                parent[v] = u;

                getBridge(v, adj, isBridge);

                lowT[u] = min(lowT[u], lowT[v]);

                if(lowT[v] > disT[u]){
                    if((u == c && v == d) || (u == d and v ==c)){
                        isBridge = true;
                    }
                }
            } else if(v != parent[u]) {
                lowT[u] = min(lowT[u], disT[v]);
            }
        }
    }

    int isBridge(int V, vector<int> adj[], int c, int d) {
        this->c = c;
        this->d = d;
        bool isBridge = false;

        disT.resize(V);
        lowT.resize(V);
        visited.resize(V, 0);
        parent.resize(V, -1);

        for(int i = 0;i<V;i++) {
            if(!visited[i]) {
                getBridge(i, adj, isBridge);
            }
        }
        return isBridge;
    }
};

int main(){

    int V, E;
    cin>>V>>E;

    vector<int> adj[V];

    for(int i = 0;i<E;i++) {
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int c,d;

    cin>>c>>d;

    Solution obj;

    cout<<obj.isBridge(V, adj, c, d);

    return 0;
}