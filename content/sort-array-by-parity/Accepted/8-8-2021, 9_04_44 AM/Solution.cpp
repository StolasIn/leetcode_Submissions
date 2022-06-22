// https://leetcode.com/problems/sort-array-by-parity

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int m=nums.size();
        int l=0,r=m-1;
        while(r>l){
            if(nums[l]%2==0){
                l++;
            }
            else{
                swap(nums[l],nums[r]);
                r--;
            }
        }
        return nums;
    }
};