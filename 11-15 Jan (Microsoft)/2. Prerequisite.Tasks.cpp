#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    vector<unordered_set<int>> makeGraph(int n, vector<pair<int, int>> &prerequisistes) {
        vector<unordered_set<int>> graph(n);

        for(auto i : prerequisistes) {
            graph[i.second].insert(i.first);
        }
        return graph;
    }

    bool dfs(vector<unordered_set<int>> &graph, int node, vector<bool> &path, vector<bool> &visited) {
        if(visited[node]){
            return false;
        }
        path[node] = visited[node] = true;

        for(int ngh : graph[node]) {
            if(path[ngh] || dfs(graph, ngh, path, visited)){
                return true;
            }
        }
        return path[node] = false;
    }

    bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
	    auto graph = makeGraph(n, prerequisites);
        
        vector<bool> path(n, false), visited(n, false);

        for(int i = 0;i<n;i++) {
            if(!visited[i] && dfs(graph, i, path, visited)) {
                return false;
            }
        }
        return true;
	}
};

int main(){
    int n,p;
    cin>>n>>p;

    vector<pair<int, int>> prerequisites;

    for(int i = 0;i<p;i++){
        int p1, p2;
        cin>>p1>>p2;
        prerequisites.push_back(make_pair(p1, p2));
    }
    Solution obj;

    cout<<obj.isPossible(n , prerequisites);

    return 0;
}