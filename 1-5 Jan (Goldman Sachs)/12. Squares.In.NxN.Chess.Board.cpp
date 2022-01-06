#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        long long squaresInChessBoard(long long N) {
            //O(1) Approach
            int sqrs = (N * (N+1) * (2 * N + 1)) / 6;
            return sqrs;

            //Recursive Approach
            // if(N == 1){
            //     return 1;
            // }
            // return N*N + squaresInChessBoard(N-1);
        }
};

int main(){

    int N;
    cin>>N;

    Solution obj;

    cout<<obj.squaresInChessBoard(N);

    return 0;
}