// https://leetcode.com/problems/robot-return-to-origin

class Solution {
public:
    bool judgeCircle(string s) {
        int a,b;
        a=b=0;
        int m=s.size();
        for(int i=0;i<m;i++){
            if(s[i]=='R') a++;
            else if(s[i]=='L') a--;
            else if(s[i]=='U') b++;
            else{
                b--;
            }
        }
        if(a==0 && b==0) return true;
        return false;
    }
};