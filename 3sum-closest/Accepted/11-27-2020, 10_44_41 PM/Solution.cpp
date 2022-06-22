// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int l,r,min=9999999,min1=9999999;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            l=i+1;
            r=nums.size()-1;
            while(l<r){
                if(abs(nums[i]+nums[l]+nums[r]-target)<min1){
                    min=nums[i]+nums[l]+nums[r];
                    min1=abs(nums[i]+nums[l]+nums[r]-target);
                }
                if(nums[i]+nums[l]+nums[r]>target){
                        r--;
                }
                else if(nums[i]+nums[l]+nums[r]<target){
                        l++;
                }
                else{
                    min=nums[i]+nums[l]+nums[r];
                    break;
                }
            }
            if(min==target) break;
        }
        return min;
    }
};