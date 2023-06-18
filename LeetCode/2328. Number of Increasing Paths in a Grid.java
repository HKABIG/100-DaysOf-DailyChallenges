class Solution {
    int Mod = 1000000007;
    int[][] dir = {{0,-1},{0,1},{1,0},{-1,0}};
    int dfs(int i,int j,int[][] grid,int[][] dp){
        int result = 1;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        for(int k=0;k<4;k++){
            int dx = i + dir[k][0];
            int dy = j + dir[k][1];
            if(dx>=0 && dy>=0 && dx<grid.length && dy<grid[0].length && grid[dx][dy]>grid[i][j]){
                result = (result + dfs(dx,dy,grid,dp))%Mod;
            }
        }
        return dp[i][j] = result;
    }
    public int countPaths(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int [][] dp = new int[m][n];
        for(int i=0;i<m;i++){
            Arrays.fill(dp[i],-1);
        }
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                count = (count + dfs(i,j,grid,dp))%Mod;
            }
        }
        return count;
    }
}