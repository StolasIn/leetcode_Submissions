// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size() / 4;
        for (int i = n; i < arr.size(); i += n) {
            int d = distance(lower_bound(arr.begin(), arr.end(), arr[i]), 
                             upper_bound(arr.begin(), arr.end(), arr[i]));
            if (d > n)
                return arr[i];
        }
        return -1;
    }
};