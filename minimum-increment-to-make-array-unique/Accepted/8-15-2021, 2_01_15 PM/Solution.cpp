// https://leetcode.com/problems/minimum-increment-to-make-array-unique

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int m = nums.size();
        int ans=0;
        for(int i=1;i<m;i++){
            if(nums[i]<=nums[i-1]){
                ans+=abs(nums[i]-nums[i-1])+1;
                nums[i]=nums[i-1]+1;
            }
        }
        return ans;
    }
};