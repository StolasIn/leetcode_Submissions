// https://leetcode.com/problems/split-a-string-in-balanced-strings

class Solution {
public:
    int balancedStringSplit(string s) {
        int m = s.size();
        int cnt = 0;
        int ans = 0;
        for(int i=0;i<m;i++){
            if(s[i]=='L'){
                cnt++;
            }
            else{
                cnt--;
            }
            if(cnt==0){
                ans++;
            }
        }
        return ans;
    }
};