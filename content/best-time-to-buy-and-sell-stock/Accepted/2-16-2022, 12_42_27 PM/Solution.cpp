// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi = 1e9;
        int diff = 0;
        for(int i=0;i<prices.size();i++){
            diff = max(diff,prices[i] - mi);
            mi = min(mi,prices[i]);
        }
        return diff;
    }
};