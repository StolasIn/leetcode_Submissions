// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int m=nums.size();
        int ma=-1;
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                ma=max(ma,nums[i]^nums[j]);
            }
        }
        return ma;
    }
};