// https://leetcode.com/problems/rectangle-overlap

class Solution {
public:
    bool isin(vector<int>& v,int x,int y){
        if(v[0]<x && v[2]>x && v[1]<y && v[3]>y){
            return true;
        }
        return false;
    }
    bool isRectangleOverlap(vector<int>& v1, vector<int>& v2) {
        return isin(v1,v2[0],v2[1]) || isin(v1,v2[2],v2[3])
                || isin(v2,v1[0],v1[1]) || isin(v2,v1[0],v1[1]);
    }
};