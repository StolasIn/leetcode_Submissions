// https://leetcode.com/problems/find-center-of-star-graph

class Solution {
public:
    int findCenter(vector<vector<int>>& e) {
        if(e[0][0]==e[1][0] || e[0][0]==e[1][1]){
            return e[0][0];
        }
        return e[0][1];
    }
};