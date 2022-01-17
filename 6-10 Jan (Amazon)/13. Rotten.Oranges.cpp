#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int orangesRotting(vector<vector<int>> &grid) {
        if(grid.size() == 0){
            return 0;
        }
        int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt = 0;
        queue<pair<int, int>> rOranges;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] != 0) {
                    tot++;
                }
                if(grid[i][j] == 2) {
                    rOranges.push({i, j});
                }
            }
        }

        int dx[4] = {0,0,1,-1};
        int dy[4] = {-1,1,0,0};

        while(!rOranges.empty()) {
            int k = rOranges.size();

            cnt += k;

            while(k--) {
                int x = rOranges.front().first, y = rOranges.front().second;
                rOranges.pop();
                for(int i = 0;i<4;i++){
                    int nx = x+dx[i], ny = y+dy[i];

                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) {
                        continue;
                    }
                    rOranges.push({nx, ny});
                    grid[nx][ny] = 2;
                }
            }
            if(!rOranges.empty()) {
                days++;
            }
        }
        return tot == cnt ? days : -1;
    }
};

int main(){

    int m, n;

    cin>>m>>n;
    vector<vector<int>> grid;
    for(int i = 0;i<m;i++) {
        vector<int> v(n);
        for(int j = 0;j<n;j++) {
            cin>>v[j];
        }
        grid.push_back(v);
    }

    Solution obj;

    cout<<obj.orangesRotting(grid);

    return 0;
}