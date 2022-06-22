// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        deque<int> d(nums.begin(),nums.end());
        for(int i=0;i<k;i++){
            d.push_front(d.back());
            d.pop_back();
        }
        nums.assign(d.begin(),d.end());
    }
};