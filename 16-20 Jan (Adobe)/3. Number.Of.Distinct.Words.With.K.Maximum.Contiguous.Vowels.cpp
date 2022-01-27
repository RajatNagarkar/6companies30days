#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

class Solution {
    public:

    int kvowelWords(int n, int k) {
        const lli MOD = 1000000007;
        int i, j;
        vector<vector<lli>> dp(n+1, vector<lli>(k+1, 0));
        vector<lli> powerDP(n+1, 1);

        lli sum = 1;
        for(i = 1;i<=n;i++) {
            dp[i][0] = sum * 21;
            dp[i][0] %= MOD;

            sum = dp[i][0];

            for(j = 1;j<=k;j++) {
                if(j > i) {
                    dp[i][j] = 0;
                } else if(j == i) {
                    powerDP[i] = (powerDP[i-1] * 5ll) % MOD;

                    dp[i][j] = powerDP[i];
                }
                else {
                    dp[i][j] = dp[i-1][j-1] * 5;
                }
                dp[i][j] %= MOD;
                
                sum += dp[i][j];

                sum %= MOD;
            }
        }
        return sum;
    }
};

int main(){
    int N, K;
    cin>>N>>K;

    Solution obj;

    cout<<obj.kvowelWords(N, K);
    

    return 0;
}