// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v1(128,0);
        vector<int> v2(128,0);
        for(int i=0;i<s.size();i++){
            v1[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            v2[t[i]]++;
        }
        for(int i='a';i<='z';i++){
            if(v1[i]!=v2[i]){
                return false;
            }
        }
        return true;
    }
};