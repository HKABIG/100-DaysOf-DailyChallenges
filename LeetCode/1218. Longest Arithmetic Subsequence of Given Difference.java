class Solution {
    public int longestSubsequence(int[] arr, int difference) {
        Map<Integer,Integer> dp = new HashMap<>();
        int ans = 1;
        for(int a:arr){
            int bA = dp.getOrDefault(a-difference,0);
            dp.put(a,bA+1);
            ans = Math.max(ans,dp.get(a));
        }
        return ans;
    }
}