// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); ++i)
            v.push_back({nums[i], i});
        nth_element(begin(v), begin(v) + k, end(v), greater<pair<int, int>>());
        sort(begin(v), begin(v) + k, [](const auto &a, const auto &b){ return a.second < b.second; });
        vector<int> res;
        for (int i = 0; i < k; ++i)
            res.push_back(v[i].first);
        return res;
    }
};