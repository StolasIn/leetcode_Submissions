// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sv(128,0);
        vector<int> tv(128,0);
        int m=s.size();
        int n=t.size();
        if(m!=n) return false;
        for(int i=0;i<m;i++){
            sv[s[i]]++;
            tv[t[i]]++;
        }
        for(int i=0;i<m;i++){
            if(sv[i]!=tv[i]) return false;
        }
        return true;
    }
};