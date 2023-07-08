class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<long long> candidates;
        for(int i=0;i<n-1;i++){
            candidates.push_back(weights[i]+weights[i+1]);
        }      
        sort(candidates.begin(),candidates.end());
        long long mxsum = 0;
        long long mnsum = 0;
        for(int i=0;i<k-1;i++){
            mnsum += candidates[i];
            mxsum += candidates[n-2-i];
        }
        return mxsum-mnsum;
    }
};