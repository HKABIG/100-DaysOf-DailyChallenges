class Solution {
    // In excel the numbers are to the base of 26 to represent Alphabets
    public String convertToTitle(int columnNumber) {
        StringBuilder ans = new StringBuilder();
        while(columnNumber>0){
            columnNumber--;
            ans.append((char)((columnNumber)%26+'A'));
            columnNumber = (columnNumber)/26;
        }
        return ans.reverse().toString();
    }
}