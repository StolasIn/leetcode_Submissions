// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int,int> map;
        unordered_map<int,int> map1;
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        for(auto i : map){
            int sum=0;
            for(auto j : map){
                if(i.first>j.first) sum+=j.second;
            }
            map1[i.first]=sum;
        }
        for(int i=0;i<ans.size();i++){
            ans[i]=map1[nums[i]];
        }
        return ans;
    }
};