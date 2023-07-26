class Solution {
    double timeReq(int[] dist,int speed){
        int n = dist.length;
        double ans = 0.0;
        for(int i=0;i<n;i++){
            double t = (double)dist[i]/(double)speed;
            ans += i==n-1?t:Math.ceil(t);
        }
        return ans;
    }
    public int minSpeedOnTime(int[] dist, double hour) {
        int left = 1;
        int right = 10000000;
        int minSpeed = -1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(timeReq(dist,mid)<=hour){
                minSpeed = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return minSpeed;
    }
}