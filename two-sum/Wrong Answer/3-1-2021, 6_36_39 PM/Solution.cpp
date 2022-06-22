// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        int sum;
        vector<int> ans;
        unordered_map<int,int> map;
        int m=nums.size();
        for(int i=0;i<m;i++){
            map[nums[i]]=i;
        }
        sort(nums.begin(),nums.end());
        int l=0,r=m-1;
        while(r>l){
            if(nums[l]+nums[r]==t){
                ans.emplace_back(map[nums[l]]);
                ans.emplace_back(map[nums[r]]);
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