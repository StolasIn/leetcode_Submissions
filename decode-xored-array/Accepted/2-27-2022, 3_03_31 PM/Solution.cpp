// https://leetcode.com/problems/decode-xored-array

class Solution {
public:
    vector<int> decode(vector<int>& e, int first) {
        vector<int> ans;
        ans.emplace_back(first);
        for(int i=0;i<e.size();i++){
            ans.emplace_back(ans[i]^e[i]);
        }
        return ans;
    }
};