class Solution {
    private int dir[][] = new int[][] {{1,0},{0,1},{0,-1},{-1,0},{-1,-1},{1,1},{1,-1},{-1,1}};
    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        boolean [][] vis = new boolean[n][n];
        vis[0][0] = true;
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0,0});
        int ans = 1;
        while(!q.isEmpty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int [] pop = q.remove();
                if(pop[0]==n-1 && pop[1]==n-1){
                    return ans;
                }
                for(int k=0;k<8;k++){
                    int nx = dir[k][0] + pop[0];
                    int ny = dir[k][1] + pop[1];
                    if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0 && !vis[nx][ny]){
                        q.add(new int[]{nx,ny});
                        vis[nx][ny] = true;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
}