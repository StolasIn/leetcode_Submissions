// https://leetcode.com/problems/single-number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(map.find(nums[i])!=map.end()){
                map[nums[i]]=1;
            }
            else{
                map[nums[i]]+=1;
            }
        }
        for(auto i : map){
            if(i.second==1)
                return ifirst;
        }
        return 0;
    }
};