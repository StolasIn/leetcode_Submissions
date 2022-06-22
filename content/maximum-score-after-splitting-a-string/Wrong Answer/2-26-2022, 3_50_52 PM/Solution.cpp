// https://leetcode.com/problems/maximum-score-after-splitting-a-string

class Solution {
public:
    int maxScore(string s) {
        int m = s.size();
        vector<int> l(m);
        vector<int> r(m);
        int ze = 0;
        int on = 0;
        int ma = -1;
        for(int i=0;i<m;i++){
            if(s[i]=='0'){
                ze++;
            }
            l[i]=ze;
        }
        for(int i=m-1;i>=0;i--){
            if(s[i]=='1'){
                on++;
            }
            r[i]=on;
        }
        for(int i=0;i<l.size();i++){
            ma = max(ma,l[i]+r[i]);
        }
        return ma;
    }
};