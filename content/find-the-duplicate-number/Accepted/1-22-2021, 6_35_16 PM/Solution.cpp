// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(vis[nums[i]]==false) vis[nums[i]]=true;
            else{
                return nums[i];
            }
        }
        return 0;
    }
};