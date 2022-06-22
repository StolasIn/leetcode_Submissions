// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent

class Solution {
public:
    string concat(vector<string>& word) {
        string res = "";
        for (auto w : word) res += w;
        return res;
    }
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        return concat(word1) == concat(word2);
    }
};