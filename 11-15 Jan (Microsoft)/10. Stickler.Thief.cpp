#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int FindMaxSum(int arr[], int n) {
        int inc = arr[0];
        int exc = 0;

        for(int i = 1;i<n;i++) {
            int newExc = max(inc, exc);

            inc = exc + arr[i];

            exc = newExc;
        }
        return max(inc, exc);
    }
};

int main(){
    int n;
    cin>>n;
    
    int arr[n];

    for(int i = 0;i<n;i++) {
        cin>>arr[i];
    }

    Solution obj;

    cout<<obj.FindMaxSum(arr, n);
    
    return 0;
}