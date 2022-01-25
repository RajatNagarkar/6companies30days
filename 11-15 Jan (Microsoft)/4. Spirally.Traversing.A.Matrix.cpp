#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat, int m, int n) {
        vector<int> ans;
        int ind = 0;
        int i, k = 0, l = 0;

        while(k < m && l < n) {
            for(i = l;i<n;i++){
                ans.push_back(mat[k][i]);
            }
            k++;

            for(i = k;i<m;i++){
                ans.push_back(mat[i][n-1]);
            }
            n--;

            if(k < m) {
                for(i = n-1;i>=l;i--){
                    ans.push_back(mat[m-1][i]);
                }
                m--;
            }

            if(l < n) {
                for(i = m-1;i>=k;i--) {
                    ans.push_back(mat[i][l]);
                }
                l++;
            }
        }
        return ans;
    }
};

int main(){

    int r, c;
    cin>>r>>c;

    vector<vector<int>> mat(r, vector<int>(c));

    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin>>mat[i][j];
        }
    }
    Solution obj;
    vector<int> ans = obj.spirallyTraverse(mat, r, c);

    for(auto x : ans) {
        cout<<x<<" ";
    }
    return 0;
}