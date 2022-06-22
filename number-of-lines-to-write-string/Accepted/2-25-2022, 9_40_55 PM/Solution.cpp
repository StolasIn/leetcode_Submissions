// https://leetcode.com/problems/number-of-lines-to-write-string

class Solution {
public:
    vector<int> numberOfLines(vector<int>& w, string s) {
        int now = 0;
        int line = 0;
        for(int i=0;i<s.size();i++){
            now+=w[s[i]-'a'];
            if(now>100){
                now = w[s[i]-'a'];
                line++;
            }
        }
        return {line+1,now};
    }
};