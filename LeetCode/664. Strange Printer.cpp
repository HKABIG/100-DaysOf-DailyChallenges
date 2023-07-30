class Solution {
public:
    int solveMem(int i,int j,string& s,vector<vector<int>> &dp){
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int minTurns = INT_MAX;
        for(int k=i;k<j;k++){
            minTurns = min(minTurns,solveMem(i,k,s,dp)+solveMem(k+1,j,s,dp));
        }
        return dp[i][j] = s[i]==s[j]?minTurns-1:minTurns;
    }
    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solveMem(0,n-1,s,dp);
    }
};