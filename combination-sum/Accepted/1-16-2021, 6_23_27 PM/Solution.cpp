// https://leetcode.com/problems/combination-sum

class Solution {
public:
    vector<vector<int>> ans;
    void re(vector<int> now,vector<int>& candidates,int item,int remain){
        if(remain==0){
            ans.push_back(now);
            return;
        }
        if(item>=candidates.size()){
            return;
        }
        for(int i=0;i*candidates[item]<=remain;i++){
            if(i!=0)
                now.push_back(candidates[item]);
            cout<<remain-i*candidates[item]<<" "<<item<<endl;
            re(now,candidates,item+1,remain-i*candidates[item]);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> now;
        //for(int i=0;i<candidates.size();i++)
            re(now,candidates,0,target);
        return ans;
    }
};