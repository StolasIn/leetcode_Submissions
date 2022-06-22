// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int m=nums.size();
        int cnt=m;
        for(int i=0;i<m;i++){
            if(map.find(nums[i])==map.end()){
                map[nums[i]]=1;
            }
            else{
                cnt--;
            }
        }
        return cnt>=k;
    }
};