#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int* findTwoElement(int *arr, int n) {
            int* ans = new int[2];

            for(int i = 0;i<n;i++){
                int ind = abs(arr[i]) - 1;
                if(arr[ind] > 0) {
                    arr[ind] = -1*arr[ind];
                } else {
                    ans[0] = abs(arr[i]);
                }
            }
            for(int i = 0;i<n;i++) {
                if(arr[i] > 0){
                    ans[1] = (i+1); 
                }
            }
            return ans;
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

    int* ans;
    ans = obj.findTwoElement(arr, n);
    cout<<ans[0]<<" "<<ans[1];
    

    return 0;
}