class Solution {
    int solve(int i,int j,int [][] dp){
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = solve(i-1,j,dp);
        int down = solve(i,j-1,dp);
        return dp[i][j] = up+down;
    }
    public int uniquePaths(int m, int n) {
        int [][] dp = new int[m+1][n+1];
        for(int i=0;i<m;i++)
            Arrays.fill(dp[i],-1);
        return solve(m-1,n-1,dp);
    }
}