class Solution {
    int mod = 1000000007;
    int solve(int remfuel,int[] locations,int curr,int finish,int[][] dp){
        if(remfuel<0) return 0;
        if(dp[curr][remfuel]!=-1) return dp[curr][remfuel];
        int ans = curr==finish?1:0;
        for(int nextCity=0;nextCity<locations.length;nextCity++){
            if(nextCity!=curr){
                ans = (ans + solve(remfuel-Math.abs(locations[curr]-locations[nextCity]),locations,nextCity,finish,dp))%mod;
            }
        }
        return dp[curr][remfuel]=ans;
    }
    int solveTab(int[] locations,int start,int finish,int fuel){
        int[][] dp = new int[locations.length][fuel+1];
        for(int i=0;i<locations.length;i++){
            Arrays.fill(dp[i],0);
        }
        
    }
    public int countRoutes(int[] locations, int start, int finish, int fuel) {
        int[][] dp = new int[locations.length][fuel+1];
        for(int i=0;i<locations.length;i++){
            Arrays.fill(dp[i],-1);
        }
        // return solve(fuel,locations,start,finish,dp);   
        return solveTab(locations,start,finish,fuel);
    }
}