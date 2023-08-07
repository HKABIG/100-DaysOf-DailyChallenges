class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Approach #1 Binary Tree View Visualisation TC(O(M+N))
        // int row = 0,col = matrix[0].size()-1;
        // int n = matrix.size();
        // while(row<=n-1 && col>=0){
        //     int curr = matrix[row][col];
        //     if(curr==target) return true;
        //     if(curr<target) row++;
        //     else col--;
        // }
        // return false;

        // Approach #2 1D array visualization TC(Log(m*n))
        int n = matrix.size(),m = matrix[0].size();
        int l = 0;
        int r = (m*n) - 1;
        while(l<=r){
            int mid = (l + (r-l)/2);
            if(matrix[mid/m][mid%m]==target) return true;
            if(matrix[mid/m][mid%m]<target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};