// https://leetcode.com/problems/number-of-segments-in-a-string

class Solution {
public:
    int countSegments(string s) {
        int m=s.size();
        int cnt=0;
        for(int i=0;i<m;i++){
            if(s[i]==' '){
                cnt++;
            }
        }
        return cnt+1;
    }
};