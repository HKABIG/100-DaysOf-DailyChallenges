class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int x=-1,y=-1,maxlen=-1,m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='@'){
                    x = i;
                    y = j;
                }
                if(grid[i][j]>='a' && grid[i][j]<='f'){
                    maxlen = max(maxlen,grid[i][j]-'a' + 1);
                }
            }
        }
        vector<int> start = {0,x,y};
        queue<vector<int>> q;
        unordered_set<string> vis;
        int step = 0;
        vis.insert(to_string(0)+" "+to_string(x)+" "+to_string(y));
        q.push(start);
        vector<vector<int>> dirs {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                vector<int> curr = q.front();
                q.pop();
                if(curr[0]==(1<<maxlen)-1)
                    return step;
                for(auto& d:dirs){
                    int i = curr[1]+d[0];
                    int j = curr[2]+d[1];
                    int keys = curr[0];
                    if(i<m && i>=0 && j<n && j>=0){
                        char c = grid[i][j];
                        if(c=='#') continue;
                        if(c>='a' && c<='f')
                            keys |= 1<<(c-'a');
                        if(c>='A' && c<='F' && ((keys>>(c-'A'))&1)==0)
                            continue;
                        if(!vis.count(to_string(keys)+" "+to_string(i)+" "+to_string(j))){
                            vis.insert(to_string(keys)+" "+to_string(i)+" "+to_string(j));
                            q.push({keys,i,j});
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};