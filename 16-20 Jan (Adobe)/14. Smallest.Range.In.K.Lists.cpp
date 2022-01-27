#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int listNum, ind, data;

    Node(int k, int i, int val) {
        listNum = k;
        ind = i;
        data = val;
    }
};

class NodeCompare {
    public:
    bool operator () (Node n1, Node n2) {
        return n1.data > n2.data;
    }
};

class Solution {
    public:
    pair<int, int> findSmallestRange(vector<vector<int>> kArr, int n, int k) {
        priority_queue<Node, vector<Node>, NodeCompare> pq;
        pair<int, int> ans{0, INT_MAX};
        int eleMax = INT_MIN;
        for(int i = 0;i<k;i++) {
            int data = kArr[i][0];
            Node obj(i, 0, data);
            pq.push(obj);
            eleMax = max(eleMax, data);
        }

        while(1) {
            Node obj = pq.top();
            pq.pop();
            int cDiff = ans.second - ans.first;
            int nDiff = eleMax - obj.data;
            if(nDiff < cDiff){
                ans = make_pair(obj.data, eleMax);
            }
            int i = obj.listNum;
            int j = obj.ind + 1;
            if(j >= n){
                break;
            }
            Node newObj(i, j , kArr[i][j]);
            eleMax = max(eleMax, kArr[i][j]);
            pq.push(newObj);
        }
        return ans;
    }
};

int main(){

    int n, k;
    cin>>n>>k;
    
    vector<vector<int>> kArr(k, vector<int>(n));

    for(int i = 0;i<k;i++) {
        for(int j = 0;j<n;j++) {
            cin>>kArr[i][j];
        }
    }

    Solution obj;

    pair<int, int> ans;

    ans = obj.findSmallestRange(kArr, n, k);

    cout<<ans.first<<" "<<ans.second;

    return 0;
}