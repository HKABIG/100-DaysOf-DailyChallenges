class Solution {
    public int countNegatives(int[][] grid) {
        int n = grid[0].length;
        int count = 0;
        for(int[] row:grid){
            int left = 0,right = n-1;
            while(left<=right){
                int mid = (left + (right-left)/2);
                if(row[mid]<0){
                    right = mid - 1;// This is for stop condition
                }
                else{
                    left = mid + 1;
                }
            }
            count += (n-left);
        }
        return count;
    }
}

        // int m = grid.length;
        // int n = grid[0].length;
        // int count = 0;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(grid[i][j]<0){
        //             count++;
        //         }
        //     }
        // }
        // return count;