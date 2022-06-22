// https://leetcode.com/problems/single-number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(map.find(nums[i])==map.end()){
                map[nums[i]]=1;
            }
            else{
                map.erase(nums[i]);
            }
        }
        for(auto i : map){
           return i.second;
        }
        return 0;
    }
};