#include<bits/stdc++.h>

using namespace std;

class Solution{
  public:
    int atoi(string str) {
        int num = 0;
        int n = str.size();
        int i = 0;
        bool neg = false;
        if(str[0] == '-') {
            i = 1;
            neg = true;
        }
        for(i;i<n;i++) {
            if(isdigit(str[i])) {
                num = num * 10;
                num += (str[i] - '0');
            } else {
                return -1;
            }
        }
        if(neg) {
            num = 0 - num;
        }
        return num;
    }
};

int main(){

    string str;
    cin>>str;

    Solution obj;
    cout<<obj.atoi(str);
    return 0;
}