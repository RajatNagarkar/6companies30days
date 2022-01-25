#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node* nextRight;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
        nextRight = NULL;
    }
};

class Solution {
    public:
    void connect(Node* root) {
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            Node* node = q.front();
            q.pop();

            if(node != NULL) {
                node->nextRight = q.front();

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            else if(!q.empty()){
                q.push(NULL);
            }
        }
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

    void printConnect(Node* root) {
        Node* node = root;
        while(node) {
            Node* rNode = node;
            while(rNode){
                cout<<rNode->data<<" ";
                rNode = rNode->nextRight;
            }
            node = node->left;
        }
    }
};

int main(){

    int n;
    cin>>n;
    vector<int> ele(n);
    for(int i = 0;i<n;i++){
        cin>>ele[i];
    }

    BuildTree tree;
    Node* root = tree.generateTree(ele, n);

    Solution obj;
    obj.connect(root);
    tree.printConnect(root);
    cout<<"\n";
    tree.showTree(root);
    return 0;
}