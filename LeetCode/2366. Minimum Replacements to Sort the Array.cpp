class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        int minmaxvalue = nums[n-1];
        for(int i=n-2;i>=0;i--){
            long long parts = ceil(nums[i]/(double)minmaxvalue);
            res += (parts-1);
            minmaxvalue = nums[i]/parts;
        }
        return res;
    }
};