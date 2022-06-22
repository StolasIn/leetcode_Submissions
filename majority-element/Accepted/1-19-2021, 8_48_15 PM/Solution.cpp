// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        int max1=0;
        int ans;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        for(auto i : map){
            if(i.second>max1){max1=i.second; ans=i.first;}
        }
        return ans;
    }
};