// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        int sum;
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int m=nums.size();
        int l=0,r=m-1;
        while(r>l){
            if(nums[l]+nums[r]==t){
                ans.emplace_back(l);
                ans.emplace_back(r);
                break;
            }
            else if(nums[l]+nums[r]>t){
                r--;
            }
            else if(nums[l]+nums[r]<t){
                l++;
            }
        }
        return ans;
    }
};