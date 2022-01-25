#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    vector<string> possibleWords(int a[], int n) {
        vector<char> kpd[10] {
            {},{},
            {'a','b','c'},
            {'d','e','f'},
            {'g','h','i'},
            {'j','k','l'},
            {'m','n','o'},
            {'p','q','r','s'},
            {'t','u','v'},
            {'w','x','y','z'}
        };
        vector<string> ans;
        generateWords(kpd, a, 0, n, "", ans);
        return ans;
    }

    void generateWords(vector<char> kpd[], int a[], int i, int n, string word, vector<string> &ans) {

        if(i >= n){
            ans.push_back(word);
            return;
        }
        int dig = a[i];
        int len = kpd[dig].size();

        for(int x = 0;x<len;x++) {
            generateWords(kpd, a, i+1, n, word + kpd[dig][x], ans);
        }
    }
};

int main(){
    int n;
    cin>>n;

    int arr[n];
    
    for(int i = 0;i<n;i++) {
        cin>>arr[i];
    }

    Solution obj;
    vector<string> ans;
    ans = obj.possibleWords(arr, n);

    for(auto x : ans) {
        cout<<x<<" ";
    }

    return 0;
}