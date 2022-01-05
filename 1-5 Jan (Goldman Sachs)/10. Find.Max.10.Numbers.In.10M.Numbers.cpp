#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<int> findTenMaxInTenMillionNumbers(vector<int> &arr) {
            vector<int> ans;

            priority_queue<int> pq;
            int n = arr.size(), k = 10; //Number of Maximum Elements to Find Out.
            
            for(auto i : arr) {
                pq.push(i);
            }

            for(int i = 0 ;i<k;i++){
                ans.push_back(pq.top());
                pq.pop();
            }
            return ans;
        }
};

int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n);

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    Solution obj;
    
    vector<int> ans;

    ans = obj.findTenMaxInTenMillionNumbers(arr);

    for(auto i : ans){
        cout<<i<<" ";
    }

    return 0;
}