class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        //char ans = letters[0];
        int n = letters.length;
        int l = 0;
        int h = n-1;
        while(l<=h){
            int mid = (l+h)/2;
            if((letters[mid]-'a')<=(target-'a')){
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return l==letters.length?letters[0]:letters[l];
    }
}