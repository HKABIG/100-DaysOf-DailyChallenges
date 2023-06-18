//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        int i = 1;
        int j = N;
        int o = 0;
        while(j-i>K){
            if(o%2==0) i+=K;
            if(i==j) return i;
            if(o%2==1){
                j-=K;
            }
           if(j-i<K) return i;
            o++;
        }
        return j;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends