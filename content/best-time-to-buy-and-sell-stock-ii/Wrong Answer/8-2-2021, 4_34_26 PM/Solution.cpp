// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mi=p[0];
        int ans=0;
        for(int i=1;i<p.size();i++){
            if(p[i]<p[i-1]){
                ans+=p[i-1]-mi;
                mi=p[i];
            }
        }
        return ans;
    }
};