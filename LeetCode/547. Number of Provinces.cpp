class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(isConnected[i][j]==1){
                        adj[i].push_back(j);
                    }
                }
            }
        }
        int numberOfComponents = 0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                numberOfComponents++;
                queue<int> q;
                q.push(i);
                vis[i] = true;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto it:adj[node]){
                        if(!vis[it]){
                            q.push(it);
                            vis[it] = true;
                        }
                    }
                }
            }
        }
        
        return numberOfComponents;
    }
};