#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int lis(vector<int> &ls) {
        vector<int> res;

        if(ls.size() > 0) {
            res.push_back(ls[0]);
        }
        int n = ls.size();
        for(int i = 1;i<n;i++) {
            if(ls[i] > res.back()) {
                res.push_back(ls[i]);
            }
            else {
                int id = lower_bound(res.begin(), res.end(), ls[i]) - res.begin();
                res[id] = ls[i];
            }
        }
        return res.size();
    }
    int minInsAndDel(int A[], int B[], int N, int M) {
        vector<int> lS;
        int l = 0;
        for(int i = 0;i<N;i++) {
            if(binary_search(B, B+M, A[i])) {
                lS.push_back(A[i]);
                
            } else {
                l++;
            }
        }      
        int lSize = lis(lS);
        int ans = (N+M) - (2*lSize); // (N - lSize) + (M - lSize);
        return ans;
    }
};

int main(){

    int n, m;
    cin>>n>>m;
    int a[n], b[m];
    for(int i = 0;i<n;i++) {
        cin>>a[i];
    }

    for(int i = 0;i<m;i++) {
        cin>>b[i];
    }

    Solution obj;

    cout<<obj.minInsAndDel(a, b, n, m);

    return 0;
}