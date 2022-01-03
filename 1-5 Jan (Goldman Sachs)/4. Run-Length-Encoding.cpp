#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string encode(string src)
    {
        string ans = "";
        int n = src.length();
        char prev = '\0';
        for (int i = 0; i < n; i++)
        {
            int c = 1;
            while (i < n && src[i] == src[i + 1])
            {
                c++;
                i++;
            }
            ans += (src[i] + to_string(c));
        }
        return ans;
    }
};

int main()
{
    string str;
    cin>>str;

    Solution obj;

    cout<<obj.encode(str);
    return 0;
}