#include<bits/stdc++.h>

using namespace std;

class Solution  {
    public:
    vector<int> subarraySum(int arr[], int n, long long s) {
        long long sum = 0;
        int start = 0, end = 0;

        for(end = 0;end<=n;end++) {

            sum += arr[end];

            while(sum >= s) {
                if(sum == s){
                    return vector<int>{start+1, end+1};
                }
                sum -= arr[start++];
            }
            
        }
        return vector<int>{-1};
    }
};

int main(){
    int n;
    long long s;
    cin>>n>>s;

    int arr[n];

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }   

    Solution obj;

    vector<int> ans = obj.subarraySum(arr, n, s);
    
    for(auto x : ans) {
        cout<<x<<" ";
    }

    return 0;
}

