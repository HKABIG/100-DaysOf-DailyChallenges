class Solution {
    public int maximumDetonation(int[][] bombs) {
        int ans = 0;
        int n = bombs.length;
        for(int i=0;i<n;i++){
            ans = Math.max(ans,dfs(i,new boolean[n],bombs));
        }
        return ans;
    }   
    int dfs(int ind,boolean []vis,int [][] bombs){
        int count = 0;
        vis[ind] = true;
        for(int i=0;i<bombs.length;i++){
            if(!vis[i] && inRange(bombs[ind],bombs[i])){
                count += dfs(i,vis,bombs);
            }
        }
        return 1+ count;
    }
    boolean inRange(int []a,int []b){
        long dx = a[0]-b[0],dy = a[1]-b[1],r = a[2];
        return dx*dx + dy*dy <= r*r;
    }
}