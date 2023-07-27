#define ll long long

class Solution {
public:
    ll isPossible(vector<int>& batteries,ll time,int n){
        ll totime = 0;
        for(ll bTime:batteries){
            if(bTime<time) totime += bTime;
            else totime += time;
        }
        return (totime>=time*n);
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        ll r = 1e14;
        ll l = 0;
        ll ans = 0;
        while(l<=r){
            ll mid = l + (r-l)/2;
            if(isPossible(batteries,mid,n)){
                l = mid + 1;
                ans = mid;
            }
            else{
                r = mid - 1;
            }
        }   
        return ans;
    }
};