// https://leetcode.com/problems/sum-of-all-subset-xor-totals

class Solution {
public:
    int subsetXORSum(vector<int>& arr) {
        int n = arr.size(), res = 0;
        for (int i=0; i < n; ++i)
            res |= arr[i];
        return res * (1<< n-1);
    }
};