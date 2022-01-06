#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        long long squaresInChessBoard(long long N) {
            if(N == 1){
                return 1;
            }

            return N*N + squaresInChessBoard(N-1);
        }
};

int main(){

    int N;
    cin>>N;

    Solution obj;

    cout<<obj.squaresInChessBoard(N);

    return 0;
}