class Solution {
    public List<String> summaryRanges(int[] nums) {
        int i = 0;
        int k = 0;
        int n = nums.length;
        List<String> ans = new ArrayList<>();
        while(i<n-1){
            if(nums[i+1]==nums[i]+1){
                i++;
                continue;
            }
            else{
                if(k!=i){
                    ans.add(Integer.toString(nums[k])+"->"+Integer.toString(nums[i]));
                }
                else{
                    ans.add(Integer.toString(nums[i]));
                }
                k = i+1;
            }
            i++;
        }
        if(k<n && i<n && i!=k){
            ans.add(Integer.toString(nums[k])+"->"+Integer.toString(nums[i]));

        }
        if(i<n && i==k){
            ans.add(Integer.toString(nums[i]));
        }
        return ans;
    }
}