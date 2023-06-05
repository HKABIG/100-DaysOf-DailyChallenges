class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        int y1 = coordinates[1][1] - coordinates[0][1];
        int x1 = coordinates[1][0] - coordinates[0][0];
        for(int i=2;i<coordinates.length;i++){
            if(y1*(coordinates[i][0]-coordinates[0][0]) != x1*(coordinates[i][1]-coordinates[0][1])){
                return false;
            }
        }
        return true;
    }
}