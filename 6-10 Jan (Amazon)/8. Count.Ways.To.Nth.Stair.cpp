#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        long long countWays(int m) {

            return (m/2)+1;

            // vector<long long> cW(m+1);
            // cW[0] = 1;
            // cW[1] = 1;
            // for(int i = 2;i<=m;i++) {
            //     cW[i] = 1 + cW[i-2]; 
            // }
            // return cW[m];
        }
};

int main(){
    int n;
    cin>>n;

    Solution obj;
    cout<<obj.countWays(n);
    
    return 0;
}