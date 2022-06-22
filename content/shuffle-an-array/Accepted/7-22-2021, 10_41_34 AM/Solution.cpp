// https://leetcode.com/problems/shuffle-an-array

class Solution {
public:
    vector<int> res;
    vector<int> shu;
    int m;
    Solution(vector<int>& nums) {
        res.assign(nums.begin(),nums.end());
        shu.assign(nums.begin(),nums.end());
        m=nums.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return res;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i=0;i<m;i++){
            swap(shu[rand()%m],shu[i]);
        }
        return shu;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */