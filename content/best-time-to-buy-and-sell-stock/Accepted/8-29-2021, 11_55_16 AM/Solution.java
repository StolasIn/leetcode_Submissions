// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
    public int maxProfit(int[] prices) {
        int mi=Integer.MAX_VALUE;
        int diff=0;
        for(int i=0;i<prices.length;i++){
            mi=Math.min(mi,prices[i]);
            diff=Math.max(diff,prices[i]-mi);
        }
        return diff;
    }
}