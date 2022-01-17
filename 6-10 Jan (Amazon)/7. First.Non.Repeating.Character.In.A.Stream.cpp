#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:

    string firstNonRepeating(string A) {
        unordered_map<char, int> mp;
        list<char> l;
        string ans = "";
        int n = A.size();
        int currSize = 0, prevSize = 0;
        for(int i = 0;i<n;i++) {
            mp[A[i]]++;
            currSize = mp.size();
            if(currSize > prevSize) {
                l.push_back(A[i]);
            } else {
                auto it = find(l.begin(), l.end(), A[i]);
                if(it != l.end()) {
                    l.erase(it);
                }
            }
            if(!l.empty()) {
                ans.push_back(l.front());
            } else {
                ans.push_back('#');
            }
            prevSize = currSize;
        }
        return ans;
    }
};

int main(){

    string str;
    cin>>str;

    Solution obj;

    cout<<obj.firstNonRepeating(str);
    return 0;
}