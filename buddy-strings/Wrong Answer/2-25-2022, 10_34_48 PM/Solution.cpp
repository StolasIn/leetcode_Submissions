// https://leetcode.com/problems/buddy-strings

class Solution {
public:
    bool buddyStrings(string s, string g) {
        if(s.size()!=g.size() || s==g){
            return false;
        }
        vector<int> m(128,0);
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        for(int i=0;i<g.size();i++){
            m[g[i]]--;
        }
        for(int i=0;i<s.size();i++){
            if(m[s[i]]!=0){
                return false;
            }
        }
        return true;
    }
};