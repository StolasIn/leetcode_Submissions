// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        int max1=0;
        int min1=INT_MAX;
        int n=prices.size();
        for(int i=0;i<n;i++){
            if(prices[i]<min1) min1=prices[i];
            if(max1<prices[i]-min1) max1=prices[i]-min1;
        }
        return max1;
    }
};