#include<bits/stdc++.h>

using namespace std;

class Solution {
    public: 
        void rotate(int n, vector<vector<int>> &a) {
            for(int x = 0;x<n/2;x++) {
                for(int y = x;y<(n-x-1);y++){
                    int temp = a[x][y];
                    
                    a[x][y] = a[y][n-x-1];

                    a[y][n-x-1] = a[n-x-1][n-y-1];

                    a[n-x-1][n-y-1] = a[n-y-1][x];

                    a[n-y-1][x] = temp;
                }
            }
        }
};

int main(){

    int n;
    cin>>n;

    vector<vector<int>> a(n, vector<int>(n));

    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            cin>>a[i][j];
        }
    }

    Solution obj;

    obj.rotate(n, a);

    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            cout<<a[i][j]<<" ";        
        }
        cout<<"\n";
    }

    return 0;
}