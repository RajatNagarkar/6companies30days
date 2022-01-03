#include<bits/stdc++.h>

using namespace std;

class Solution {
    public: 
        vector<vector<string>> Anagrams(vector<string> &string_list) {
            map<string, vector<string>> ang;

            for(auto i : string_list) {
                string key = i;
                sort(key.begin(), key.end());
                ang[key].push_back(i);
            }
            vector<vector<string>> ans;
            for(auto i : ang) {
                ans.push_back(i.second);
            }
            return ans;
        }
};

int main(){
    int n;
    cin>>n;

    vector<string> string_list(n);

    while(n--){
        string str;
        cin>>str;
        string_list.push_back(str);
    }
    vector<vector<string>> ans;
    Solution obj;
    ans = obj.Anagrams(string_list);
    for(auto i : ans){
        for(auto x : i){
            cout<<x<<" ";
        }
        cout<<"\n";
    }

    return 0;
}