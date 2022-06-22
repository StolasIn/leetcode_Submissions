// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> map;
        unordered_map<char,char>::iterator iter;
        int m=s.size();
        for(int i=0;i<m;i++){
            iter=map.find(s[i]);
            if(iter==map.end()){
                map[s[i]]=t[i];
            }
            else{
                if(map[s[i]]!=t[i]) return false;
            }
        }
        return true;
    }
};