// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses

class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int ma = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                cnt++;
            }
            else if(s[i] == ')'){
                cnt--;
            }
            ma = max(ma,cnt);
        }
        return ma;
    }
};