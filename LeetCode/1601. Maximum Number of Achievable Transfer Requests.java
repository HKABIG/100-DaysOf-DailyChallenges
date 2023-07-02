class Solution {
    int ans = 0;
    void help(int i,int l,int[][] requests,int[] temp){
        if(i==requests.length){
            for(int a:temp) if(a!=0) return;
            ans = Math.max(ans,l);
            return;
        }
        help(i+1,l,requests,temp);
        temp[requests[i][0]]--;
        temp[requests[i][1]]++;
        help(i+1,l+1,requests,temp);
        temp[requests[i][0]]++;
        temp[requests[i][1]]--;
    }
    public int maximumRequests(int n, int[][] requests) {
        int [] temp = new int[n];
        help(0,0,requests,temp);
        return ans;
    }
}