#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        if(L1[0] > R2[0] || L2[0] > R1[0]){
            return 0;
        }
        else if(R1[1] > L2[1] || R2[1] > L1[1]) {
            return 0;
        }
        return 1;
    }
};

int main(){

    int l1[2], r1[2], l2[2], r2[2];

    cin>>l1[0]>>l1[1]>>r1[0]>>r1[1]>>l2[0]>>l2[1]>>r2[0]>>r2[1];

    Solution obj;

    obj.doOverlap(l1, r1, l2, r2);

    return 0;
}