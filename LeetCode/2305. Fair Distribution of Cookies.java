class Solution {
    int max(int[] distribute){
        int ans = 0;
        for(int i=0;i<distribute.length;i++){
            ans = Math.max(distribute[i],ans);
        }
        return ans;
    }
    int dfs(int i,int[] cookies,int[] distribute,int zcount,int k){
        if(cookies.length-i<zcount)
            return Integer.MAX_VALUE;
        if(i==cookies.length)
            return max(distribute);
        int ans = Integer.MAX_VALUE;
        for(int j=0;j<k;j++){
            zcount -= distribute[j]==0 ? 1:0;
            distribute[j] += cookies[i];
            ans = Math.min(ans,dfs(i+1,cookies,distribute,zcount,k));
            zcount += distribute[j]==0 ? 1:0;
            distribute[j] -= cookies[i];
        }
        return ans;
    }
    public int distributeCookies(int[] cookies, int k) {
        int n = cookies.length;
        int[] distribute = new int[k];
        return dfs(0,cookies,distribute,k,k);
    }
}