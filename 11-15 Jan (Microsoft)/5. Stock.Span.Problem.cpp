#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    vector<int> calculateSpan(int price[], int n) {
        vector<int> ans;
        ans.push_back(1);
        stack<int> s;
        s.push(0);
        for(int i = 1;i<n;i++) {

            while(!s.empty() and price[s.top()] < price[i]){
                s.pop();
            }

            int span = s.empty() ? i+1 : (i - s.top());
            s.push(i);
            ans.push_back(span);
        }
        return ans;
    }
};

int main(){
    int n;
    cin>>n;

    int a[n];
    for(int i = 0;i<n;i++) {
        cin>>a[i];
    }

    Solution obj;

    vector<int> ans;

    ans = obj.calculateSpan(a, n);

    for(auto x : ans) {
        cout<<x<<" ";
    }

    return 0;
}