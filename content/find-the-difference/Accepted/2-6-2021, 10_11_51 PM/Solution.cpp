// https://leetcode.com/problems/find-the-difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v1(128,0);
        vector<int> v2(128,0);
        int m=s.size();
        int n=t.size();
        for(int i=0;i<m;i++){
            v1[s[i]]++;
        }
        for(int i=0;i<n;i++){
            v2[t[i]]++;
        }
        for(int i='a';i<='z';i++){
            if(v1[i]!=v2[i]) return char(i);
        }
        return '\0';
    }
};