class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Brute Force O(N)
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==target) return i;
        // }
        // return -1;

        // Optimized O(log(n))
        int n = nums.size();
        int l = 0,h = n - 1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            // left sorted array
            if(nums[l]<=nums[mid]){
                if(nums[l]<=target && nums[mid]>=target){
                    h = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            // right sorted array
            else{
                if(nums[mid]<=target && nums[h]>=target){
                    l = mid + 1;
                }
                else{
                    h = mid -1 ;
                }
            }
        }
        return -1;
    }
};