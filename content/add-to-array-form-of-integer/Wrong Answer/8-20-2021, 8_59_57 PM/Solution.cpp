// https://leetcode.com/problems/add-to-array-form-of-integer

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        int c=0;
        vector<int> ans;
        for(int i=nums.size()-1;i>=0;i--){
            nums[i]+=(k%10+c);
            k/=10;
            if(nums[i]>9){
                nums[i]-=10;
                c=1;
            }
            else{
                c=0;
            }
        }
        if(c==1){
            ans.emplace_back(1);
            for(int i=0;i<nums.size();i++){
                ans.emplace_back(nums[i]);
            }
            return ans;
        }
        else{
            return nums;
        }
    }
};