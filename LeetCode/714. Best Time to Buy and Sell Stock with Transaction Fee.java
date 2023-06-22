class Solution {
    int solveTab(int[] prices,int fee){
        int n = prices.length;
        int aheadBuy,aheadNotBuy;
        aheadBuy = aheadNotBuy = 0;
        int curBuy,curNotBuy;
        for(int ind=n-1;ind>=0;ind--){
            curBuy = Math.max(-prices[ind] + aheadNotBuy,0 + aheadBuy);
            curNotBuy = Math.max(prices[ind]-fee+aheadBuy,0+aheadNotBuy);
            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }
        return aheadBuy;

    }
    public int maxProfit(int[] prices, int fee) {
        return solveTab(prices,fee);
    }
}