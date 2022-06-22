// https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& p) {
        int d = 1e9;
        int ans = -1;
        for(int i=p.size()-1;i>=0;i--){
            if(x==p[i][0] || y==p[i][1]){
                int tmp = abs(p[i][0]-x) + abs(p[i][1]-y);
                if(d>=tmp){
                    d = tmp;
                    ans = i;
                }
            }
        }
        return ans;
    }
};