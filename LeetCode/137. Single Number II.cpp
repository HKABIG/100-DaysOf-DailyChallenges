#define ll long long
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Optimized and Highly Intuitive
        int n = nums.size();
        ll ans = 0,shift = 1;
        for(int i=0;i<32;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(((nums[j]>>i)&1)==1){
                    count++;
                }
            }
            if(count%3!=0)
                ans += shift;
            shift*=2;
        }
        return ans;

        // Highly Optimized Not Intuitive
        // int ones = 0;int twos = 0;
        // for(int i=0;i<nums.size();i++){
        //     ones = (ones^nums[i])&(~twos);
        //     cout<<"ones of "<<nums[i]<<" is "<<ones<<" ";
        //     twos = (twos^nums[i])&(~ones);
        //     cout<<"twos of "<<nums[i]<<" is "<<twos<<endl;
        // }
        // return ones;
    }
};