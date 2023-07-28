class Solution {
public:
    int solve(vector<int>& nums,int i,int j){
        if(i==j){
            return nums[i];
        }
        if(i>j) return 0;
        int l = nums[i] + min(solve(nums,i+2,j),solve(nums,i+1,j-1));
        int r = nums[j] + min(solve(nums,i,j-2),solve(nums,i+1,j-1));
        return max(l,r);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int mx = solve(nums,0,n-1);
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(mx>=(sum-mx)) return true;
        return false;
    }
};