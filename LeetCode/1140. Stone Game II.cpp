class Solution {
public:
    int diff(int i,int M,vector<int>& p,vector<vector<int>>& dp){
        if(i>=p.size()) return 0;
        int tot = 0;
        int ans = INT_MIN;
        if(dp[i][M]!=-1) return dp[i][M];
        for(int j=0;j<2*M;j++){
            if(i+j<p.size()) tot += p[i+j];
            ans = max(ans,tot-diff(i+j+1,max(j+1,M),p,dp));
        }
        return dp[i][M] = ans;
    }
    int stoneGameII(vector<int>& p) {
        int sum = 0;
        for(int it:p){
            sum += it;
        }
        vector<vector<int>> dp(101,vector<int>(101,-1));
        int dif = diff(0,1,p,dp);
        return (sum+dif)/2;
    }
};