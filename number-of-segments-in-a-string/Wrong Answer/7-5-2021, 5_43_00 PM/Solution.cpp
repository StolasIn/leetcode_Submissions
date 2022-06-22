// https://leetcode.com/problems/number-of-segments-in-a-string

class Solution {
public:
    int countSegments(string s) {
        if(s=="") return 0;
        int m=s.size();
        int cnt=0;
        bool flag=true;
        for(int i=1;i<m;i++){
            if(i-1!=0 && s[i-1]==' ' && s[i]!=' '){
                cnt++;
            }
        }
        if(s[m-1]!=' ') cnt++;
        return cnt;
    }
};