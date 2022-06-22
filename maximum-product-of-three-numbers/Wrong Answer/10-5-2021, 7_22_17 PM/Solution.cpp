// https://leetcode.com/problems/maximum-product-of-three-numbers

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int pro=nums[0]*nums[1]*nums[2];
        int ma=pro;
        for(int i=0;i<nums.size()-3;i++){
            if(nums[i]!=0)pro/=nums[i];
            else pro=nums[i+1]*nums[i+2];
            pro*=nums[i+3];
            ma=max(ma,pro);
        }
        return ma;
    }
};