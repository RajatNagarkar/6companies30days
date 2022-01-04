#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        string gcdOfStrings(string str1, string str2) {
            int len1 = str1.length();
            int len2 = str2.length();
            string ans = "";
            if((str1 + str2) == (str2 + str1)){
                ans = str1.substr(0, __gcd(len1, len2));
            }
            return ans;
        }
};

int main(){

    string str1, str2;

    cin>>str1>>str2;

    Solution obj;
    cout<<obj.gcdOfStrings(str1, str2);

    return 0;
}