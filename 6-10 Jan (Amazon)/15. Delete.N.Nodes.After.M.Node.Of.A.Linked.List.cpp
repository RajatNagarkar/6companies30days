#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
    public:
    void linkdelete(Node* head, int M, int N) {
        Node* link = head;
        int ctr = 0;
        while(head && head->next) {
            ctr++;
            if(ctr == M){
                Node* node = head;
                int loop = N;
                while(loop--) {
                    if(node->next) {
                        node = node->next;
                    }
                }
                head->next = node->next;
                ctr = 0;
            }
            head = head->next;
        }
    }
};


int main(){
    int size, M, N;
    cin>>size>>M>>N;
    Node* head = NULL;
    Node* node;
    int data;
    
    for(int i = 0;i<size;i++) {
        cin>>data;
        if(i == 0) {
            head = new Node(data);
            node = head;
            continue;
        }
        node->next = new Node(data);
        node = node->next;
    }

    Solution obj;
    obj.linkdelete(head, M, N);
    while(head) {
        cout<<head->data<<" ";
        head = head->next;
    }
    return 0;
}