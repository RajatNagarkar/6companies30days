#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    bool isSafe(vector<vector<int>> &grid, int r, int c, int n, int m, vector<vector<bool>> &visited){
        bool row = r >= 0 and r < n;         //Check if row is valid;
        bool col = c >= 0 and c < m;         //Check if col is valid;
        bool isOne = false;            //Check if the current element is '1'
        bool isVisited = false;  //Check if current element is visited before

        if(row and col) {
            isOne = grid[r][c];
            isVisited = !visited[r][c];
        }
        // cout<<row<<col<<isOne<<isVisited<<"\n";
        return (row and col and isOne and isVisited);
    }
    void dfs(vector<vector<int>> &grid, int r, int c, int n, int m, vector<vector<bool>> &visited, int &count) {
        static int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        static int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        if(!isSafe(grid, r, c, n, m, visited))
            return;
        visited[r][c] = true;
        for(int k = 0;k<8;k++){
            if(isSafe(grid, r+dx[k], c+dy[k], n, m, visited)) {
                count++;
                dfs(grid, r+dx[k], c+dy[k], n, m, visited, count);
            }
        }
    }

    int findMaxArea(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int ans = INT_MIN;

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++){

                if(grid[i][j] and !visited[i][j]){

                    int count = 1;
                    dfs(grid, i, j, n, m, visited, count);
                    ans = max(ans, count);
                }
            }
        }
        return ans;
    }
};

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m, -1));

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    Solution obj;

    cout<<obj.findMaxArea(grid);
    return 0;
}