// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        return arr;
    }
};