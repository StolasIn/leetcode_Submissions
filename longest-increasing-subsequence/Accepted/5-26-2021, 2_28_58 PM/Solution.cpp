// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& n) {
        vector<int> pos;
        pos.emplace_back(-1e6);
        int m=n.size();
        for(int i=0;i<m;i++){
            if(n[i]>pos.back()){
                pos.emplace_back(n[i]);
            }
            else{
                auto tmp = lower_bound(pos.begin(),pos.end(),n[i]);
                *tmp = n[i];
            }
        }
        return pos.size()-1;
    }
};