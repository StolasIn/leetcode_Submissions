// https://leetcode.com/problems/repeated-substring-pattern

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string str=s+s;
        str=str.substr(1,str.size()-2);
        return str.find(s);
    }
};