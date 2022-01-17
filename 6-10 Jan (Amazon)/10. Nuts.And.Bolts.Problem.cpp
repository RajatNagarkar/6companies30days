#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:	
	void matchPairs(char nuts[], char bolts[], int n) {
	    sort(nuts, nuts+n);
	    sort(bolts, bolts+n);
	}
};

int main(){
    int n;
    cin>>n;

    char nuts[n], bolts[n];
    for(int i = 0;i<n;i++) {
        cin>>nuts[i];
    }

    for(int i = 0;i<n;i++) {
        cin>>bolts[i];
    }

    Solution obj;

    obj.matchPairs(nuts, bolts, n);
    
    for(int i = 0;i<n;i++){
        cout<<nuts[i]<<" ";
    }

    cout<<"\n";

    for(int i = 0;i<n;i++) {
        cout<<bolts[i]<<" ";
    }
    return 0;
}