#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int findCoins(int i, int j, vector<int> &A, vector<vector<int>> &dp) {
        if(i > j) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int incThis = A[i] + min(findCoins(i+2, j, A, dp), findCoins(i+1, j-1, A, dp));
        int incOther = A[j] + min(findCoins(i, j-2, A, dp), findCoins(i+1, j-1, A, dp));
        dp[i][j] = max(incThis, incOther);

        return dp[i][j];
    }

    int maxCoins(vector<int> &A, int n) {
        vector<vector<int>> dp(501, vector<int>(501, -1));

        return findCoins(0, n-1, A, dp);
    }
};

int main(){
    int n;
    cin>>n;

    vector<int> A(n);

    for(int i = 0;i<n;i++) {
        cin>>A[i];
    }

    Solution obj;

    cout<<obj.maxCoins(A, n);
    

    return 0;
}