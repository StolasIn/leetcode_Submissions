// https://leetcode.com/problems/next-greater-element-ii

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        unordered_map<int,int> map;
        auto tmp=nums;
        sort(nums.begin(),nums.end());
        int m=nums.size();
        nums.emplace_back(-1);
        for(int i=0;i<m;i++){
            map[nums[i]]=nums[i+1];
        }
        for(int i=0;i<m;i++){
            tmp[i]=map[tmp[i]];
        }
        return tmp;
    }
};