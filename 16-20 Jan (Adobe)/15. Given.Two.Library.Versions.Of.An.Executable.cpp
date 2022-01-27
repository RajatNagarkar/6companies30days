#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    string getVersions(string str1, string str2) {
        if(str1 == ""){
            return str2;
        }
        if(str2 == "") {
            return str1;
        }
        int len1 = str1.length();
        int len2 = str2.length();

        if(len1 < len2) {
            return str2;
        }
        if(len1 > len2) {
            return str1;
        }

        for(int i = 0;i<len1;i++) {
            char ch1 = str1[i] - 48;
            char ch2 = str2[i] - 48;
            if(ch2 > ch1) {
                return str2;
            } else if(ch2 < ch1) {
                return str1;
            }
        }
        return str1;
    }
};

int main(){
    string str1, str2;
    cin>>str1>>str2;

    Solution obj;

    cout<<obj.getVersions(str1, str2);
    

    return 0;
}