class Solution {
public:
    int solve(int ind,int amount,vector<int>& coins,vector<vector<int>> &dp){
        if(amount==0){
            return 1;
        }
        if(ind==coins.size()){
            return 0;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        if(coins[ind]>amount){
            return dp[ind][amount] = solve(ind+1,amount,coins,dp);
        }
        dp[ind][amount] = solve(ind,amount-coins[ind],coins,dp)+solve(ind+1,amount,coins,dp);
        return dp[ind][amount];
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        return solve(0,amount,coins,dp);
    }
};