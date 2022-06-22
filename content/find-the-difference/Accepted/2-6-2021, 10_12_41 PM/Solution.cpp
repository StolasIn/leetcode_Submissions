// https://leetcode.com/problems/find-the-difference

class Solution {
public:
    char findTheDifference(string s, string t) {
         char res = 0;
        
        for(auto c: t) {
            res ^= c;
        }
        
        for(auto c: s) {
            res ^= c;
        }
        
        return res;
    }
};