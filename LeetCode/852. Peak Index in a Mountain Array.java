class Solution {
    public boolean Check(int i,int[] arr){
        int n = arr.length;
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]) return false;
        }
        for(int k=i;k<n-1;k++){
            if(arr[k]<arr[k+1]) return false;
        }
        return true;
    }
    public int peakIndexInMountainArray(int[] arr) {
        int n = arr.length;
        // Brute Force O(N^2) 
        // for(int i=1;i<n-1;i++){
        //     if(Check(i,arr)) return i;
        // }
        // if(Check(2,arr)) return 2;
        // return -1;

        // Optimized O(N)
        // int i=0;
        // while(arr[i]<arr[i+1]){
        //     i++;
        // }
        // return i;

        // Optimized O(LOG(N))
        int l = 0;int r = n - 1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(arr[mid]<arr[mid+1]){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return l;
    }
}