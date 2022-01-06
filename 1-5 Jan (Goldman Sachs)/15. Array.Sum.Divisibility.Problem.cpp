#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool canPair(vector<int> nums, int k) {
            unordered_map<int, int> ele;
            int n = nums.size();
            for(auto i : nums){
                ele[i%k]++;;
            }

            if(ele[0] % 2 != 0){
                return false;
            }
            
            for(auto i : ele){
                int rem = i.first;
                int freq = i.second;

                if(rem != 0 && ele[k-rem] != freq)
                    return false;
            }
            return true;
        }
};

int main(){

    int n, k;
    cin>>n>>k;
    vector<int> nums(n);

    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }    
    Solution obj;
    cout<<obj.canPair(nums, k);
    return 0;
}