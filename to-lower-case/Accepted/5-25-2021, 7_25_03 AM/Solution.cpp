// https://leetcode.com/problems/to-lower-case

class Solution {
public:
    string toLowerCase(string s) {
        int m=s.size();
        for(int i=0;i<m;i++){
            s[i]=tolower(s[i]);
        }
        return s;
    }
};