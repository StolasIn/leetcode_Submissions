// https://leetcode.com/problems/find-the-highest-altitude

class Solution {
public:
    int largestAltitude(vector<int>& g) {
        int ma = max(0,g[0]);
        for(int i=1;i<g.size();i++){
            g[i] += g[i-1];
            ma = max(ma,g[i]);
        }
        return ma;
    }
};