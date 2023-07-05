class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0;
        int start = 0;
        int n = nums.size();
        int zc = 0;
        for(int i=0;i<n;i++){
            zc += nums[i]==0?1:0;
            while(zc>1){
                zc -= nums[start]==0?1:0;
                start++;
            }
            l = max(l,i-start);
        }
        return l;
    }
};