// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram

class Solution {
public:
    int minSteps(string s, string t) {
        int v1[128];
        int v2[128];
        int cnt=0;
        memset(v1,0,sizeof(v1));
        memset(v2,0,sizeof(v2));
        for(int i=0;i<s.size();i++){
            v1[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            v2[t[i]]++;
        }
        for(int i='a';i<='z';i++){
            cnt+=abs(v1[i]-v2[i]);
        }
        return cnt/2;
    }
};