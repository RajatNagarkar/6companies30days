#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    vector<string> generate(int N) {
        vector<string> ans;
        queue<string> q;
        q.push("1");
        while(N--) {
            string s = q.front();

            ans.push_back(s);
            q.pop();

            q.push(s + "0");
            q.push(s + "1");
        }
        return ans;
    }
};

int main(){
    int N;
    cin>>N;  

    Solution obj;
    vector<string> ans = obj.generate(N);

    for(auto i : ans) {
        cout<<i<<" ";
    }
    return 0;
}