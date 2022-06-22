// https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int m = cost.size();
        int ans = 0;
        for(int i=0;i<m%3;i++){
            ans+=cost[m-i-1];
        }
        if(cost.size()<=2){
            return ans;
        }
        for(int i=0;i<cost.size();i+=3){
            ans+=cost[i];
            ans+=cost[i+1];
        }
        return ans;
    }
};