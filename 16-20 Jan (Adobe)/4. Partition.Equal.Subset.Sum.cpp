#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int equalPartition(int n, int arr[]) {
        int sum = 0;
        for(int i = 0;i<n;i++) {
            sum += arr[i];
        }   
        if(sum % 2) {
            return 0;
        }
        sum /= 2;
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, 0));

        for(int i = 0;i<=n;i++) {
            for(int j = 0;j<=sum;j++) {
                if(j == 0) {
                    dp[i][j] = true;
                } else if(i == 0) {
                    dp[i][j] = false;
                } else if(arr[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
                }
            }
        }
        return dp[n][sum];
    }
};

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i = 0;i<n;i++) {
        cin>>arr[i];
    }

    Solution obj;

    int ans = obj.equalPartition(n, arr);
    cout<<ans<<endl;
    ans == 1 ? cout<<"YES" : cout<<"NO";
    

    return 0;
}