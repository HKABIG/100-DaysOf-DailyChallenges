class Solution {
    long getCost(int[] nums,int[] cost,int base){
        long res = 0L;
        for(int i=0;i<nums.length;i++){
            res += 1L*(Math.abs(nums[i]-base))*cost[i];
        }
        return res;
    }
    public long minCost(int[] nums, int[] cost) {
        int left = 1000001,right = 0;
        for(int num:nums){
            left = Math.min(num,left);
            right = Math.max(num,right);
        }
        long ans = getCost(nums,cost,nums[0]);
        while(left<right){
            int mid = left + (right-left)/2;
            long cost1 = getCost(nums,cost,mid);
            long cost2 = getCost(nums,cost,mid+1);
            ans = Math.min(cost1,cost2);
            if(cost1>cost2){
                left = mid+1;
            }
            else right = mid;
        }
        return ans;
    }
}