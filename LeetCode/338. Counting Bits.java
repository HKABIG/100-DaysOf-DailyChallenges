class Solution {
    int count(int n){
        int count = 0;
        while(n>0){
            count += n&1;
            n >>= 1;
        }
        return count;
    }
    public int[] countBits(int n) {
        // int [] ans = new int[n+1];
        // for(int i=0;i<n+1;i++){
        //     ans[i] = count(i);
        // }
        // return ans;
        int [] memo = new int[n+1];
        for(int i=0;i<n+1;i++){
            memo[i] = memo[i/2] + i%2;
        }
        return memo;
    }
}