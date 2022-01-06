#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int minSubArrayLen(int target, vector<int> &nums) {
            int n = nums.size();
            int min = n+1;
            int sum = 0, start = 0, end = 0;    
            while(end<n) {
                while(sum < target and end < n){
                    sum += nums[end++];
                }
                while(sum >= target and start < n) {
                    if((end-start) < min){
                        min = end-start;
                    }
                    sum -= nums[start++];
                }
            }
            return min == (n+1) ? 0 : min;
        }
};

int main(){
    int target, n;
    cin>>n>>target;

    vector<int> nums(n);

    for(int i = 0;i<n;i++) {
        cin>>nums[i];
    }

    Solution obj;

    cout<<obj.minSubArrayLen(target, nums);
    

    return 0;
}