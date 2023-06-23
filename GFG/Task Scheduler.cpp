//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int n, int k, vector<char> &tasks) {
        vector<int> map(26,0);
        for(char i:tasks){
            map[i-'A']++;
        }
        priority_queue<int> pq;
        for(int i=0;i<26;i++){
            if(map[i]){
                pq.push(map[i]);
                //cout<<map[i]<<" ";
            }
        }
        int time = 0;
        while(!pq.empty()){
            vector<int> remains;
            int cycle = k + 1;
            while(cycle && !pq.empty()){
                int mxfreq = pq.top();
                pq.pop();
                if(mxfreq>1) remains.push_back(mxfreq-1);
                ++time; 
                --cycle; 
            }
            for(int i:remains){
                pq.push(i);
            }
            if(pq.empty()) break;
            time += cycle;
        }
        return time;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends