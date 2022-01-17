#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
    int n = 9;
    int empty = 0;
    int isValid(vector<vector<int>> &mat) {
        return isRowValid(mat) and isColValid(mat) and isBoxValid(mat);
    }

    bool isRowValid(vector<vector<int>> &mat) {
        for(int row = 0;row < n;row++){
            map<int, int> sdk;

            for(int ele = 0;ele<n;ele++) {
                int val = mat[row][ele];
                if(val != empty) {
                    if(sdk.find(val) != sdk.end()){
                        return false;
                    }
                    sdk[val] = 1;
                }
            }
        }
        return true;
    }

    bool isColValid(vector<vector<int>> &mat) {
        for(int row = 0;row < n;row++){
            map<int, int> sdk;

            for(int ele = 0;ele<n;ele++) {
                int val = mat[ele][row];
                if(val != empty) {
                    if(sdk.find(val) != sdk.end()){
                        return false;
                    }
                    sdk[val] = 1;
                }
            }
        }
        return true;
    }

    bool isBoxValid(vector<vector<int>> &mat) {
        for(int i = 0;i<9;i+=3) {
            for(int j = 0;j<9;j+=3) {
                if(!checkBox(mat, i, j)){
                    return false;
                }
            }
        }
        return true;
    }

    bool checkBox(vector<vector<int>> &mat, int startRow, int startCol) {
        int endCol = startCol + 3;
        int endRow = startRow + 3;
        map<int, int> gridMap;
        for(int i = startRow;i < endRow; i++){
            for(int j = startCol;j < endCol; j++){
                int val = mat[i][j];
                if(val != empty) {
                    if(gridMap.find(val) != gridMap.end()) {
                        return false;
                    }
                    gridMap[val] = 1;
                }
            }
        
        }
        return true;
    }
};

int main(){
    int n = 9;
    vector<vector<int>> mat(n, vector<int>(9));
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            cin>>mat[i][j];
        }
    }
    
    Solution obj;

    cout<<obj.isValid(mat);
    return 0;
}