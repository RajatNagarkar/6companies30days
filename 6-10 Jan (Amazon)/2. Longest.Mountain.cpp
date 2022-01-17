#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestMountainDP(vector<int>& arr) { //This is a DP Apporach With O(n) Time and O(n) Space.
        int n = arr.size();
        
        if(n < 3){
            return 0;
        }
        
        vector<int> left(n, 0), right(n, 0);
        
        for(int i = 1;i<n;i++){
            if(arr[i] > arr[i-1]) {
                left[i] = left[i-1] + 1;
            }
        }
        for(int i = n-2;i>0;i--){
            if(arr[i] > arr[i+1]) {
                right[i] = right[i+1] + 1;
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++) {
            if(left[i] && right[i]) {
                int longMt = left[i] + right[i] + 1;
                ans = max(ans, longMt);
            }
        }
        return ans;
    }

    int longestMountain(vector<int> &arr) {
        int i, ans = 0, count = 0, n = arr.size();

        for(int i = 1;i<n;i++){
            if(arr[i] == arr[i-1]){
                count = 0;
            }
            else if(arr[i] > arr[i-1]) {
                count++;
            } else if(count > 0) {
                while(i< n && arr[i] < arr[i-1]) {
                    count++;
                    i++;
                }
                ans = max(ans, count+1);
                count = 0;
                i--;
            }
        }
        return ans;
    }
};

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i = 0;i<n;i++) {
        cin>>arr[i];
    }

    Solution obj;

    cout<<obj.longestMountain(arr);

    return 0;
}