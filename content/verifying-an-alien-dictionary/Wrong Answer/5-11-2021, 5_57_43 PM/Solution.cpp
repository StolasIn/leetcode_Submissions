// https://leetcode.com/problems/verifying-an-alien-dictionary

class Solution {
public:
    int ord[26];
    bool cmp(string& s1,string& s2){
        int m=min(s1.size(),s2.size());
        for(int i=0;i<m;i++){
            if(ord[s1[i]-'a']>ord[s2[i]-'a']) return false;
        }
        if(s1.size()>s2.size()) return false;
        return true;
    }
    bool isAlienSorted(vector<string>& words, string& s) {
        int m=s.size();
        int n=words.size();
        for(int i=0;i<m;i++){
            ord[s[i]-'a']=26-i;
        }
        for(int i=1;i<n;i++){
            if(cmp(words[i-1],words[i])) return false;
        }
        return true;
    }
};