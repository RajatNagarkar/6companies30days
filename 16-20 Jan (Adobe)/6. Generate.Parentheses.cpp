#include<bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    void generateParenthesis(int n, int open, int close, string s, vector<string> &ans) {
        if(open == n && close == n) {
            ans.push_back(s);
            return;
        }
        
        if(open < n) {
            generateParenthesis(n, open + 1, close, s + "(", ans);
        }
        if(close < open) {
            generateParenthesis(n, open, close + 1, s + ")", ans);
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        vector<string> ans;
        generateParenthesis(n, 0, 0, "", ans);
        return ans;
    }
};

int main(){

    int n;
    cin>>n;
    
    Solution obj;
    vector<string> ans = obj.AllParenthesis(n);

    for(auto i : ans) {
        cout<<i<<"\n";
    }
    return 0;
}