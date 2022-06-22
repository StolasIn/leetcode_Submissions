// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        int max1=0,min1=prices[0],n=prices.size();
        for(int i=1;i<n;i++){
            min1=min(prices[i],min1);
            max1=max(max1,prices[i]-min1);
        }
        return max1;
    }
};