// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int now = 1e9;
        int ans = 0;
        for(int i=0;i<p.size();i++){
            now = min(now,p[i]);
            if(p[i]>now){
                ans+=p[i]-now;
                now = p[i];
            }
        }
        return ans;
    }
};