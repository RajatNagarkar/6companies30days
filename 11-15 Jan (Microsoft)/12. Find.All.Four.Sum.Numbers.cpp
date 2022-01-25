#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    vector<vector<int>> fourSum(vector<int> &arr, int x) {
        sort(arr.begin(), arr.end());

        cout<<"===\n";
        for(auto x : arr) {
            cout<<x<<" ";
        }
        cout<<"\n===\n";
        int n = arr.size();
        int l, r;
        set<vector<int>> ans;
        for(int i = 0;i<n-3;i++) {
            for(int j = i+1;j<n-2;j++) {
                int l = j+1;
                int r = n-1;
                while(l < r) {
                    int sum = arr[i] + arr[j] + arr[l] + arr[r];
                    if(sum == x) {
                        vector<int> v(4);
                        v = {arr[i], arr[j], arr[l], arr[r]};
                        ans.insert(v);
                        l++;
                        r--;
                    }
                    else if(sum < x) {
                        l++;
                    } else {
                        r--;
                    }

                }
            }
        }
        vector<vector<int>> finalAns;
        
        for(auto x: ans) {
            finalAns.push_back(x);
        }
        return finalAns;
    }
};

int main(){

    int n, x;
    cin>>n>>x;

    vector<int> arr(n);

    for(int i = 0;i<n;i++) {
        cin>>arr[i];
    }

    Solution obj;
    vector<vector<int>> ans = obj.fourSum(arr, x);
    
    for(auto x: ans) {
        for(auto i : x){
            cout<<i<<" ";
        }
        cout<<"$";
    }
    return 0;
}