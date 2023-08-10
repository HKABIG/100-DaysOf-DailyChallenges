class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // Brute Force TC:O(N) Linear Search 
        // for(auto it:nums){
        //     if(it==target){
        //         return true;
        //     }
        // }
        // return false;
        int n = nums.size();
        int low = 0,high = n - 1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[mid]==nums[low] && nums[high]==nums[mid]){
                low++;
                high--;
                continue;
            }
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && nums[mid]>=target){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                if(nums[mid]<=target && nums[high]>=target){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};