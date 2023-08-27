class Solution {
public:
    unordered_map<int,int> mark;
    int dp[2001][2001];
    bool solve(int prev,int index,vector<int>& stones,int n){
        if(index==n-1){
            return 1;
        }
        if(dp[prev][index]!=-1){
            return dp[prev][index];
        }
        bool ans = false;
        for(int nextJump=prev-1;nextJump<=prev+1;nextJump++){
            if(nextJump>0 && mark.find(stones[index]+nextJump)!=mark.end()){
                ans = ans || solve(nextJump,mark[stones[index]+nextJump],stones,n);
            }
        }
        return dp[prev][index]=ans;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        for(int i=0;i<n;i++){
            mark.insert({stones[i],i});
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,0,stones,n);
    }
};