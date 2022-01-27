#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
  
    vector<string> winner(string arr[],int n)
    {
        map<string, int> elec;
        int maxV = 0;
        for(int i = 0;i<n;i++) {
            elec[arr[i]]++;
            
            maxV = max(maxV, elec[arr[i]]);
        }
        vector<string> ans;
        for(auto i : elec) {
            if(i.second == maxV){
                ans.push_back(i.first);
                ans.push_back(to_string(i.second));
            }
        }
        
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    
    string arr[n];
    for(int i = 0;i<n;i++) {
        cin>>arr[i];
    }

    Solution obj;

    vector<string> ans;

    ans = obj.winner(arr, n);

    cout<<ans[0]<<" "<<ans[1];

    return 0;
}