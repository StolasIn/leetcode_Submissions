// https://leetcode.com/problems/robot-return-to-origin

class Solution {
public:
    bool judgeCircle(string s) {
        int a,b,c,d;
        a=b=c=d=0;
        int m=s.size();
        for(int i=0;i<m;i++){
            if(s[i]=='R') a++;
            else if(s[i]=='L') b++;
            else if(s[i]=='U') c++;
            else{
                d++;
            }
        }
        if(a==b && c==d) return true;
        return false;
    }
};