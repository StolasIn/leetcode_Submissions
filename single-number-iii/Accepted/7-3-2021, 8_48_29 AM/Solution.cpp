// https://leetcode.com/problems/single-number-iii

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,bool> map;
        vector<int> ans;
        int m=nums.size();
        for(int i=0;i<m;i++){
            if(map.find(nums[i])!=map.end()){
                map[nums[i]]=true;
            }
            else{
                map[nums[i]]=false;
            }
        }
        for(auto i : map){
            if(i.second==false){
                ans.emplace_back(i.first);
            }
        }
        return ans;
    }
};