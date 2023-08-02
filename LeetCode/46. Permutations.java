class Solution {
    void swap(int[] nums,int i,int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void recurPermute(int ind,int[] nums, List<List<Integer>> ans){
        if(ind==nums.length){
            List<Integer> ds = new ArrayList<>();
            for(int it:nums){
                ds.add(it);
            }
            ans.add(new ArrayList<>(ds));
        }
        for(int i=ind;i<nums.length;i++){
            swap(nums,ind,i);
            recurPermute(ind+1,nums,ans);
            swap(nums,ind,i);
        }
    }
        public void recurPermu(int[] nums,List<List<Integer>> ans ,List<Integer> ds,boolean freq[]){
        if(ds.size()==nums.length){
            ans.add(new ArrayList<>(ds));
            return;
        }
        for(int i=0;i<nums.length;i++){
            if(!freq[i]){
                freq[i] = true;
                ds.add(nums[i]);
                recurPermu(nums,ans,ds,freq);
                ds.remove(ds.size()-1);
                freq[i] = false;
            }
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        // List<List<Integer>> ans = new ArrayList<>();
        // List<Integer> ds = new ArrayList<>();
        // boolean freq[] = new boolean[nums.length];
        // recurPermu(nums,ans,ds,freq);
        // return ans;
        List<List<Integer>> ans = new ArrayList<>();
        recurPermute(0,nums,ans);
        return ans;
    }
}