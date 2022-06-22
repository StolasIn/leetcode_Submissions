// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
public:
    int findd(vector<int>& nums){
        unordered_map<int,int> map;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        for(auto i : map){
            if(i.second>=2) cnt++;
        }
        return cnt;
    }
    int findPairs(vector<int>& nums, int k) {
        if(k==0){
            return findd(nums);
        }
        unordered_set<int> s;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        for(auto i : s){
            if(s.find(i+k)!=s.end()){
                cnt++;
            }
        }
        return cnt;
    }
};