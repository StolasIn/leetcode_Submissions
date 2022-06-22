// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& num, int k) {
        unordered_map<int,vector<int>> map;
        int m=num.size();
        for(int i=0;i<m;i++){
            map[num[i]].emplace_back(i);
            auto& v=map[num[i]];
            if(v.size()>=2 && v.back()-v[v.size()-2]<=k) return true;
        }
        return false;
    }
};