class Solution {
    public int largestAltitude(int[] gain) {
        int n = gain.length;
        int[] alt = new int[n+1];
        int maxAlt = 0;
        for(int i=1;i<n;i++){
            alt[i] = gain[i-1] + alt[i-1];
            maxAlt = Math.max(alt[i],maxAlt);
        }
        maxAlt = Math.max(maxAlt,gain[n-1]+alt[n-1]);
        return maxAlt;
    }
}