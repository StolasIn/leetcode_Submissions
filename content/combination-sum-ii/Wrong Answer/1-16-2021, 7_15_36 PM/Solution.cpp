// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
    vector<vector<int>> ans;
    void re(vector<int> now,vector<int>& candidates,int item,int remain){
        if(remain==0){
            ans.push_back(now);
            return;
        }
        else if(remain<0) return;
        if(item>=candidates.size()){
            return;
        }
        if(item+1<candidates.size() && candidates[item]!=candidates[item+1]){
            re(now,candidates,item+1,remain);
        }
        
        now.push_back(candidates[item]);
        re(now,candidates,item+1,remain-candidates[item]);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> now;
        vector<bool> vis(51,false);
        sort(candidates.begin(),candidates.end());
        for(int i=0;i<candidates.size();i++){
            if(!vis[candidates[i]]){
                re(now,candidates,i,target);
                vis[candidates[i]]=true;
            }
        }
        return ans;
    }
};