#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int minDifference(int arr[], int n) {
        int sum = 0;
        for(int i = 0;i<n;i++) {
            sum += arr[i];
        }
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1));
        
        for(int i = 0;i<=n;i++) {
            for(int j = 0;j<=sum;j++) {
                if(j == 0) {
                    dp[i][j] = true;
                } else if(i == 0) {
                    dp[i][j] = false;
                } else if(arr[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
            }
        }
        int diff = INT_MAX;
        for(int i = sum/2;i >= 0;i--) {
            if(dp[n][i]){
                diff = sum - (2*i);
                break;
            }
        }
        return diff;
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

    cout<<obj.minDifference(arr, n);

    return 0;
}