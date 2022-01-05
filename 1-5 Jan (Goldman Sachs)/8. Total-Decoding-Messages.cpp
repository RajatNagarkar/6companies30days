#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int countWays(string str) {
        int n = str.size();
        int dp[n+1];

        long long int mod = 1e+9;

        dp[0] = 1;
        dp[1] = 1;

        if(str[0] == '0'){
            return 0;
        }
        for(int i = 2;i<=n;i++) {
            if(str[i-1] == '0' && str[i-2] != '0'){ //Where First Digit is Zero & Second is Not
                int num = stoi(str.substr(i-2, 2));
                if(num > 26){
                    dp[i] = 0;
                }
                else {
                    dp[i] = dp[i-2]%mod;
                }
            }
            else if(str[i-1] != '0'  && str[i-2] == '0'){ //Where First Digit is Not Zero but second Is
                dp[i] = dp[i-1]%mod;
            }
            else if(str[i-1] == '0' && str[i-2] == '0'){ //Where First Ans Seciond Digit both are Zero
                dp[i] = 0;
            } else { //Where both digits are not Zero
                int num = stoi(str.substr(i-2,2));
                if(num > 26){
                    dp[i] = dp[i-1]%mod;
                } else {
                    dp[i] = (dp[i-1] + dp[i-2])%mod;
                }
            }
        }
        return dp[n];
    }
};

int main(){
    string str;
    cin>>str;
    
    Solution obj;

    cout<<obj.countWays(str);

    return 0;
}