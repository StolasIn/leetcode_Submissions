// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<bool> ans(n+1,false);
        vector<int> ans2;
        for(int i=0;i<n;i++){
            ans[nums[i]]=true;
        }
        for(int i=1;i<=n;i++){
            if(ans[i]==false) ans2.push_back(i);
        }
        return ans2;
    }
};