class Solution {
    int solve(int ind,int diff,int[] nums,HashMap<Integer, Integer>[] dp){
        // Memoization DP
        if(ind<0) 
            return 0;
        int ans = 0;
        if(dp[ind].containsKey(diff)) return dp[ind].get(diff);
        for(int j=ind-1;j>=0;j--){
            if(nums[ind]-nums[j]==diff){
                ans = Math.max(ans,1+solve(j,diff,nums,dp));
            }
        }
        dp[ind].put(diff,ans);
        return ans;
    }
    public int longestArithSeqLength(int[] nums) {
        // Memoization Code O(N^2)
        // int n = nums.length;
        // if(n<=2) return n;
        // int ans = 0;
        // HashMap<Integer, Integer>[] dp = new HashMap[nums.length];
        // for(int i=0;i<n;i++){
        //     dp[i] = new HashMap<Integer,Integer>();
        // }
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         ans = Math.max(ans,2+solve(i,nums[j]-nums[i],nums,dp));
        //     }
        // }
        // return ans;
        int maxLength = 0;
        HashMap<Integer,Integer>[] dp = new HashMap[nums.length];
        for(int right=0;right<nums.length;right++){
            dp[right] = new HashMap<>();
            for(int left=0;left<right;left++){
                int diff = nums[left] - nums[right];
                dp[right].put(diff,dp[left].getOrDefault(diff,1)+1);
                maxLength = Math.max(maxLength,dp[right].get(diff));
            }
        }
        return maxLength;
    }
}