// https://leetcode.com/problems/shuffle-an-array

class Solution {
public:
    vector<int> ori;
    vector<int> shu;
    Solution(vector<int>& nums) {
        ori.assign(nums.begin(),nums.end());
        shu.assign(nums.begin(),nums.end());
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return ori;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int r;
        int s=shu.size();
        for(int i=0;i<s;i++){
            r=rand()%s;
            swap(shu[i],shu[r]);
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