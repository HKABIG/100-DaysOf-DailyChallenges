class Solution {
    public int bestClosingTime(String customers) {
        int max_score = 0,score = 0,right_time = -1;
        for(int i=0;i<customers.length();i++){
            score += (customers.charAt(i)=='Y')?1:-1;
            if(score>max_score){
                max_score = score;
                right_time = i;
            }
        }
        return right_time + 1;
    }
}