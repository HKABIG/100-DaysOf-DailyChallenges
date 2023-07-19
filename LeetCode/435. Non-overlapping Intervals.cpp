class Solution {
public:
    int solve(vector<pair<int,int>> &inter,int n,vector<int>& dp,int i){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int j = i+1;
        while(j<n && inter[j].first<inter[i].second){
            j++;
        }
        int op1 = 1 + solve(inter,n,dp,j);
        int op2 = solve(inter,n,dp,i+1);
        return dp[i] = max(op1,op2);
    }
    int bs(int i,vector<pair<int,int>>& inter){
        int l = i;
        int r = inter.size();
        while(r>l+1){
            int mid = (l+r)/2;
            if(inter[mid].first<inter[i].second){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        return r;
    }
    int solveTab(vector<pair<int,int>>& inter,vector<vector<int>>& intervals){
        int n = intervals.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int j = bs(i,inter);
            dp[i] = max(1+dp[j],dp[i+1]);
        }
        return n-dp[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Greedy Based O(NLog(N))
        // sort(intervals.begin(),intervals.end());
        // int n = intervals.size(),l = 0,r = 1,count = 0;
        // while(r<n){
        //     if(intervals[l][1]<=intervals[r][0]){
        //         l= r;
        //         r++;
        //     }
        //     else if(intervals[l][1]<=intervals[r][1]){
        //         count++;
        //         r++;
        //     }
        //     else if(intervals[l][1]>intervals[r][1]){
        //         count++;
        //         l = r;
        //         r++;
        //     }
        // }
        // return count;

        // DP
        int n = intervals.size();
        vector<pair<int,int>> inter;
        for(auto it:intervals)
            inter.push_back({it[0],it[1]});
        sort(inter.begin(),inter.end());
        // vector<int> dp(n,-1);
        // return n - solve(inter,n,dp,0);
        return solveTab(inter,intervals);
    }
};