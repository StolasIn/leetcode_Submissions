// https://leetcode.com/problems/combination-sum

class Solution {
public:
    vector<vector<int>> ans;
    void re(vector<int> now,vector<int>& candidates,int item,int remain){
        if(item>=candidates.size()){
            return;
        }
        if(remain==0){
            ans.push_back(now);
        }
        for(int i=1;i*candidates[i]<=remain;i++){
            now.push_back(candidates[i]);
            re(now,candidates,item+1,remain-i*candidates[i]);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        re(new vector<int> now(),candidates,candidates.size(),target);
        return ans;
    }
};