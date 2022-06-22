// https://leetcode.com/problems/permutations

class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void all(vector<int>& nums,vector<int> now,vector<bool> vis){
        if(now.size()==n){
            ans.push_back(now);
            return;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=true;
                now.emplace_back(nums[i]);
                all(nums,now,vis);
                now.pop_back();
                vis[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        /*for(int i=0;i<nums.size();i++){
            
        }*/
        vector<bool> vis(100,false);
        vector<int> now;
        all(nums,now,vis);
        return ans;
    }
};