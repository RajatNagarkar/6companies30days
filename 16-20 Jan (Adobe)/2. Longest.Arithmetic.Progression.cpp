#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int lengthOfLongestAP(int A[], int n) {
        int ans = 0;

        vector<vector<int>> dp(n, vector<int>(10001));

        for(int i = 0;i<n;i++) {
            for(int j = i + 1;j<n;j++) {
                
                int d = abs(A[j] - A[i]);

                dp[j][d] = max(dp[i][d] + 1, 2);

                ans = max(ans, dp[j][d]);
            }
        }
        return ans;
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

    cout<<obj.lengthOfLongestAP(arr, n);

    return 0;
}