#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    string colName(long long int n) {
        string ans = "";

        while(n > 0) {
            char ch = 'A' + ((n - 1) % 26);
            ans = ch + ans;

            n = (n-1) / 26;
        }
        return ans;
    }
};

int main(){
    int n;

    cin>>n;

    Solution obj;

    cout<<obj.colName(n);
    

    return 0;
}