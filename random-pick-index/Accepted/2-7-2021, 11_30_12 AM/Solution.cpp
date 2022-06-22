// https://leetcode.com/problems/random-pick-index

class Solution {
    vector<int> population;
public:
    Solution(vector<int>& nums) {
        this->population.swap(nums);
    }
    
    int pick(int target) {
        int n = population.size();
        int count = 0;
        int idx = 0;
        for(int i = 0; i < n; ++i) {
            if(population[i] == target) {
                count++;
                if(rand() %count == 0) idx = i;
            }
        }
        return idx;
    }
};