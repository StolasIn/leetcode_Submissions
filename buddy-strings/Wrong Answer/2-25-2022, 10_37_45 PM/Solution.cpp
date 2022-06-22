// https://leetcode.com/problems/buddy-strings

class Solution {
public:
    bool buddyStrings(string s, string g) {
        if(s.size()!=g.size()){
            return false;
        }
        vector<int> m(128,0);
        int ma = 0;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            ma = max(ma,m[s[i]]);
        }
        for(int i=0;i<g.size();i++){
            m[g[i]]--;
        }
        for(int i=0;i<s.size();i++){
            if(m[s[i]]!=0){
                return false;
            }
        }
        if(ma==1 && s==g){
            return false;
        }
        return true;
    }
};