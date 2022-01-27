#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
    vector<int> leaders(int arr[], int n){
        stack<int> s;
        s.push(arr[n-1]);
        int leader = arr[n-1];
        for(int i = n-2;i>=0;i--) {
            if(arr[i] >= leader){
                s.push(arr[i]);
                leader = arr[i];
            }
        }
        vector<int> ans;
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
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

    vector<int> ans;
    ans = obj.leaders(arr, n);

    for(auto i : ans) {
        cout<<i<<" ";
    }
    

    return 0;
}