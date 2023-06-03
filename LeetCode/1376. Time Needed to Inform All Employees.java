class Solution {
public:
    int maxTime = INT_MIN;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        queue<pair<int,int>> q;
        q.push({headID,0});
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int i = node.first;
            int time = node.second;
            maxTime = max(maxTime,time);
            for(int child:adj[i]){
                q.push({child,time+informTime[i]});
            }
        }
        return maxTime;
    }
};