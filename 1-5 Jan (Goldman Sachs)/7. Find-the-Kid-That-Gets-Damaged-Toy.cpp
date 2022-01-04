#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int getChildWithDamagedToy(int n, int m, int k) {
            
            if(m <= (n-k+1)){
                return n + k -1;
            }

            m = m - (n - k + 1);

            return m % n == 0 ? n : m % n;
        }
};


int main(){

    int n, m, k;

    cin>>n>>m>>k;
    
    Solution obj;

    cout<<obj.getChildWithDamagedToy(n, m, k);

    return 0;
}