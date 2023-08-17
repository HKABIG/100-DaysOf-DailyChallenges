class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(),n = mat[0].size();
        vector<vector<int>> dist(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j] = true;
                }
            }
        }
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            dist[x][y] = dis;
            for(int i=0;i<4;i++){
                int nx = dx[i]+x,ny = dy[i]+y;
                if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny]){
                    q.push({{nx,ny},dis+1});
                    vis[nx][ny] = true;
                }
            }
        }
        return dist;
    }
};