class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j){
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0 || grid[i][j]==1){
            return 0;
        }
        int up = solve(grid,i-1,j);
        int left = solve(grid,i,j-1);
        return up + left;
    }
    int solveMem(vector<vector<int>>& grid,int i,int j,vector<vector<int>> &dp){
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0 || grid[i][j]==1){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int up = solveMem(grid,i-1,j,dp);
        int left = solveMem(grid,i,j-1,dp);
        return dp[i][j] = up + left;
    }
    int solveTab(int m,int n,vector<vector<int>>& grid){
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0] = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                int up = 0;
                int left = 0;
                if(i>0 && grid[i][j]!=1) up = dp[i-1][j];
                if(j>0 && grid[i][j]!=1) left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        // int R = grid.size();
        // int C = grid[0].size();
        // if(grid[0][0]==1) return 0;
        // grid[0][0] = 1;
        // for(int i=1;i<R;i++){
        //     grid[i][0] = (grid[i-1][0] == 1 && grid[i][0] == 0)?1:0;
        // }
        // for(int i=1;i<C;i++){
        //     grid[0][i] = (grid[0][i-1] == 1 && grid[0][i] == 0)?1:0;
        // }
        // for(int i=1;i<R;i++){
        //     for(int j=1;j<C;j++){
        //         if(grid[i][j]==0){
        //             grid[i][j] = grid[i-1][j] + grid[i][j-1];
        //         }
        //         else{
        //             grid[i][j] = 0;
        //         }
        //     }
        // }
        // return grid[R-1][C-1];
        int m = grid.size(),n = grid[0].size();
        if(grid[0][0]==1) return 0;
        if(m==1 && n==1 && grid[0][0] == 1) return 0;
        // return solve(grid,m-1,n-1);
        // vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        // return solveMem(grid,m-1,n-1,dp);
        return solveTab(m,n,grid);
    }
};