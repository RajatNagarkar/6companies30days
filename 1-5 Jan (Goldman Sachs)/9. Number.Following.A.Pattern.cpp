#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        string printMinNumberForPattern(string str) {
            int n = str.length();
            string ans = "";
            stack<int> s;
            int count = 1;
            for(int i = 0;i<n;i++){
                if(str[i] == 'I') {
                    s.push(count);
                    count++;
                    while(!s.empty()){
                        ans += to_string(s.top());
                        s.pop();
                    }
                } else {
                    s.push(count);
                    count++;
                }
            }
            s.push(count);
            while(!s.empty()){
                ans += to_string(s.top());
                s.pop();
            }
            return ans;
        }
};

int main(){

    string str;
    cin>>str;

    Solution obj;
    cout<<obj.printMinNumberForPattern(str);

    return 0;
}