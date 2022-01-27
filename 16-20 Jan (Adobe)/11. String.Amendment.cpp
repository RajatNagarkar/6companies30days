#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
    string amendSentence (string str) {
        string ans = "";
        int n = str.size();
        
        for(int i = 0;i<n;i++){
            if(str[i] >= 'A' && str[i] <= 'Z'){
                if(ans != "") {
                    char ch = ' ';
                    ans += ch;
                }
                char ch = str[i] + ' ';
                ans += ch;
            }
            else {
                ans += str[i];
            }
        }
        return ans;
    }
};

int main(){

    string str;
    cin>>str;

    Solution obj;

    cout<<obj.amendSentence(str);

    return 0;
}