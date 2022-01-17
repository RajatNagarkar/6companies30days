#include<bits/stdc++.h>

using namespace std;

class Solution  {
    public:
    vector<vector<string>> phoneDirectory(int n, string contact[], string s) {
        vector<vector<string>> ans;
        string t = "";
        int len = s.size();
        int exLen = 1;

        for(int i = 0;i<len;i++) {
            t += s[i];
            vector<string> list;
            set<string> st;

            for(int j = 0;j<n;j++) {
                int ind = contact[j].find(t);

                if(ind == 0){
                    st.insert(contact[j]);
                }
            }

            if(!st.empty()) {
                for(auto it: st){
                    list.push_back(it);
                }
                ans.push_back(list);
            } else {
                list.push_back("0");
                ans.push_back(list);
            }
        }

        return ans;
    }
};

int main(){
    int n;
    string s;
    cin>>n>>s;

    string str[n];
    
    for(int i = 0;i<n;i++) {
        cin>>str[i];
    }
    Solution obj;

    vector<vector<string>> ans;

    ans = obj.phoneDirectory(n, str, s);

    for(int i = 0;i<ans.size();i++){
        for(auto x : ans[i]){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    return 0;
}