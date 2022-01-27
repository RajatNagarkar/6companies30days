#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    long long int MOD = 10e9+7;
    int numOfWays(int n, int x) {
        int base = 1;
        return getNum(n, base, x);
    }
    int powerXY(int x, int y){
        int temp;
        if( y == 0)
            return 1;
        temp = powerXY(x, y / 2);
        if (y % 2 == 0)
            return temp * temp;
        else
            return x * temp * temp;
    }

    int getNum(int rem, int base, int power) {
        int res = powerXY(base, power);
        if(rem == res) {
            return 1;
        }
        if(rem < res) {
            return 0;
        }

        int inc = getNum(rem - res, base+1, power);
        int exc = getNum(rem, base + 1, power);

        int num = (inc + exc) % MOD;
        return num;
    }
};

int main(){
    int n,x;
    cin>>n>>x;

    Solution obj;

    cout<<obj.numOfWays(n, x);
    

    return 0;
}