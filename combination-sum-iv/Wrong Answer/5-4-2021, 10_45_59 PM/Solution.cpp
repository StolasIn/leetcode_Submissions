// https://leetcode.com/problems/combination-sum-iv

class Solution {
public:
    void re(set<vector<int>>& s,vector<int>& nums,vector<int>& now, int t,int idx,int remain){
        if(remain<0) return;
        if(remain==0) s.insert(now);
        if(idx>=nums.size()) return;
        now.emplace_back(nums[idx]);
        re(s,nums,now,t,idx,remain-nums[idx]);
        now.pop_back();
        for(int i=0;i<nums.size();i++){
            now.emplace_back(nums[i]);
            re(s,nums,now,t,i+1,remain-nums[i]);
            now.pop_back();
        }
    }
    int combinationSum4(vector<int>& nums, int t) {
        set<vector<int>> s;
        vector<int> now;
        for(int i=0;i<nums.size();i++) re(s,nums,now,t,i,t);
        /*for(auto i : s){
            for(auto j : i){
                cout<<j<<" ";
            }
            cout<<endl;
        }*/
        return s.size();
    }
};