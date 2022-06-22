// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mi=p[0];
        vector<int> v;
        p.emplace_back(-1);
        for(int i=1;i<p.size();i++){
            if(p[i]<p[i-1]){
                v.emplace_back(p[i-1]-mi);
                mi=p[i];
            }
        }
        sort(v.rbegin(),v.rend());
        if(v.size()==0) return 0;
        else if(v.size()==1) return v[0];
        return v[0]+v[1];
    }
};