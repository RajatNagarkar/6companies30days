#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val = 0) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
    public:
    Node* bfsForParents(Node* root, map<Node*, Node*> &parentMap, int start) {
        queue<Node*> q;
        q.push(root);

        Node* res;

        while(!q.empty()) {
            Node* node = q.front();

            if(node->data == start) {
                res = node;
            }
            q.pop();

            if(node->left){
                parentMap[node->left] = node;
                q.push(node->left);
            }

            if(node->right){
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }
    int minTime(Node* root, int start) {
        map<Node*, Node*> parentMap;
        Node* target = bfsForParents(root, parentMap, start);

        int ans = findMaxDistance(parentMap, target);

        return ans;
    }

    int findMaxDistance(map<Node*, Node*> &parentMap, Node* target) {
        queue<Node*> q;
        q.push(target);
        map<Node*, int> burnt;
        burnt[target] = 1;

        int maxi = 0;

        while(!q.empty()) {
            int sz = q.size();
            bool brn = false;

            for(int i = 0;i<sz;i++) {
                Node* node = q.front();
                q.pop();

                if(node->left && !burnt[node->left]) {
                    brn = true;
                    burnt[node->left] = 1;
                    q.push(node->left);
                }

                if(node->right && !burnt[node->right]) {
                    brn = true;
                    burnt[node->right] = 1;
                    q.push(node->right);
                }

                if(parentMap[node] && !burnt[parentMap[node]]) {
                    brn = true;
                    burnt[parentMap[node]] = 1;
                    q.push(parentMap[node]);
                }
            }
            if(brn){
                maxi++;
            }
        }
        return maxi;
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
    int n, target;
    cin>>n>>target;
    vector<int> elements(n);

    for(int i = 0;i<n;i++) {
        cin>>elements[i];
    }
    BuildTree tree;
    Node* root = tree.generateTree(elements, n);
    
    
    Solution obj;

    cout<<obj.minTime(root, target);
    
    return 0;
}