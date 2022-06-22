// https://leetcode.com/problems/valid-boomerang

class Solution {
public:
    bool iss(vector<int>& p1,vector<int>& p2){
        return p1[0]==p2[0] && p1[1]==p2[1];
    }
    bool isBoomerang(vector<vector<int>>& p) {
        if(iss(p[0],p[1]) || iss(p[0],p[2]) || iss(p[1],p[2])){
            return false;
        }
        double m;
        if(p[1][0] - p[0][0]==0){
            return p[2][0] != 0;
        }
        m = (double)(p[1][1] - p[0][1])/(p[1][0] - p[0][0]);
        int c = p[0][1] - m * p[0][0];
        if(fabs(m*p[2][0] + c -  p[2][1])<=1e-6){
            return false;
        }
        return true;
    }
};