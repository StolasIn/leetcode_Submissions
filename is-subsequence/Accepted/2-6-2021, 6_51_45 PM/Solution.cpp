// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=t.size();
        int cnt=0;
        for(int i=0;i<m;i++){
            if(t[i]==s[cnt]){
                cnt++;
            }
        }
        if(cnt==s.size()) return true;
        else return false;
    }
};