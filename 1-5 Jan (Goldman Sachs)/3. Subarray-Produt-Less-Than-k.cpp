#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
class Solution {
    public:
        int countSubarrayProductLessThanK(vector<int> &a, int n, int k) {
            int l(0), r(0), res(0);
            lli prod = 1;
            for(r = 0;r<n;r++) {
                prod *= a[r];

                if(prod >= k) {
                    while(l < r and prod >= k) {
                        prod /= a[l];
                        l++;
                    }
                }
                if(prod < k) {
                    int len = (r-l) + 1;
                    res += len;
                }
            }
            return res;
        }
};

int main(){

    int n, k;
    cin>>n>>k;

    vector<int> v(n);

    for(int i = 0;i<n;i++){
        cin>>v[i];
    }

    Solution obj;

    cout<<obj.countSubarrayProductLessThanK(v, n, k);

    return 0;
}