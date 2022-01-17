#include<bits/stdc++.h>

using namespace std;

class BST {
    public:
        int data = 0;
        BST* left;
        BST* right;
        BST () {
            this->left = NULL;
            this->right = NULL;
        }
        BST(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }

        BST* insert(BST* root, int val) {
            if(root == NULL) {
                return new BST(val);
            }

            if(val < root->data) {
                root->left = insert(root->left, val);
            } else {
                root->right = insert(root->right, val);
            }
            return root;
        }

        BST* deleteNode(BST* root, int val) {
            if(root == NULL){
                return root;
            }

            if(val < root->data) {
                root->left= deleteNode(root->left, val);
            } else if(val > root->data) {
                root->right = deleteNode(root->right, val);
            }
            else {
                if(root->right == NULL) {
                    BST* temp = root->left;
                    free(root);
                    return temp;
                } 
                if(root->left == NULL) {
                    BST* temp = root->right;
                    free(root);
                    return temp;
                }
                BST* inordSucc = inorderSuccessor(root->right);
                root->data = inordSucc->data;
                root->right = deleteNode(root->right, inordSucc->data);
            }
            return root;
        }

        BST* inorderSuccessor(BST* root){
            BST* curr  = root;
            while(curr && curr->left != NULL){
                curr =curr->left;
            }
            return curr;
        }

        int getMax(BST* root){
            BST* curr = root;

            while(curr->right != NULL) {
                curr= curr->right;
            }
            return curr->data;
        }

        void inorder(BST* root) {
            if(root == NULL){
                return;
            }
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
        
};

class Solution {
    public:
        vector<int> max_of_subarrays(int *arr, int n, int k) {
            vector<int> ans;
            BST b, *root = NULL;
            int i;
            // Removing First Node(First Element of Array) from the BST will delete the Complete Tree.
            root = b.insert(root, -1); // So Assigning -1.
            
            int delInd = 0, treeSize = 0;
            for(i = 0;i<n;i++) {
                b.insert(root, arr[i]);
                treeSize++;

                if(treeSize >= k){
                    ans.push_back(b.getMax(root));
                    b.deleteNode(root, arr[delInd++]);
                }                 
            }
            return ans;
        }
};

int main(){
    int n, k;
    cin>>n>>k;

    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    
    Solution obj;

    vector<int> ans;

    ans = obj.max_of_subarrays(arr, n, k);

    for(auto i : ans){
        cout<<i<<" ";
    }


    return 0;
}