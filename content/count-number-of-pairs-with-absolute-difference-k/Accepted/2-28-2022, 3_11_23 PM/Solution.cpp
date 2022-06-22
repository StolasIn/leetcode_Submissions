// https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int m = nums.size();
        map<int,int> map;
        int ans = 0;
        for(int i=0;i<m;i++){
            map[nums[i]]++;
        }
        for(auto i : map){
            if(map.find(i.first+k)!=map.end()){
                ans+=i.second * map[i.first+k];
            }
        }
        return ans;
    }
};