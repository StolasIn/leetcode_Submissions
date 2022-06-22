// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& num, int k) {
        unordered_map<int,vector<int>> map;
        int m=num.size();
        for(int i=0;i<m;i++){
            map[num[i]].emplace_back(i);
        }
        for(auto i : map){
            auto& v=i.second;
            if(v.size()>=2){
                for(int j=1;j<v.size();j++){
                    if(v[j]-v[j-1]<=k) return true;
                }
            }
        }
        return false;
    }
};