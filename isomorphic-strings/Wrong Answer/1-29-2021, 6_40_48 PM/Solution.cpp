// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> sv(129,'\0');
        vector<char> tv(129,'\0');
        int m=s.size();
        for(int i=0;i<m;i++){
            if(sv[s[i]]!=tv[t[i]]){
                return false;
            }
            sv[s[i]]=' ';
            tv[t[i]]=' ';
        }
        return true;
    }
};