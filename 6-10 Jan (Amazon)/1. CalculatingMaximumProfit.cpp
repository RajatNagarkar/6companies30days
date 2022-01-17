#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int maxProfit(vector<int> &prices, int k) {
            int n = prices.size();
            vector<vector<int>> dp(k+1, vector<int>(n, 0));
            for(int t = 1;t<=k;t++) {
                int maxProfit = INT_MIN;
                for(int d = 1;d<n;d++){
                    maxProfit = max(maxProfit, (dp[t-1][d-1] - prices[d-1]));
                    int profit = maxProfit + prices[d];
                    dp[t][d] = max(dp[t][d-1], profit);
                }
            }
            return dp[k][n-1];
        }
};

int main(){

    int n, k;
    cin>>n>>k;

    vector<int> prices(n);

    for(int i = 0;i<n;i++) {
        cin>>prices[i];
    }

    Solution obj;

    cout<<obj.maxProfit(prices, k);

    return 0;
}