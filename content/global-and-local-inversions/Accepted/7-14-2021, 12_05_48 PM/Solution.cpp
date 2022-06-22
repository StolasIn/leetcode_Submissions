// https://leetcode.com/problems/global-and-local-inversions

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int m=nums.size();
        for(int i=1;i<m;i++){
            if(nums[i]<nums[i-1]){
                swap(nums[i],nums[i-1]);
                i++;
            }
        }
        for(int i=0;i<m;i++){
            if(i!=nums[i]) return false;
        }
        return true;
    }
};