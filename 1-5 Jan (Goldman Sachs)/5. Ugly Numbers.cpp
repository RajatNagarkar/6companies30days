#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

class Solution{
public:	
	lli getNthUglyNo(int n) {
	    int c2 = 0, c3 = 0, c5 = 0;
	    vector<lli> dp(n+1);
	    dp[0] = 1;
	    for(int i = 1;i<n;i++){
	        lli dp2 = 2 * dp[c2];
	        lli dp3 = 3 * dp[c3];
	        lli dp5 = 5 * dp[c5];
	        dp[i] = min({dp2, dp3, dp5});
	        
	        if(dp2 == dp[i]){
	            c2++;
	        } 
            if(dp3 == dp[i]){
	            c3++;
	        }
            if(dp5 == dp[i]) {
	            c5++;
	        }
	    }
	    return dp[n-1];
	}
};

int main(){
    int n;
    cin>>n;

    Solution obj;

    cout<<obj.getNthUglyNo(n);
    return 0;
}