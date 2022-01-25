#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
    public:
    int countSubtreeSum(Node* root, int &count, int &x) {
        if(root == NULL){
            return 0;
        }
        int sumLeft =  countSubtreeSum(root->left, count, x);
        int sumRight =  countSubtreeSum(root->right, count, x);
        
        int sum = sumLeft + sumRight + root->data;

        if(sum == x){
            count++;
        }
        return sum;
    }
    int countSubtreeWithSumX(Node* root, int X){
        if(root == NULL) {
            return 0;
        }

        int count = 0;
        int lSum = countSubtreeSum(root->left, count, X);
        int rSum = countSubtreeSum(root->right, count, X);
        
        if(lSum + rSum + root->data == X){
            count++;
        }
        return count;
    }
};

class BuildTree {
    public:
    int i = 0;
    Node* generateTree(vector<int> &ele, int n) {
        if(n == 0){
            return NULL;
        }
        if(i >= n){
            return NULL;
        }
        if(ele[i] == -1){
            i++;
            return NULL;
        }
        Node* root = new Node(ele[i++]);
        root->left = generateTree(ele, n);
        root->right = generateTree(ele, n);
        return root;

    }

    void showTree(Node* root) {
        if(root == NULL) {
            return;
        }
        cout<<root->data<<" ";
        showTree(root->left);
        showTree(root->right);
    }

};

int main(){
    int n, x;
    cin>>n>>x;

    vector<int> ele(n);

    for(int i = 0;i<n;i++) {
        cin>>ele[i];
    }

    BuildTree tree;
    Node* root = tree.generateTree(ele, n);

    Solution obj;

    cout<<obj.countSubtreeWithSumX(root, x);
    
    return 0;
}