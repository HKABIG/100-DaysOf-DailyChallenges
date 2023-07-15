class Solution {
    int solve(int[][] events,int n,int ind,int k){
        if(ind==n || k==0){
            return 0;
        }
        int i;
        for(i=ind+1;i<n;i++){
            if(events[i][0]>events[ind][1])
                break;
        }
        return Math.max(solve(events,n,ind+1,k),events[ind][2]+solve(events,n,i,k-1));
    }
    int solveMem(int[][] events,int n,int ind,int k,int[][] dp){
        if(ind==n || k==0){
            return 0;
        }
        if(dp[ind][k]!=-1) return dp[ind][k];
        int i;
        for(i=ind+1;i<n;i++){
            if(events[i][0]>events[ind][1])
                break;
        }
        return dp[ind][k] = Math.max(solveMem(events,n,ind+1,k,dp),events[ind][2]+solveMem(events,n,i,k-1,dp));
    }
    public int maxValue(int[][] events, int k) {
        int n = events.length;
        Arrays.sort(events, (a, b) -> a[0] - b[0]);
        int [][] dp = new int[n+1][k+1];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        // return solve(events,n,0,k);
        return solveMem(events,n,0,k,dp);
    }
}