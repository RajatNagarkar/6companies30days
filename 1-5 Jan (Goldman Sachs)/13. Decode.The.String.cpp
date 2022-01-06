#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:

    string decodeTheString(string s) {
        string str = "";

        stack<int> numStack;
        stack<string> stringStack;
        int num = 0;
        int n = s.size();
        for(int i = 0;i<n;i++) {
            if(isdigit(s[i])) {
                num = (num * 10 + (s[i] - 48));
            }
            else if(s[i] == '[') {
                numStack.push(num);
                num = 0;

                stringStack.push(str);
                str = "";
            }
            else if(s[i] == ']') {
                string ans = str;

                if(!stringStack.empty()){
                    str = stringStack.top();
                    stringStack.pop();
                }
                int count = 0;
                if(!numStack.empty()) {
                    count = numStack.top();
                    numStack.pop();
                }
                while(count > 0) {
                    str += ans;
                    count--;
                }
            }
            else {
                str += s[i];
            }
        }
        return str;
    }
};

int main(){

    string str;
    cin>>str;

    Solution obj;

    cout<<obj.decodeTheString(str);

    return 0;
}