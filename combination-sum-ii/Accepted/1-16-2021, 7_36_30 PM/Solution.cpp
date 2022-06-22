// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
    vector<vector<int>> ans;
    void re(vector<int> now,vector<int>& candidates,int item,int remain){
        if(remain==0){
            ans.push_back(now);
            return;
        }
        for(int i=item;i<candidates.size()&&candidates[i]<=remain;i++){
            if(i==item || candidates[i]!=candidates[i-1]){
                now.push_back(candidates[i]);
                re(now,candidates,i+1,remain-candidates[i]);
                now.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> now;
        sort(candidates.begin(),candidates.end());
        re(now,candidates,0,target);
        return ans;
    }
};