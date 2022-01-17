#include<bits/stdc++.h>

using namespace std;

class Solution {
    private:
    void getParanthesis(vector<vector<int>> &bracket, int i, int j, int n, char &name, string &str) {
        if(i > j || i >=n || j >= n) {
            return;
        }
        if(i == j){
            str += name;
            name++;
            return;
        }
        str += '(';

        getParanthesis(bracket, i , bracket[i][j], n, name, str);
        getParanthesis(bracket, bracket[i][j] + 1, j, n, name, str);

        str += ')';
        
    }
    public:
    string matrixChainOrder(int p[], int n) {
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> bracket(n, vector<int>(n));

        char name = 'A';
        string ans = "";

        for(int i = 0;i<n;i++){
            dp[i][i] = 0;
        }

        for(int gap = 2;gap<n;gap++) {
            for(int i  = 0;i<=(n - gap);++i) {
                int j = i + gap - 1;

                dp[i][j] = INT_MAX;
                
                for(int k = i;k<j;k++) {
                    int cost = dp[i][k] + dp[k+1][j] + (p[i-1] * p[k] * p[j]);

                    if(cost < dp[i][j]) {
                        dp[i][j] = cost;
                        bracket[i][j] = k;
                    }
                }
            }
        }
        getParanthesis(bracket, 1, n-1, n, name, ans);

        return ans;
    }
};

int main(){
    int n;
    cin>>n;

    int p[n];

    for(int i = 0;i<n;i++) {
        cin>>p[i];
    }

    Solution obj;
    cout<<obj.matrixChainOrder(p, n);

    return 0;
}