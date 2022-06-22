// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ma = nums[0];
        int mi = nums[0];
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(mi,ma);
            }
            mi = min(nums[i],mi * nums[i]);
            ma = max(nums[i],ma * nums[i]);
            ans = max(ans,ma);
        }
        return ans;
    }
};