// https://leetcode.com/problems/add-to-array-form-of-integer

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        vector<int> ans;
        int i=nums.size()-1;
        while(i>=0 || k!=0){
            if(i>=0) k+=nums[i];
            ans.emplace_back(k%10);
            k/=10;
            i--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};