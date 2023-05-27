class Solution {
    int help(int i,int[] s,int[] dp){
        if(i>=s.length) return 0;
        if(dp[i]!=-1) return dp[i];
        else{
            int ans = Integer.MIN_VALUE;
            ans = Math.max(ans,s[i]-help(i+1,s,dp));
            if(i+1<s.length)ans = Math.max(ans,s[i]+s[i+1]-help(i+2,s,dp));
            if(i+2<s.length)ans = Math.max(ans,s[i]+s[i+1]+s[i+2]-help(i+3,s,dp));
            return dp[i] = ans;
        }
    }
    int helpTab(int [] s){
        int n = s.length;
        int [] dp = new int[n+1];
        for(int i=n-1;i>=0;i--){
            int ans = Integer.MIN_VALUE;
            ans = Math.max(ans,s[i]-dp[i+1]);
            if(i+1<n)ans = Math.max(ans,s[i]+s[i+1]-dp[i+2]);
            if(i+2<n)ans = Math.max(ans,s[i]+s[i+1]+s[i+2]-dp[i+3]);
            dp[i] = ans;
        }
        return dp[0];
    }
    public String stoneGameIII(int[] stoneValue) {
        int [] dp = new int[50001];
        Arrays.fill(dp,-1);
        //int Alice = help(0,stoneValue,dp);
        int Alice = helpTab(stoneValue);
        if(Alice>0) return "Alice";
        if(Alice==0) return "Tie";
        return "Bob";
    }
}