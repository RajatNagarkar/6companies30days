#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int minSteps(int D) {
        
        int sum = 0, step = 0;

        while(sum < D || (sum - D) % 2 != 0) {
            step++;
            sum += step;
        }
        return step;
    }
};

int main(){
    int D;
    cin>>D;

    Solution obj;

    cout<<obj.minSteps(D);
    

    return 0;
}