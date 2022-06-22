// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ma = -1e9;
        int now = 1;
        for(int i=0;i<nums.size();i++){
            now *= nums[i];
            ma = max(ma,now);
            if(now == 0){
                now = 1;
            }
        }
        return ma;
    }
};