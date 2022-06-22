// https://leetcode.com/problems/word-pattern

class Solution {
public:
    bool wordPattern(string p, string s) {
        unordered_map<char,string> map;
        vector<string> str;
        string tmp="";
        int m=p.size();
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                tmp+=s[i];
            }
            else{
                str.emplace_back(tmp);
                tmp="";
            }
        }
        str.emplace_back(tmp);
        for(int i=0;i<m;i++){
            map[p[i]]=str[i];
        }
        for(int i=0;i<m;i++){
            if(map[p[i]]!=str[i]) return false;
        }
        return true;
    }
};