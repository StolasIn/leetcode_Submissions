// https://leetcode.com/problems/single-number-iii

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> map;
        vector<int> ans;
        int m=nums.size();
        for(int i=0;i<m;i++){
            if(map.find(nums[i])==map.end()){
                map.insert(nums[i]);
            }
            else{
                map.erase(nums[i]);
            }
        }
        for(auto i : map){
            ans.emplace_back(i);
        }
        return ans;
    }
};