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
    vector<int> inord;
    int i = 0;
    void help(Node* root) {
        if(root == NULL) {
            inord.push_back(-1);
            return;
        }
        inord.push_back(root->data);
        help(root->left);
        help(root->right);
    }

    vector<int> serialize(Node* root) {
        help(root);
        return inord;
    }

    Node* deSerialze(vector<int> &ele) {
        if(ele.size() == 0){
            return NULL;
        }
        if(ele[i] == -1) {
            i++;
            return NULL;
        }

        Node* root = new Node(ele[i++]);
        root->left = deSerialze(ele);
        root->right = deSerialze(ele);
        return root;
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
    int n;
    cin>>n;
    vector<int> elements(n);

    for(int i = 0;i<n;i++) {
        cin>>elements[i];
    }
    BuildTree tree;
    Node* root = tree.generateTree(elements, n);
    
    
    Solution obj;
    vector<int> inord;
    inord = obj.serialize(root);

    root = obj.deSerialze(inord);
    tree.showTree(root);
    return 0;
}