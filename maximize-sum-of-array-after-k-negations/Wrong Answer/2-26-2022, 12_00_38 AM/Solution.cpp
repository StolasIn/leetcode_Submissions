// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0 && k>0){
                nums[i] = -nums[i];
                k--;
            }
        }
        if(k>0 && k%2==1){
            *min_element(nums.begin(),nums.end()) *= -1;
        }
        for(int i=0;i<nums.size();i++){
            ans+=nums[i];
        }
        return ans;
    }
};