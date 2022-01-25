#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    void dfs(int v, vector<vector<int>> &g, vector<int> &vis, vector<int> &topo) {
        vis[v] = 1;
        
        for(auto x:g[v]) {
            if(!vis[x]){
                dfs(x, g, vis, topo);
            }
        }
        topo.push_back(v);
    }

    string findOrder(string dict[], int n, int k) {
        
        vector<vector<int>> g(k);

        for(int i = 0;i<n-1;i++){
            string w1 = dict[i];
            string w2 = dict[i+1];

            int limit = min(w1.length(), w2.length());

            for(int j = 0;i<limit;j++) {
                if(w1[i] != w2[i]) {
                    int u = w1[i] - 'a';
                    int v = w2[i] - 'a';
                    g[u].push_back(v);
                    break;
                }
            }
        }

        vector<int> vis(k, 0);
        vector<int> topo;
        for(int i = 0;i<k;i++) {
            if(!vis[i]) {
                dfs(i, g, vis, topo);
            }
        }
        string ans = "";
        int topoLen = topo.size();
        for(int i = 0;i<topoLen;i++){
            char ch = topo[i] + 'a';
            ans = ch + ans;
        }
        return ans;
    }
};

