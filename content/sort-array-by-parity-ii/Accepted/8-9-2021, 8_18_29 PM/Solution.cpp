// https://leetcode.com/problems/sort-array-by-parity-ii

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
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
        int e=1,o=nums.size()/2;
        if((nums.size()/2)%2==1) o++;
        while(o<nums.size()){
            swap(nums[e],nums[o]);
            e+=2;
            o+=2;
        }
        return nums;
    }
};