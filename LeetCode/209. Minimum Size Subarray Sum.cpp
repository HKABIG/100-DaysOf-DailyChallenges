class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ml = INT_MAX;
        // for(int i=0;i<n;i++){
        //     int sum = 0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];
        //         if(sum>=target){
        //             ml = min(ml,j-i+1);
        //         }
        //     }
        // }
        int i = 0,j = 0;
        int sum = 0;
        while(i<n){
            sum += nums[i];
            while(sum>=target){
                ml = min(ml,i-j+1);
                sum -= nums[j];
                j++;
            }
            i++;
        }
        return ml==INT_MAX?0:ml;

    }
};