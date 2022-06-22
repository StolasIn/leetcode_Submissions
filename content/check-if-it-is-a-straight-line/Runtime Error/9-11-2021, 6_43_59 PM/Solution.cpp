// https://leetcode.com/problems/check-if-it-is-a-straight-line

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        if(c.size()<=2) return true;
        if(c[1][0]-c[0][0]==0){
            for(int i=2;i<c.size();i++){
                if(c[i][0]!=c[0][0]){
                    return false;
                }
            }
            return true;
        }
        double m=(c[1][1]-c[0][1])/(c[1][0]-c[0][0]);
        double t;
        for(int i=2;i<c.size();i++){
            t=(c[i][1]-c[i-1][1])/(c[i][0]-c[i-1][0]);
            if(t!=m){
                return false;
            }
        }
        return true;
    }
};