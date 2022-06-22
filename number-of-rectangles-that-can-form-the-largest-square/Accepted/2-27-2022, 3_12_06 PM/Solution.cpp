// https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int cnt = 0;
        int maxLen = 0;
        for (auto it: rectangles) {
            int len = min(it[0], it[1]);
            maxLen = max(maxLen, len);
        }
        for (auto it: rectangles) {
            int len = min(it[0], it[1]);
            if (len == maxLen)
                cnt++;
        }
        return cnt;
    }
};